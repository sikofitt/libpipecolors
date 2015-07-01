AC_DEFUN([AC_CHECK_CXX_ARGUMENT], [
  AC_MSG_CHECKING([if ${CXX-g++} supports argument $1])
  OLD_CXX_FLAGS=$CXXFLAGS
  CXXFLAGS="$1 $CXXFLAGS"
  AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM([], [])],
    [AC_MSG_RESULT(yes)
     if test "x$EXTRA_CXXFLAGS" = x; then
       EXTRA_CXXFLAGS="$1"
       AC_SUBST([EXTRA_CXXFLAGS])
     else
       EXTRA_CXXFLAGS="$1 $EXTRA_CXXFLAGS"
     fi
     ifelse([$2], , :, [$2])],
    [AC_MSG_RESULT([no])
     ifelse([$3], , :, [$3])])
  CXXFLAGS=$OLD_CXX_FLAGS])
