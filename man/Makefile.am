
man_MANS = libpipecolors.7 pcprintf.3


MAINTAINERCLEANFILES = \
	Makefile.in

install-man: install-man3 install-man7 install-man-gzip
uninstall-man: uninstall-man3 uninstall-man7 uninstall-man-gzip

install-man-gzip:
	test -f $(mandir)/man3/pcprintf.3 && gzip -qf /usr/share/man/man3/pcprintf.3
	test -f $(mandir)/man7/libpipecolors.7 && gzip -qf /usr/share/man/man7/libpipecolors.7
	test -f $(mandir)/man3/pcprintf.3.gz && ln -sf /usr/share/man/man3/pcprintf.3.gz /usr/share/man/man3/pcsprintf.3.gz

uninstall-man-gzip:
	test -f $(mandir)/man3/pcprintf.3.gz && rm -f /usr/share/man/man3/pcprintf.3.gz
	test -h $(mandir)/man3/pcsprintf.3.gz && rm -f /usr/share/man/man3/pcsprintf.3.gz
	test -f $(mandir)/man7/libpipecolors.7.gz && rm -f /usr/share/man/man7/libpipecolors.7.gz
