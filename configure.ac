AC_PREREQ(2.61)
AC_INIT([stygmorgan],[0.30.0],[holborn@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/main.C])
AC_CONFIG_HEADER([src/config.h])
AC_ARG_ENABLE(optimizations,
AC_HELP_STRING([--enable-optimizations[=yes/no]],[enable optimizations (default=yes)]),
[ac_optimizations="$enableval"], [ac_optimizations="yes"])

if test "x$ac_optimizations" = "xyes"; 
then
OPTS=""
else
OPTS="no"
fi


AC_ARG_ENABLE(vectorize,
AC_HELP_STRING([--enable-vectorize[=yes/no]],[enable vectorize (default=yes)]),
[ac_vectorize="$enableval"], [ac_vectorize="yes"])

if test "x$ac_vectorize" = "xyes"; then
VECTOR="-ftree-vectorize -fvect-cost-model"
else
ac_vectorize="no"
fi


AC_ARG_ENABLE(sse,
AC_HELP_STRING([--enable-see],[enable sse (default=automatic check)]),
[ac_sse="$enableval"])

if test "x$ac_sse" = "xyes"; then
SSE="-msse -mfpmath=sse"
else
ac_sse="no"
fi

AC_ARG_ENABLE(sse2,
AC_HELP_STRING([--enable-see2],[enable sse2 (default=automatic check)]),
[ac_sse2="$enableval"])

if test "x$ac_sse2" = "xyes"; then
SSE="-msse2 -mfpmath=sse"
else 
ac_sse2="no"
fi

AC_ARG_ENABLE(altivec,
AC_HELP_STRING([--enable-altivec],[enable altivec (default=automatic check)]),
[ac_altivec="$enableval"])

if test "x$ac_altivec" = "xyes"; then
ALTIVEC="-maltivec"
else
ac_altivec="no"
fi

AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET

AC_CHECK_PROG([FLTKCONFIG], [fltk-config], [fltk-config])
if test -z "$FLTKCONFIG"; then
  AC_MSG_ERROR([fltk not installed!])
fi
AC_CHECK_PROG([ACONNECT],[aconnect],[aconnect])
if test -z "$ACONNECT"; then
  AC_MSG_ERROR([aconnect not installed!])
fi

AC_CHECK_PROG([Z7],[7z],[7z])
if test -z "$Z7"; then
  AC_MSG_ERROR([7z not installed!])
fi




# Checks gcc version

GCC_VERSION=`$CC -dumpversion | cut -f 2 -d "."`
if test "$GCC_VERSION" = "5"; then
ADDS="-fvar-tracking-assignments-toggle -fexcess-precision=fast"
else
ADDS=""
fi

AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

AC_PROG_GCC_TRADITIONAL
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_MALLOC
AC_FUNC_SELECT_ARGTYPES


AC_HEADER_STDC

AC_FUNC_SELECT_ARGTYPES
AC_CHECK_FUNCS([bzero memset strlen sprintf printf select strdup strstr])


# Checks for libraries.

AC_CHECK_LIB([X11], [XOpenDisplay],[ac_X11="yes"],[ac_X11="no"])
if test "x$ac_X11" = "xno"; then
AC_MSG_ERROR([Could not find XOpenDisplay in -lX11.])
else
   LIBS="$LIBS -lX11"
fi


AC_CHECK_LIB([Xft], [main], [ac_libXft="yes"], [ac_libXft="no"])
if test "x$ac_libXft" = "xno"; then
AC_MSG_ERROR([Xft library not found.])
else 
   LIBS="$LIBS -lXft"
fi

AC_CHECK_LIB([Xrender], [main], [ac_Xrender="yes"], [ac_Xrender="no"])
if test "x$ac_Xrender" = "xno"; then
AC_MSG_ERROR([Xrender library not found.])
else 
   LIBS="$LIBS -lXrender"

fi


AC_CHECK_LIB([dl], [main], [ac_dl="yes"], [ac_dl="no"])
if test "x$ac_dl" = "xno"; then
AC_MSG_ERROR([dl library not found.])
else 
   LIBS="$LIBS -ldl"

fi

AC_CHECK_LIB([fltk], [main], [ac_fltk="yes"], [ac_fltk="no"])
if test "x$ac_fltk" = "xno"; then
AC_MSG_ERROR([FLTK library not found.])
fi

AC_CHECK_LIB([Xpm],[main], [ac_Xpm="yes"], [ac_Xpm="no"])
if test "x$ac_Xpm" = "xno"; then
AC_MSG_ERROR([Xpm library not found.])
else 
   LIBS="$LIBS -lXpm"

fi

AC_CHECK_LIB([fontconfig], [main], [ac_fontconfig="yes"], [ac_fontconfig="no"])
if test "x$ac_fontconfig" = "xno"; then
AC_MSG_ERROR([fontconfig library not found.])
else 
   LIBS="$LIBS -lfontconfig"

fi

AC_CHECK_LIB([freetype], [main], [ac_freetype="yes"], [ac_freetype="no"])
if test "x$ac_freetype" = "xno"; then
AC_MSG_ERROR([freetype library not found.])
else 
   LIBS="$LIBS -lfreetype"

fi

AC_CHECK_LIB([m], [main], [ac_m="yes"], [ac_m="no"])
if test "x$ac_m" = "xno"; then
AC_MSG_ERROR([Math library not found.])
else 
   LIBS="$LIBS -lm"

fi

AC_CHECK_LIB([pthread], [main], [ac_pthread="yes"], [ac_pthread="no"] )
if test "x$ac_pthread" = "xno"; then
AC_MSG_ERROR([pthread library not found.])
else 
   LIBS="$LIBS -lpthread"
fi

AC_CHECK_LIB([rt], [main], [ac_rt="yes"], [ac_rt="no"])
if test "x$ac_rt" = "xno"; then
AC_MSG_ERROR([rt library not found.])
else 
   LIBS="$LIBS -lrt"

fi

AC_CHECK_LIB([z], [main], [ac_z="yes"], [ac_zm="no"])
if test "x$ac_z" = "xno"; then
AC_MSG_ERROR([z library not found.])
else 
   LIBS="$LIBS -lz"

fi

AC_CHECK_LIB([asound], [main], [ac_asound="yes"], [ac_asound="no"])
if test "x$ac_asound" = "xno"; then
AC_MSG_ERROR([ALSA libasound library not found.])
else 
   LIBS="$LIBS -lasound"
fi

AC_CHECK_LIB([jack],main, [ac_jack="yes"], [ac_jack="no"])
if test "x$ac_jack" = "xno"; then
AC_MSG_ERROR([JACK library not found.])
else 
   LIBS="$LIBS -ljack"

fi





AC_CHECK_HEADER(alsa/asoundlib.h, true, AC_MSG_ERROR([Alsa is required]))


if test "x$prefix" = "xNONE"; then
AC_DEFINE_UNQUOTED(PREFIX, "/usr/local", [Install prefix])
else
AC_DEFINE_UNQUOTED(PREFIX, "$prefix", [Install prefix])
fi
if test "x$prefix" = "xNONE"; then
AC_DEFINE_UNQUOTED(PREFIX, "/usr/local", [Install prefix])
else
AC_DEFINE_UNQUOTED(PREFIX, "$prefix", [Install prefix])
fi

if test "x$prefix" = "xNONE"; then
prefix=/usr/local
fi


AC_HEADER_DIRENT
AC_HEADER_STDC

AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h libintl.h stdlib.h string.h sys/ioctl.h unistd.h X11/xpm.h])

AC_ARG_ENABLE(datadir,
AC_HELP_STRING([--enable-datadir[=yes/no]],[use datadir (default=no)]),
[ac_dd="$enableval"], [ac_dd="no"])

if test "x$ac_dd" = "xyes"; then
DATADIR="$datadir"
else
DATADIR="$prefix/share/${PACKAGE}"
fi

IS64=$(uname -m | grep x86_64) 

if test -z "$IS64"; then
IS64=""
else
IS64=" -D_FILE_OFFSET_BITS=64 "
fi

AC_ARG_ENABLE(docdir,
AC_HELP_STRING([--enable-docdir[=yes/no]],[use docdir (default=no)]),
[ac_hd="$enableval"], [ac_hd="no"])

if test "x$ac_hd" = "xyes"; then
HELPDIR="$docdir"
else
HELPDIR="$prefix/share/doc/${PACKAGE}"
fi

AC_DEFINE_UNQUOTED(DATADIR,"$DATADIR",[DATADIR])
AC_DEFINE_UNQUOTED(HELPDIR,"$HELPDIR",[HELPDIR])


if test -z "$OPTS";then
if test -z "$ALTIVEC";then
if test -z "$SSE"; then
SSE=$(cat /proc/cpuinfo | grep sse2)
if test -z "$SSE"; then
SSE=""
ac_sse2="no"
else
SSE="-msse2 -mfpmath=sse"
ac_sse2="yes"
fi
if test -z "$SSE"; then
SSE=$(cat /proc/cpuinfo | grep sse)
if test -z "$SSE"; then
SSE=""
ac_sse="no"
else
SSE="-msse -mfpmath=sse"
ac_sse="yes"
fi
fi
fi
fi

if test -z "$ALTIVEC"; then
ALTIVEC=$(cat /proc/cpuinfo | grep altivec)
if test -z "$ALTIVEC"; then
ALTIVEC=""
ac_altivec="no"
else
ALTIVEC="-maltivec"
ac_altivec="yes"
fi
fi
fi


LIBS="`$FLTKCONFIG --use-images --ldflags` $LIBS"
CXXFLAGS="-O2 -Wall -pipe $ADDS $IS64 $SSE $ALTIVEC -ffast-math $VECTOR `$FLTKCONFIG --use-images --cxxflags` $CXXFLAGS"

AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADER(alsa/asoundlib.h, true, AC_MSG_ERROR([Alsa is required]))

AC_PATH_PROG(FLTK_CONFIG, fltk-config, no)
if test "$FLTK_CONFIG" = "no"; then
  AC_MSG_ERROR(fltk-config not found)
fi
AC_CHECK_PROG([ACONNECT],[aconnect],[aconnect])
if test -z "$ACONNECT"; then
  AC_MSG_ERROR([aconnect not installed!])
fi


# Checks for libraries.
AC_CHECK_LIB([Xft], [main])
AC_CHECK_LIB([Xrender], [main])
AC_CHECK_LIB([asound], [main])
AC_CHECK_LIB([dl], [main])
AC_CHECK_LIB([fltk], [main])
AC_CHECK_LIB([fontconfig], [main])
AC_CHECK_LIB([freetype], [main])
AC_CHECK_LIB([Xpm],[main])


if test "x$prefix" == "xNONE"; then
prefix=/usr/local
fi



DATADIR="$prefix/share/${PACKAGE}"
HELPDIR="$prefix/share/doc/${PACKAGE}"

AC_DEFINE_UNQUOTED(DATADIR,"$DATADIR",[DATADIR])
AC_DEFINE_UNQUOTED(HELPDIR,"$HELPDIR",[HELPDIR])
AC_DEFINE([WEBSITE],[""],[WEBSITE])


AC_OUTPUT(Makefile src/Makefile data/Makefile doc/Makefile doc/html/Makefile doc/examples/Makefile doc/DSPeffects/Makefile )

echo
echo  " $PACKAGE_NAME $PACKAGE_VERSION"
echo
echo
echo  " Optimizations__________________________________________________"
echo  " Vectorization. . . . . . . . . . . . . . . . . . . . . .: $ac_vectorize"
echo  " Use altivec. . . . . . . . . . . . . . . . . . . . . . .: $ac_altivec"
echo  " Use sse  . . . . . . . . . . . . . . . . . . . . . . . .: $ac_sse"
echo  " Use sse2 . . . . . . . . . . . . . . . . . . . . . . . .: $ac_sse2"
echo  
echo  " Library________________________________________________________"
echo  " X11 support  . . . . . . . . . . . . . . . . . . . . . .: $ac_X11"
echo  " Xpm support (libxpm) . . . . . . . . . . . . . . . . . .: $ac_Xpm"
echo  " Xft support  . . . . . . . . . . . . . . . . . . . . . .: $ac_libXft"
echo  " Xrender support  . . . . . . . . . . . . . . . . . . . .: $ac_Xrender"
echo  " Fontconfig support . . . . . . . . . . . . . . . . . . .: $ac_fontconfig"
echo  " Freetype support . . . . . . . . . . . . . . . . . . . .: $ac_freetype"
echo  " FLTK toolkit . . . . . . . . . . . . . . . . . . . . . .: $ac_fltk"
echo  " pthread support (libpthread) . . . . . . . . . . . . . .: $ac_pthread"
echo  " ALSA MIDI Sequencer support  . . . . . . . . . . . . . .: $ac_asound"
echo  " JACK Audio Connection Kit library  . . . . . . . . . . .: $ac_jack"
echo  
echo  " Now maybe you can run 'make' to build the sources."
echo
echo


