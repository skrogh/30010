#
# ZDS II Make File - proj, Debug
#

CC = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict -usrinc:"C:\Users\Soren\Git\30010\src\include" -NOwatch
#   -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Soren\Git\30010\project\4\proj_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Soren\Git\30010\project\4\proj_Debug.asmsw

OUTDIR = C:\Users\Soren\Git\30010\project\4\

Debug: proj

deltarget: 
	@if exist C:\Users\Soren\Git\30010\project\4\proj.lod  \
            del C:\Users\Soren\Git\30010\project\4\proj.lod

clean: 
	@if exist C:\Users\Soren\Git\30010\project\4\proj.lod  \
            del C:\Users\Soren\Git\30010\project\4\proj.lod
	@if exist C:\Users\Soren\Git\30010\project\4\zsldevinit.obj  \
            del C:\Users\Soren\Git\30010\project\4\zsldevinit.obj
	@if exist C:\Users\Soren\Git\30010\project\4\main.obj  \
            del C:\Users\Soren\Git\30010\project\4\main.obj
	@if exist C:\Users\Soren\Git\30010\project\4\ansi.obj  \
            del C:\Users\Soren\Git\30010\project\4\ansi.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Soren\Git\30010\project\4\zsldevinit.obj  \
            C:\Users\Soren\Git\30010\project\4\main.obj  \
            C:\Users\Soren\Git\30010\project\4\ansi.obj

proj: $(OBJS)
	 $(LINK)  @C:\Users\Soren\Git\30010\project\4\proj_Debug.linkcmd

C:\Users\Soren\Git\30010\project\4\zsldevinit.obj :  \
            C:\Users\Soren\Git\30010\project\4\zsldevinit.asm  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Soren\Git\30010\project\4\zsldevinit.asm

C:\Users\Soren\Git\30010\project\4\main.obj :  \
            C:\Users\Soren\Git\30010\src\exercise4\main.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\src\include\ansi.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\src\exercise4\main.c

C:\Users\Soren\Git\30010\project\4\ansi.obj :  \
            C:\Users\Soren\Git\30010\src\include\ansi.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\src\include\ansi.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\src\include\ansi.c

