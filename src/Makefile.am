pkgconfigdir=/usr/lib/pkgconfig
pkgconfig_DATA = libpipecolors.pc pipecolors.pc

AM_LDFLAGS = $(LDFLAGS)

ACLOCAL_AMFLAGS = -I m4 -I config
LIBTOOL_DEPS = @LIBTOOL_DEPS@

lib_LTLIBRARIES = libpipecolors.la
libpipecolors_la_SOURCES = libpipecolors.cc
libpipecolors_la_CFLAGS = -fPIC -DPIC -pthread

if PC_REMOVE_INVALID
AM_CPPFLAGSINVALID = -DPC_REMOVE_INVALID
endif
if PC_DEBUG
AM_CPPFLAGSDEBUG = -DPC_DEBUG
endif
AM_CPPFLAGS = $(AM_CPPFLAGSINVALID) $(AM_CPPFLAGSDEBUG)

libpipecolors_la_LDFLAGS = -module \
	-release ${PIPECOLORS_VERSION}

include_HEADERS = pipecolors.h
noinst_HEADERS = config.h

MAINTAINERCLEANFILES = \
	aclocal.m4 \
	config.h \
	config.h.in \
	config.h.in~ \
	config.log \
	stamp-h1 \
	Makefile.in \
	pipecolors.pc

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ../config.status libtool

pipecolors.pc:
	cp libpipecolors.pc pipecolors.pc
