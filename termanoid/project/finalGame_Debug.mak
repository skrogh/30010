#
# ZDS II Make File - finalGame, Debug
#

CC = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:ROM -debug
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
CFLAGS = -sw:C:\Users\Soren\Git\30010\termanoid\project\finalGame_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Soren\Git\30010\termanoid\project\finalGame_Debug.asmsw

OUTDIR = C:\Users\Soren\Git\30010\termanoid\project\

Debug: finalGame

deltarget: 
	@if exist C:\Users\Soren\Git\30010\termanoid\project\finalGame.lod  \
            del C:\Users\Soren\Git\30010\termanoid\project\finalGame.lod

clean: 
	@if exist C:\Users\Soren\Git\30010\termanoid\project\finalGame.lod  \
            del C:\Users\Soren\Git\30010\termanoid\project\finalGame.lod
	@if exist C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\backgrounds.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\backgrounds.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\ball.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\ball.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\brick.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\brick.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\graphics.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\graphics.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\input.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\input.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\joystick.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\joystick.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\levels.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\levels.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\lut.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\lut.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\main.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\main.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\math.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\math.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\sound.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\sound.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\spi.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\spi.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\striker.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\striker.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\timekeeping.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\timekeeping.obj
	@if exist C:\Users\Soren\Git\30010\termanoid\project\timerlib.obj  \
            del C:\Users\Soren\Git\30010\termanoid\project\timerlib.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\backgrounds.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\ball.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\brick.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\graphics.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\input.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\joystick.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\levels.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\lut.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\main.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\math.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\sound.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\spi.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\striker.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\timekeeping.obj  \
            C:\Users\Soren\Git\30010\termanoid\project\timerlib.obj

finalGame: $(OBJS)
	 $(LINK)  @C:\Users\Soren\Git\30010\termanoid\project\finalGame_Debug.linkcmd

C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.obj :  \
            C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.asm  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Soren\Git\30010\termanoid\project\zsldevinit.asm

C:\Users\Soren\Git\30010\termanoid\project\backgrounds.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\backgrounds.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\BACKGR~1.H
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\backgrounds.c

C:\Users\Soren\Git\30010\termanoid\project\ball.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\ball.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\ball.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\math.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\sound.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\ball.c

C:\Users\Soren\Git\30010\termanoid\project\brick.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\brick.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\brick.c

C:\Users\Soren\Git\30010\termanoid\project\graphics.obj :  \
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
            C:\Users\Soren\Git\30010\TERMAN~1\include\BACKGR~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\graphics.c

C:\Users\Soren\Git\30010\termanoid\project\input.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\input.c  \
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
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\joystick.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\input.c

C:\Users\Soren\Git\30010\termanoid\project\joystick.obj :  \
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

C:\Users\Soren\Git\30010\termanoid\project\levels.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\levels.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\BACKGR~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\levels.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\levels.c

C:\Users\Soren\Git\30010\termanoid\project\lut.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\lut.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\lut.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\lut.c

C:\Users\Soren\Git\30010\termanoid\project\main.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\main.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\BACKGR~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\ball.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\brick.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\levels.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\sound.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\TIMEKE~1.H
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\main.c

C:\Users\Soren\Git\30010\termanoid\project\math.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\math.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\lut.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\math.c

C:\Users\Soren\Git\30010\termanoid\project\sound.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\sound.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\spi.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\sound.c

C:\Users\Soren\Git\30010\termanoid\project\spi.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\spi.c  \
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
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\spi.c

C:\Users\Soren\Git\30010\termanoid\project\striker.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\striker.c  \
            C:\PROGRA~2\pgm\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\graphics.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\input.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\math.h  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\striker.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\striker.c

C:\Users\Soren\Git\30010\termanoid\project\timekeeping.obj :  \
            C:\Users\Soren\Git\30010\termanoid\src\timekeeping.c  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\CONSTA~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\include\TIMEKE~1.H  \
            C:\Users\Soren\Git\30010\TERMAN~1\src\timerlib.h
	 $(CC)  $(CFLAGS) C:\Users\Soren\Git\30010\termanoid\src\timekeeping.c

C:\Users\Soren\Git\30010\termanoid\project\timerlib.obj :  \
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

