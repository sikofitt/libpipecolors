pkgconfig_DATA = libpipecolors.pc

ACLOCAL_AMFLAGS = -I m4 -I config
LIBTOOL_DEPS = @LIBTOOL_DEPS@

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

lib_LTLIBRARIES = libpipecolors.la
libpipecolors_la_SOURCES = libpipecolors.cpp
libpipecolors_la_LIBS = -lboost_regex
libpipecolors_la_CFLAGS = -fPIC -DPIC -pthread
libpipecolors_la_LDFLAGS = -module \
	-release ${PIPECOLORS_VERSION}

include_HEADERS = pipecolors.h

man_MANS = libpipecolors.7 pcprintf.3

docdir = $(datadir)/doc/@PACKAGE@
doc_DATA = README NEWS AUTHORS ChangeLog COPYING

MAINTAINERCLEANFILES = \
	aclocal.m4 \
	config.h \
	config.h.in \
	config.h.in~ \
	config.log \
	stamp-h1 \
	-rf config \
	-rf m4 \
	configure \
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
