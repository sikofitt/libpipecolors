#!/bin/sh

set -x

test -f configure && autoreconf -i && exit 0 ||

test -d autom4te.cache && rm -rf autom4te.cache
test -d config && rm -rf config
mkdir config || exit 1
libtoolize --install --copy || exit 1
aclocal -I config || exit 1
autoheader || exit 1
autoconf || exit 1
automake --add-missing --copy --force || exit 1