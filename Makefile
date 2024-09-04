
CGNSLIB ?= $(PETSC_DIR)/$(PETSC_ARCH)/lib
CGNSINCLUDE ?= $(PETSC_DIR)/$(PETSC_ARCH)/include

COPTS  = $(CFLAGS) -I$(CGNSINCLUDE)
LDLIBS = -L$(CGNSLIB) -Wl,-rpath,$(CGNSLIB) -lcgns -lmpi

CC ?= mpicc
 
all: main

main: main.c | $(CGNSLIB)
	$(CC) $(COPTS) $^ $(LDLIBS) -o $@
