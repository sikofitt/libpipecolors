#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

m4_define([pipecolors_version_major],[0])
m4_define([pipecolors_version_minor],[1])
m4_define([pipecolors_version_micro],[0])
m4_define([pipecolors_version_beta], [])

m4_define([pipecolors_version_base], [pipecolors_version_major.pipecolors_version_minor.pipecolors_version_micro])
m4_define([pipecolors_version],
	  [ifelse(pipecolors_version_beta, [], [pipecolors_version_base], [pipecolors_version_base.pipecolors_version_beta])])

AC_INIT([pipecolors], [pipecolors_version])

PKG_PROG_PKG_CONFIG

AC_SUBST(PIPECOLORS_VERSION_BASE, pipecolors_version_base)
AC_SUBST(PIPECOLORS_VERSION_BETA, pipecolors_version_beta)

AC_SUBST([PIPECOLORS_VERSION_MAJOR], [pipecolors_version_major])
AC_SUBST([PIPECOLORS_VERSION_MINOR], [pipecolors_version_minor])
AC_SUBST([PIPECOLORS_VERSION_MICRO], [pipecolors_version_micro])
AC_SUBST([PIPECOLORS_VERSION], [pipecolors_version])

PKG_INSTALLDIR
AC_CONFIG_SRCDIR([libpipecolors.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([-Wall -Werror])

AC_GNU_SOURCE
AC_CANONICAL_HOST
AC_PROG_CXX
AC_PROG_CXX_C_O
AC_PROG_CXXCPP
AM_PROG_AR
AC_PROG_LIBTOOL

LT_INIT
AC_LANG_CPLUSPLUS
AC_PREFIX_DEFAULT([/usr])
#AC_CHECK_LIB([pipecolors], [cprintf])
#PKG_CHECK_MODULES([LIBPIPECOLORS], [pipecolors])
# Checks for programs.
AM_CONDITIONAL(CXX, test "$CXX" = yes)   # let the Makefile know if we're gcc
AC_CONFIG_MACRO_DIR([m4])
AC_SUBST([LIBTOOL_DEPS])

gcc_full_vers=`g++ -dumpversion`
gcc_major_vers=`echo ${gcc_full_vers} | cut -f1 -d.`
gcc_minor_vers=`echo ${gcc_full_vers} | cut -f2 -d.`
gcc_micro_vers=`echo ${gcc_full_vers} | cut -f3 -d.`

# Checks for functions

AC_CHECK_CXX_ARGUMENT([-std=c++11], [], [AC_MSG_ERROR([C++11 support is required.])])

AC_MSG_CHECKING([if ${CXX-c++} supports nullptr])
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM(
    [],
    [[
      char *char_null = nullptr;
    ]])],
  [AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE_NULLPTR, 1,
     [Define to 1 if the compiler supports the nullptr C++11 constant])],
  [AC_MSG_RESULT(no)])

AC_MSG_CHECKING([${CXX-c++} version])
if test "${gcc_minor_vers}" -lt 9; then
  AC_MSG_ERROR([GCC >= 4.9 is required, you have version ${gcc_full_vers}])
else
  AC_MSG_RESULT([${gcc_full_vers} ... acceptable])
fi
AC_HEADER_STDC
AC_CHECK_FUNCS([vprintf vsprintf printf])

# Checks for libraries.
AC_CHECK_HEADERS([stdarg.h regex.h termcap.h])
AC_CHECK_LIB([termcap], [getenv], [termcap=yes], [termcap=no])
if test "${termcap}" = "no"; then
  AC_MSG_ERROR([requirement not found : getenv in -ltermcap])
fi
AC_CHECK_TYPE([size_t])

AC_CHECK_TYPES([std::string], [], [], [[
  #include <stdio.h>
  #include <string>
  #include <iostream>
  ]])

AC_ARG_ENABLE([the-force],
	[AC_HELP_STRING([--enable-the-force], [use the force [default=no]])],
		[], [enable_the_force=no])
AM_CONDITIONAL([ENABLE_THE_FORCE], [test "x$enable_the_force" = "xyes"])

AC_CONFIG_FILES([Makefile pipecolors.pc:pipecolors.pc.in],[],[APIVERSION=PIPECOLORS_VERSION])
AC_CONFIG_COMMANDS([default],[[]],[[]])
AC_OUTPUT
