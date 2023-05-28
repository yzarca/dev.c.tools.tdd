# makefile_test
#
CC    = gcc	#compiler
OBJS  = TDDtest.o TDDunit.o
#
BINPATH = bin
LIBPATH = lib
OBJPATH = obj
SRCPATH = src

TDDtest:	$(OBJS)
	[ -d $(BINPATH) ] || /usr/bin/mkdir $(BINPATH)
	$(CC) $(OBJPATH)/TDDtest.o $(OBJPATH)/TDDunit.o -o $(BINPATH)/TDDtest

TDDtest.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(SRCPATH)/TDDtest.c -o $(OBJPATH)/TDDtest.o
TDDunit.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(LIBPATH)/TDDunit.c -o $(OBJPATH)/TDDunit.o

clean:
	rm -f $(OBJPATH)/*.o