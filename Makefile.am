pkgconfig_DATA = libpipecolors.pc

AM_LDFLAGS = $(LDFLAGS)

ACLOCAL_AMFLAGS = -I m4 -I config
LIBTOOL_DEPS = @LIBTOOL_DEPS@

lib_LTLIBRARIES = libpipecolors.la
libpipecolors_la_SOURCES = libpipecolors.cpp
libpipecolors_la_LIBS = -lboost_regex
libpipecolors_la_CFLAGS = -fPIC -DPIC -pthread

if PC_REMOVE_INVALID
AM_CPPFLAGSINVALID = -DPC_REMOVE_INVALID
endif

if BUILD_WITH_BTREE
AM_CPPFLAGSBTREE = -DBUILD_WITH_BTREE -std=c++11
endif

AM_CPPFLAGS = $(AM_CPPFLAGSBTREE) $(AM_CPPFLAGSINVALID)

libpipecolors_la_LDFLAGS = -module \
	-release ${PIPECOLORS_VERSION}

include_HEADERS = pipecolors.h
noinst_HEADERS = config.h

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
	Makefile.in \
	-rf cpp-btree

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

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool
