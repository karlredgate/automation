(require :sb-bsd-sockets)

(defpackage echo-server
  (:use :cl :sb-bsd-sockets))

(in-package echo-server)

; (defvar *port* 7000)
(defvar *port* 9999)

(defun make-echoer (stream id disconnector)
  (lambda (_)
    (declare (ignore _))
    (handler-case
        (let ((line (read-line stream)))
          (setf line (subseq line 0 (1- (length line))))
          (cond ((string= line "quit")
                 (funcall disconnector))
                (t
                 (format t "~a: ~a~%" id line)
                 (format stream "~a: ~a~%" id line)
                 (force-output stream))))
      (end-of-file ()
        (funcall disconnector)))))

(defun make-disconnector (socket id)
  (lambda ()
    (let ((fd (socket-file-descriptor socket)))
      (format t "~a: closing~%" id)
      (sb-impl::invalidate-descriptor fd)
      (socket-close socket))))

(defun serve (socket id)
  (let ((stream (socket-make-stream socket :output t :input t))
        (fd (socket-file-descriptor socket)))
    (sb-impl::add-fd-handler fd
                             :input
                             (make-echoer stream
                                          id
                                          (make-disconnector socket id)))))

(defun echo-server (&optional (port *port*))
  (let ((socket (make-instance 'inet-socket :type :stream :protocol :tcp))
        (counter 0))
    (setf (sb-bsd-sockets:sockopt-reuse-address socket) t)
    (format t "about to bind the socket ~D" port)
    (socket-bind socket #(127 0 0 1) port)
    (socket-listen socket 5)
    (sb-impl::add-fd-handler (socket-file-descriptor socket)
                             :input
                             (lambda (_)
                               (declare (ignore _))
                               (incf counter)
                               (format t "Accepted client ~A~%" counter)
                               (serve (socket-accept socket) counter)))))

(print "create server")
#+sb-thread
(sb-thread:make-thread (lambda ()
                         (echo-server)
                         (loop
                            (sb-impl::serve-all-events))))
#-sb-thread
(print "Starting server")
(echo-server)
