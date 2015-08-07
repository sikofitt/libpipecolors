#!/bin/sh

set -x

test -f configure && autoreconf -i && exit 0 ||

test -d autom4te.cache && rm -rf autom4te.cache
test -d config && rm -rf config
mkdir config
libtoolize --install --copy
aclocal -I config
autoheader
autoconf 
automake --add-missing --copy --force