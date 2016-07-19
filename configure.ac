AC_INIT([CFA], [0.0.0])

AC_DEFUN([AC_DEFINE_SUBST], [
AC01_DEFINE([$1], [$2], [$3])
AC_SUBST([$1], ['$2'])
])

AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11
LT_INIT

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_HEADER([include/config.h])
AC_CONFIG_FILES(m4_esyscmd(find . -name 'Makefile.am' | sed 's:^\./::g' | sed 's/Makefile\.am$/Makefile/g' | sed ':a;N;$!ba;s/\n/ /g'))
AC_OUTPUT

