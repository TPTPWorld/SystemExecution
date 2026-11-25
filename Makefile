#----Set TPTP_HOME if not already imported from environment
TPTP_HOME ?= /home/tptp

CC = gcc
#---- -I/usr/include/x86_64-linux-gnu for bits/libc-header-start.h and curl/curl.h
CFLAGS = -Wall -Wformat-overflow=0 -I/usr/include/x86_64-linux-gnu -D TPTP_HOME=\"$(TPTP_HOME)\"
LFLAGS = -lcurl -lm -L/usr/lib/x86_64-linux-gnu 

#----Default to LINUX (done again in TreeLimitedRun.c)
OS ?= LINUX

clean-install: clean install

all: TreeLimitedRun

#----install does not cause a make all to recompile because the objects are still current.
install: all

TreeLimitedRun: TreeLimitedRun.o
	$(CC) -D$(OS) $(LFLAGS) -static -o $@ TreeLimitedRun.o 

TreeLimitedRun.o: TreeLimitedRun.c
	$(CC) -D$(OS) $(CFLAGS) -static -c TreeLimitedRun.c

clean:
	rm -f *.o
