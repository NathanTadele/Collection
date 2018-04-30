# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
LDLIBS = -lm
PROG = collection
SRC = $(PROG).c album.c array.c saveAlbums.c
HDR = album.h array.h saveAlbums.h
OBJ = $(SRC:.c=.o)

# Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
