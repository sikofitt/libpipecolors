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
AC_CANONICAL_TARGET
AC_CANONICAL_HOST
AC_CANONICAL_BUILD
PKG_PROG_PKG_CONFIG
AM_INIT_AUTOMAKE([gnu dist-bzip2 dist-zip std-options])

AM_SILENT_RULES
AC_GNU_SOURCE
AC_PROG_INSTALL
AC_PROG_CXXCPP
AM_PROG_AR
AC_PROG_LIBTOOL
AC_PROG_LN_S

LT_INIT
AC_LANG_CPLUSPLUS
AC_PREFIX_DEFAULT([/usr])

# Checks for programs.

AC_CONFIG_MACRO_DIR([m4])
AC_SUBST([LIBTOOL_DEPS])

gcc_full_vers=`g++ -dumpversion`
gcc_major_vers=`echo ${gcc_full_vers} | cut -f1 -d.`
gcc_minor_vers=`echo ${gcc_full_vers} | cut -f2 -d.`
gcc_micro_vers=`echo ${gcc_full_vers} | cut -f3 -d.`


AC_MSG_CHECKING([${CXX-c++} version])
if test "${gcc_minor_vers}" -lt 9; then
  AC_MSG_ERROR([GCC >= 4.9 is required, you have version ${gcc_full_vers}])
else
  AC_MSG_RESULT([${gcc_full_vers} ... acceptable])
fi
AC_CHECK_FUNCS([vasprintf], [], [AC_MSG_ERROR([Why don't you have this?  Install basic c++ header files.])])
AC_CHECK_HEADERS([stdarg.h stdlib.h unistd.h string iostream map],[],[AC_MSG_ERROR([We couldn't find one or more of the required headers.])])
AC_CHECK_HEADER([boost/regex.hpp],[],[AC_MSG_ERROR([Please install the libboost-regex header library.])])
AC_CHECK_LIB([boost_regex], [main], [], [AC_MSG_ERROR([Please install the libboost-regex libs on your system.])])


AC_CHECK_TYPES([std::string], [], [], [[
  #include <iostream>
	#include <string>
  ]])

AC_ARG_ENABLE([pipe-stripping],
  [AC_HELP_STRING([--disable-pipe-stripping], [strip invalid pipe codes [default=no]])],
    [], [disable_pipe_stripping=no])
  AM_CONDITIONAL([PC_REMOVE_INVALID], [test "x$disable_pipe_stripping" = "xno"])
AM_COND_IF([PC_REMOVE_INVALID],
  [AC_MSG_NOTICE([Invalid pipe codes will be filtered.
  e.g. (|41Hello will show as Hello World instead of |41Hello World)])],
  [AC_MSG_NOTICE([Invalid pipe codes will not be filtered.
  e.g. (|41Hello will show |41Hello World instead of Hello World)])])
AC_ARG_ENABLE([the-force],
	[AC_HELP_STRING([--enable-the-force], [use the force [default=no]])],
		[], [enable_the_force=no])
AM_CONDITIONAL([ENABLE_THE_FORCE], [test "x$enable_the_force" = "xyes"])


AC_CONFIG_FILES([Makefile libpipecolors.pc:libpipecolors.pc.in libpipecolors.h:libpipecolors.h.in],[],[APIVERSION=PIPECOLORS_VERSION])
AC_CONFIG_COMMANDS([timestamp], [date >timestamp])
AC_OUTPUT

resetc=$(tput sgr0);
green=$(tput bold; tput setaf 2)
blue=$(tput bold; tput setaf 4)
cyan=$(tput bold; tput setaf 6)
white=$(tput bold; tput setaf 7)


if test "x$disable_pipe_stripping" == "xno" ; then

cat << EOF

 ${reset}
 ${green}* ${white}Prefix ${resetc}: ${cyan}${prefix}
 ${green}* ${white}Exec Prefix ${resetc}: ${cyan}${exec_prefix}
 ${green}* ${white}Library ${resetc}: ${cyan}${libdir}
 ${green}* ${white}Include ${resetc}: ${cyan}${includedir}
 ${green}* ${resetc}Configure finished type '${cyan}make${resetc}' to build and '${cyan}make install${resetc}' to install.
 ${green}* ${resetc}Invalid pipe codes will be filtered
 ${green}* ${resetc}  e.g. ('${white}|41${resetc}Hello World' will show as 'Hello World' instead of '${white}|41${resetc}Hello World')
 ${green}* ${resetc}  You can change this behavior by using the ${white}--disable-pipe-stripping ${resetc}configure flag.

EOF

else

cat << EOF

 ${reset}
 ${green}* ${white}Prefix ${resetc}: ${cyan}${prefix}
 ${green}* ${white}Exec Prefix ${resetc}: ${cyan}${exec_prefix}
 ${green}* ${white}Library ${resetc}: ${cyan}${libdir}
 ${green}* ${white}Include ${resetc}: ${cyan}${includedir}
 ${green}* ${resetc}Configure finished type '${cyan}make${resetc}' to build and '${cyan}make install${resetc}' to install.
 ${green}* ${resetc}Invalid pipe codes will not be filtered.
 ${green}* ${resetc}  e.g. ('${white}|41${resetc}Hello World' will show as '${white}|41${resetc}Hello World' instead of 'Hello World')
 ${green}* ${resetc}  You can change this behavior by removing the ${white}--disable-pipe-stripping ${resetc}configure flag.

EOF

fi
