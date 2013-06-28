#
# ZDS II Make File - smashing_bricks, Debug
#

CC = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8lib

CFLAGS =  \
 -alias -asm -bitfieldsize:32 -charsize:8 -const:ROM -debug  \
 -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY  \
 -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32  \
 -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy  \
 -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc  \
 -NOjmpopt -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy  \
 -localcse -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L  \
 -NOoptlink -optsize -peephole -NOpromote -quiet -regvar -revaa  \
 -NOsdiopt -shortsize:16  \
 -stdinc:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"  \
 -strict -usrinc:"C:\DOCUME~1\s123161\git\30010\TERMAN~1\include"  \
 -NOwatch -cpu:Z8F6403  \
 -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"

AFLAGS =  \
 -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1  \
 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj  \
 -NOigcase  \
 -include:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"  \
 -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt  \
 -warn -NOzmasm -revaa -cpu:Z8F6403

OUTDIR = C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\

Debug: smashing_bricks

deltarget: 
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\smashing_bricks.lod  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\smashing_bricks.lod

clean: 
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\smashing_bricks.lod  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\smashing_bricks.lod
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\graphics.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\graphics.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\input.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\input.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\lut.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\lut.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\math.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\math.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\sound.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\sound.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timekeeping.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timekeeping.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\striker.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\striker.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\backgrounds.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\backgrounds.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\ball.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\ball.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\brick.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\brick.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\levels.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\levels.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\main.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\main.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timerlib.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timerlib.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\joystick.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\joystick.obj
	@if exist C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\spi.obj  \
            del C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\spi.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\graphics.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\input.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\lut.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\math.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\sound.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timekeeping.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\striker.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\backgrounds.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\ball.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\brick.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\levels.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\main.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timerlib.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\joystick.obj  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\spi.obj

smashing_bricks: $(OBJS)
	 $(LINK)  @C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\smashing_bricks_Debug.linkcmd

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\zsldevinit.asm

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\graphics.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\graphics.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\graphics.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\input.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\input.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\input.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\lut.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\lut.c
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\lut.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\math.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\math.c
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\math.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\sound.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\sound.c
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\sound.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timekeeping.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\timekeeping.c
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\API\timekeeping.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\striker.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\striker.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\striker.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\backgrounds.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\backgrounds.c
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\backgrounds.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\ball.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\ball.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\ball.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\brick.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\brick.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\brick.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\levels.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\levels.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\levels.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\main.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\main.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\APPLIC~1\main.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\timerlib.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\timerlib.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\timerlib.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\joystick.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\joystick.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\joystick.c

C:\DOCUME~1\s123161\git\30010\TERMAN~1\project\spi.obj :  \
            C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\spi.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\DOCUME~1\s123161\git\30010\TERMAN~1\src\HWLIB~1\spi.c

