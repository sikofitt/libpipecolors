man-hook:
	gzip $(mandir)/man7/libpipecolors.7
	gzip $(mandir)/man3/pcprintf.3


pkgconfig_DATA = libpipecolors.pc
AM_CXXFLAGS =  -std=c++11
ACLOCAL_AMFLAGS = -I m4 -I config
LIBTOOL_DEPS = @LIBTOOL_DEPS@

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

lib_LTLIBRARIES = libpipecolors.la
libpipecolors_la_SOURCES = libpipecolors.cpp
#libpipecolors_la_LIBADD = -ltermcap
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
