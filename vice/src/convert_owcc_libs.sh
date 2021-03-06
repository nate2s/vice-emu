#!/bin/sh

# this file converts openwatcom *.lib files to lib*.a files
# imho this is a bug in the owcc program, it should be able
# to handle *.lib files when -l* is given, when this is
# corrected in owcc this script can be removed.

for i in $*
do
    case $i in
        -lm) # special case, libm functions are in libc, so using any lib will do.
            cp $WATCOM/lib386/nt/version.lib ./libm.a        
            ;;
        -lkernel32)
            cp $WATCOM/lib386/nt/kernel32.lib ./libkernel32.a
            ;;
        -luser32)
            cp $WATCOM/lib386/nt/user32.lib ./libuser32.a
            ;;
        -lgdi32)
            cp $WATCOM/lib386/nt/gdi32.lib ./libgdi32.a
            ;;
        -lwinmm)
            cp $WATCOM/lib386/nt/winmm.lib ./libwinmm.a
            ;;
        -lcomdlg32)
            cp $WATCOM/lib386/nt/comdlg32.lib ./libcomdlg32.a
            ;;
        -lcomctl32)
            cp $WATCOM/lib386/nt/comctl32.lib ./libcomctl32.a
            ;;
        -lddraw)
            cp $WATCOM/lib386/nt/ddraw.lib ./libddraw.a
            ;;
        -ldsound)
            cp $WATCOM/lib386/nt/directx/dsound.lib ./libdsound.a
            ;;
        -lth32)
            cp $WATCOM/lib386/nt/th32.lib ./libth32.a
            ;;
        -lwsock32)
            cp $WATCOM/lib386/nt/wsock32.lib ./libwsock32.a
            ;;
        -lversion)
            cp $WATCOM/lib386/nt/version.lib ./libversion.a
            ;;
    esac
done

echo >owcc_libs_converted.h "/* dummy header */"
