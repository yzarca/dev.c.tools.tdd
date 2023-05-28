# makefile_test
#
CC    = gcc	#compiler
OBJS  = TEST.TDDunit.o TDDunit.o
#
BINPATH = bin
LIBPATH = lib
OBJPATH = obj
SRCPATH = src

TEST.TDDunit:	$(OBJS)
	[ -d $(BINPATH) ] || /usr/bin/mkdir $(BINPATH)
	$(CC) $(OBJPATH)/TEST.TDDunit.o $(OBJPATH)/TDDunit.o -o $(BINPATH)/TEST.TDDunit

TEST.TDDunit.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(SRCPATH)/TEST.TDDunit.c -o $(OBJPATH)/TEST.TDDunit.o
TDDunit.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(LIBPATH)/TDDunit.c -o $(OBJPATH)/TDDunit.o

clean:
	rm -f $(OBJPATH)/*.o