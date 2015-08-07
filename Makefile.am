SUBDIRS = src man

ACLOCAL_AMFLAGS = -I m4 -I config

docdir = $(datadir)/doc/@PACKAGE@
doc_DATA = README NEWS AUTHORS ChangeLog COPYING

MAINTAINERCLEANFILES = \
	aclocal.m4 \
	config.log \
	stamp-h1 \
	-rf config \
	-rf m4 \
	configure \
	Makefile.in

test:
	echo 0