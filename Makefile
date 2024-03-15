CC       := gcc
ALL_SUBDIRS := $(sort $(dir $(wildcard */*)))
INCLUDE_PATHS := $(foreach dir,$(ALL_SUBDIRS),-I$(dir))

CFLAGS := -Wall -g $(INCLUDE_PATHS)

BIN     := bin
SRC     := .

EXECUTABLE  := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(wildcard *.c) $(wildcard */*.c)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@

out: $(wildcard *.c) $(wildcard */*.c)
	$(CC) $(CFLAGS) $^ -o $(BIN)\\$(EXECUTABLE).out

clean:
	-rm $(BIN)/*