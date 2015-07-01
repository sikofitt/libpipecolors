pkgconfig_DATA = pipecolors.pc
VERSION = 0.1.0
AM_CXXFLAGS =  -std=c++11
ACLOCAL_AMFLAGS = -I m4 -I config
LIBTOOL_DEPS = @LIBTOOL_DEPS@

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

lib_LTLIBRARIES = libpipecolors.la
libpipecolors_la_SOURCES = libpipecolors.cpp
libpipecolors_la_LIBADD = -ltermcap
libpipecolors_la_CFLAGS = -fPIC -DPIC -pthread
libpipecolors_la_LDFLAGS = -module \
	-release ${PIPECOLORS_VERSION}

include_HEADERS = pipecolors.h
