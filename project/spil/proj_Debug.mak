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
#   -strict -usrinc:"C:\Users\Soren\Git\30010\termanoid\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Soren\Git\30010\project\spil\proj_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Soren\Git\30010\project\spil\proj_Debug.asmsw

OUTDIR = C:\Users\Soren\Git\30010\project\spil\

Debug: proj

deltarget: 
	@if exist C:\Users\Soren\Git\30010\project\spil\proj.lod  \
            del C:\Users\Soren\Git\30010\project\spil\proj.lod

clean: 
	@if exist C:\Users\Soren\Git\30010\project\spil\proj.lod  \
            del C:\Users\Soren\Git\30010\project\spil\proj.lod
	@if exist C:\Users\Soren\Git\30010\project\spil\zsldevinit.obj  \
            del C:\Users\Soren\Git\30010\project\spil\zsldevinit.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\ball.obj  \
            del C:\Users\Soren\Git\30010\project\spil\ball.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\graphics.obj  \
            del C:\Users\Soren\Git\30010\project\spil\graphics.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\input.obj  \
            del C:\Users\Soren\Git\30010\project\spil\input.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\joystick.obj  \
            del C:\Users\Soren\Git\30010\project\spil\joystick.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\lut.obj  \
            del C:\Users\Soren\Git\30010\project\spil\lut.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\main.obj  \
            del C:\Users\Soren\Git\30010\project\spil\main.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\math.obj  \
            del C:\Users\Soren\Git\30010\project\spil\math.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\striker.obj  \
            del C:\Users\Soren\Git\30010\project\spil\striker.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\timekeeping.obj  \
            del C:\Users\Soren\Git\30010\project\spil\timekeeping.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\timerlib.obj  \
            del C:\Users\Soren\Git\30010\project\spil\timerlib.obj
	@if exist C:\Users\Soren\Git\30010\project\spil\brick.obj  \
            del C:\Users\Soren\Git\30010\project\spil\brick.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Soren\Git\30010\project\spil\zsldevinit.obj  \
            C:\Users\Soren\Git\30010\project\spil\ball.obj  \
            C:\Users\Soren\Git\30010\project\spil\graphics.obj  \
            C:\Users\Soren\Git\30010\project\spil\input.obj  \
            C:\Users\Soren\Git\30010\project\spil\joystick.obj  \
            C:\Users\Soren\Git\30010\project\spil\lut.obj  \
            C:\Users\Soren\Git\30010\project\spil\main.obj  \
            C:\Users\Soren\Git\30010\project\spil\math.obj  \
            C:\Users\Soren\Git\30010\project\spil\striker.obj  \
            C:\Users\Soren\Git\30010\project\spil\timekeeping.obj  \
            C:\Users\Soren\Git\30010\project\spil\timerlib.obj  \
            C:\Users\Soren\Git\30010\project\spil\brick.obj

proj: $(OBJS)
	 $(LINK)  @C:\Users\Soren\Git\30010\project\spil\proj_Debug.linkcmd

C:\Users\Soren\Git\30010\project\spil\zsldevinit.obj :  \
            C:\Users\Soren\Git\30010\project\spil\zsldevinit.asm  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Soren\Git\30010\project\spil\zsldevinit.asm

C:\Users\Soren\Git\30010\project\spil\ball.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\ball.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\ball.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\math.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\ball.c

C:\Users\Soren\Git\30010\project\spil\graphics.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\graphics.c  \
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
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\graphics.c

C:\Users\Soren\Git\30010\project\spil\input.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\input.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\joystick.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\input.c

C:\Users\Soren\Git\30010\project\spil\joystick.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\joystick.c  \
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
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\joystick.c

C:\Users\Soren\Git\30010\project\spil\lut.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\lut.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\lut.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\lut.c

C:\Users\Soren\Git\30010\project\spil\main.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\main.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\ball.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\TIMEKE~1.H
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\main.c

C:\Users\Soren\Git\30010\project\spil\math.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\math.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\lut.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\math.c

C:\Users\Soren\Git\30010\project\spil\striker.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\striker.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\math.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\striker.c

C:\Users\Soren\Git\30010\project\spil\timekeeping.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\timekeeping.c  \
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
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\TIMEKE~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\src\timerlib.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\timekeeping.c

C:\Users\Soren\Git\30010\project\spil\timerlib.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\timerlib.c  \
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
            C:\Users\Soren\Git\30010\TERMAN~1\src\timerlib.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\timerlib.c

C:\Users\Soren\Git\30010\project\spil\brick.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\brick.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\brick.c

