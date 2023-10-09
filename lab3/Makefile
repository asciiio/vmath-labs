TARGET = main

CC = gcc
CFLAGS = -Wall -Os -std=c99 -Wno-unused-result
LFLAGS = -lm

DEPDIR = deps

SOURCES = $(wildcard *.c) $(wildcard $(DEPDIR)/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	@echo Object files created: $(OBJECTS).
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LFLAGS)
	@echo Executable file created: $(TARGET).

remove:
	@for obj in $(OBJECTS); do if (test -f $$obj); then	rm $$obj; fi; done
	@echo Object files deleted: $(OBJECTS).
	@if test -f $(TARGET); then rm $(TARGET); fi
	@echo Executable file deleted: $(TARGET).
