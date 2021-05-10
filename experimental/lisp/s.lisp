#!/opt/local/bin/sbcl --script

(require :sb-bsd-sockets)
(defpackage ke (:use :cl :sb-bsd-sockets))

(in-package ke)
(defvar *my-port* 7000)

(let ( (socket (make-instance 'inet-socket :type :stream :protocol :tcp))
      )
  (socket-bind socket #(127 0 0 1) *my-port*)
)

; vim: set autoindent expandtab sw=4
