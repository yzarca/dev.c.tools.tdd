# makefile_test
#
CC    = gcc	#compiler
OBJS  = tddtest.o tddunit.o
#
BINPATH = bin
LIBPATH = lib
OBJPATH = obj

tddtest:	$(OBJS)
	[ -d $(BINPATH) ] || /usr/bin/mkdir $(BINPATH)
	$(CC) $(OBJPATH)/tddtest.o $(OBJPATH)/tddunit.o -o $(BINPATH)/tddtest

tddtest.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c tddtest.c -o $(OBJPATH)/tddtest.o
tddunit.o:
	[ -d $(OBJPATH) ] || /usr/bin/mkdir $(OBJPATH)
	$(CC) -c $(LIBPATH)/tddunit.c -o $(OBJPATH)/tddunit.o

clean:
	rm -f $(OBJPATH)/*.o