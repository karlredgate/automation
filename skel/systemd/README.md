
 * <https://docs.varnish-software.com/tutorials/configuring-systemd-services/>
 * <https://freedesktop.org/wiki/Software/systemd/#manualsanddocumentationforusersandadministrators>
 * <https://linuxconfig.org/how-to-create-systemd-service-unit-in-linux>

```
# systemctl --user enable [my_service].service
# systemctl --user start [my_service].service
# systemctl --user status [my_service].service
```

Next create a systemd service unit file named `test.service`.
Please note you want this to be in `/etc/systemd/system/` and NOT in
`/usr/lib/systemd/` or it could be written over on the next update.

```
systemctl daemon-reload
systemctl enable test.service
sudo systemctl status varnish
sudo systemctl enable varnish
sudo systemctl enable varnish --now
sudo systemctl edit --full varnish.service
```

The override directory is (for Debian, Ubuntu and CentOS/RHEL)
located at `/etc/systemd/system`.
In order to configure only a limited change to the package-supplied
unit-file, create the directory
`/etc/systemd/system/varnish.service.d`,
and then create a file
`/etc/systemd/system/varnish.service.d/override.conf`
with the required changes (see previous section for an example).

 * A systemd unit is any system resource systemd can manage, including,
   but not limited to service, socket, device and target.
 * A unit file is a configuration file that encodes information about
   the unit required for systemd to manage that resource.
 * A systemd target is the concept systemd introduces to handle boot
   ordering and event synchronisation. Where SysV used runlevels, systemd
   has the more flexible targets that roughly describe various states and
   events. systemd provides a number of predefined such targets that are
   useful when working with service type units.
 * service in systemd is a unit that takes care of running and maintaining
   a process or a group of processes. A service unit file is a highly
   standardised and structured configuration file in contrast to SysV
   initscripts that are (shell-)scripts with some standard headers bolted
   on top. In addition to starting and stopping services, systemd can also
   be asked to take action if a service fails.

sudo systemd-delta
[EXTENDED]   /lib/systemd/system/varnish.service → /etc/systemd/system/varnish.service.d/override.conf
[OVERRIDDEN] /etc/systemd/system/hitch.service → /lib/systemd/system/hitch.service

--- /lib/systemd/system/hitch.service   2017-06-06 15:27:52.000000000 +0200
+++ /etc/systemd/system/hitch.service   2018-03-19 13:31:52.407432199 +0100
@@ -16,3 +16,4 @@

 [Install]
 WantedBy=multi-user.target
+#Small change
