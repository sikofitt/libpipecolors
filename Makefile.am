pkgconfig_DATA = pipecolors.pc

AM_CXXFLAGS =+ -std=c++11 -fPIC -pipe
ACLOCAL_AMFLAGS =+ -I m4
LIBTOOL_DEPS += @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

pkginclude_HEADERS = pipecolors.h
soinclude_HEADERS = pipecolors.h
soincludedir = $(prefix)/include
sodir=$(libdir)
so_PROGRAMS = libpipecolors.so
libpipecolors_so_SOURCES = libpipecolors.cpp
libpipecolors_so_LDFLAGS = \
	-shared \
	-fPIC	\
	-Wl,-soname,libpipecolors.so.0.1
