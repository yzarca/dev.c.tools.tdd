# makefile_test
#
CC    = gcc
OBJS  = TesT.o TDDunit.o
#
BINPATH = bin
LIBPATH = lib
OBJPATH = obj
SRCPATH = src

TesT:	$(OBJS)
	[ -d $(BINPATH) ] || /usr/bin/mkdir $(BINPATH)
	$(CC) $(OBJPATH)/TesT.o $(OBJPATH)/TDDunit.o -o $(BINPATH)/Run.TesT.a

TesT.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(SRCPATH)/TesT.c -o $(OBJPATH)/TesT.o
TDDunit.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(LIBPATH)/TDDunit.c -o $(OBJPATH)/TDDunit.o

clean:
	rm -f $(OBJPATH)/*.o