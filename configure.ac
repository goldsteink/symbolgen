dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(SymbolGen, 1.0)
AC_CONFIG_MACRO_DIR([m4])


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()
${CXXFLAGS=""}

AC_PROG_CXX
AX_CXX_COMPILE_STDCXX(11, noext, mandatory)


PKG_CHECK_MODULES([LIBCONFIGXX], [libconfig++ >= 1.4],,
	AC_MSG_ERROR([libconfig++ 1.4 or newer not found.]))
	

PKG_CHECK_MODULES([SPDLOG], [spdlog >= 1.0.0],,
	AC_MSG_ERROR([spdlog 1.0.0 or newer not gound.]))
	

AC_ARG_ENABLE([debug],
[  --disable-debug    Turn off debugging],
[case "${enableval}" in
  yes) debug=true ;;
  no)  debug=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],[debug=true])
AM_CONDITIONAL([DEBUG], [test x$debug = xtrue])

AC_CONFIG_FILES(Makefile)
AC_OUTPUT
