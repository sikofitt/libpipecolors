#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

m4_define([pipecolors_version_major],[1])
m4_define([pipecolors_version_minor],[2])
m4_define([pipecolors_version_patch],[0])

m4_define([pipecolors_version], [pipecolors_version_major.pipecolors_version_minor.pipecolors_version_patch])

AC_INIT([pipecolors], [pipecolors_version])

AC_SUBST([PIPECOLORS_VERSION_MAJOR], [pipecolors_version_major])
AC_SUBST([PIPECOLORS_VERSION_MINOR], [pipecolors_version_minor])
AC_SUBST([PIPECOLORS_VERSION_PATCH], [pipecolors_version_patch])
AC_SUBST([PIPECOLORS_VERSION], [pipecolors_version])

PKG_INSTALLDIR
AC_CONFIG_SRCDIR([src/libpipecolors.cc])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([config])
AC_CANONICAL_TARGET
AC_CANONICAL_HOST
AC_CANONICAL_BUILD
PKG_PROG_PKG_CONFIG

AM_INIT_AUTOMAKE([dist-bzip2 dist-zip])

#AC_GNU_SOURCE

# Checks for programs.
AC_PROG_INSTALL
AC_PROG_CXX
AM_PROG_AR
AC_PROG_LIBTOOL
AC_PROG_LN_S

LT_INIT
AC_LANG_CPLUSPLUS
AC_PREFIX_DEFAULT([/usr])

AC_CONFIG_MACRO_DIR([m4])
AC_SUBST([LIBTOOL_DEPS])

# Check for functions
AC_CHECK_FUNCS([vasprintf], [], [AC_MSG_ERROR([Why don't you have this?  Install basic c++ header files.])])

# Check for Headers
AC_CHECK_HEADERS([cstdio iostream cstring cstdlib cstdarg unistd.h],[],[AC_MSG_ERROR([We couldn't find one or more of the required headers.])])


AC_CHECK_TYPES([std::string], [], [], [[
  #include <iostream>
	#include <string>
  ]])

AC_ARG_ENABLE([pipe-stripping],
  [AC_HELP_STRING([--disable-pipe-stripping], [strip invalid pipe codes [default=no]])],
    [], [disable_pipe_stripping=no])
  AM_CONDITIONAL([PC_REMOVE_INVALID], [test "x$disable_pipe_stripping" = "xno"])

AM_COND_IF([PC_REMOVE_INVALID],
  [AC_MSG_NOTICE([Invalid pipe codes will be filtered.])],
  [AC_MSG_NOTICE([Invalid pipe codes will not be filtered.])])

AC_ARG_ENABLE([debug],
  [AC_HELP_STRING([--enable-debug], [enable debuging [default=no]])],
    [enable_debug=no], [enable_debug=yes])
  AM_CONDITIONAL([PC_DEBUG], [test "x$enable_debug" = "xno"])

AM_COND_IF([PC_DEBUG],
  [AC_MSG_NOTICE([Debugging enabled.])],
  [])

AC_CONFIG_FILES([Makefile src/Makefile man/Makefile src/libpipecolors.pc:src/libpipecolors.pc.in src/libpipecolors.h:src/libpipecolors.h.in],[],[APIVERSION=PIPECOLORS_VERSION])
AC_CONFIG_COMMANDS([timestamp], [date >timestamp])
AC_OUTPUT

resetc=$(tput sgr0);
green=$(tput bold; tput setaf 2)
blue=$(tput bold; tput setaf 4)
cyan=$(tput bold; tput setaf 6)
white=$(tput bold; tput setaf 7)
under=$(tput smul)
underoff=$(tput rmul)

cat << EOF

 ${resetc}
 ${green}* ${white}Prefix ${resetc}: ${cyan}${prefix}
 ${green}* ${white}Exec Prefix ${resetc}: ${cyan}${exec_prefix}
 ${green}* ${white}Library ${resetc}: ${cyan}${libdir}
 ${green}* ${white}Include ${resetc}: ${cyan}${includedir}
 ${green}* ${resetc}Configure finished type '${cyan}make${resetc}' to build and '${cyan}make install${resetc}' to install.
EOF
if test "x$disable_pipe_stripping" == "xno" ; then
cat << EOF
 ${green}* ${resetc}Invalid pipe codes ${white}${under}will${resetc}${underoff} be filtered.
EOF
else
cat << EOF
 ${green}* ${resetc}Invalid pipe codes ${white}${under}will not${resetc}${underoff} be filtered.
EOF
fi
cat << EOF
 ${green}* ${resetc}  e.g. ('${white}|41${resetc}Hello World' will show as 'Hello World' instead of '${white}|41${resetc}Hello World')
 ${green}* ${resetc}  You can change this behavior by using the ${white}--disable-pipe-stripping ${resetc}configure flag.

EOF

