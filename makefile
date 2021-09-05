IDIR = include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
SDIR=src

_DEPS = matrix_functions.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o matrix_functions.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

matrix_rotate_driver: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	@rm -f $(ODIR)/*.o && rm matrix_rotate_driver