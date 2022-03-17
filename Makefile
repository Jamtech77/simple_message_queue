CURDIR = $(shell pwd)

CC := gcc
AR := ar
SIZE := size
OBJCOPY := objcopy
OBJDUMP := objdump
SIZE := size

exe := main

SRCS = \
	$(CURDIR)/main.c \
	$(CURDIR)/queue/queue.c

SRCS_NOTDIR = $(notdir $(SRCS))

OBJ_FILES_C= $(SRCS_NOTDIR:%.c=%.o)
OBJ_FILES_ALL = $(OBJ_FILES_C)

INCLUDES := \
	-I$(CURDIR)/queue

cflags += $(INCLUDES)

VPATH =\
	$(CURDIR): \
	$(CURDIR)/queue:

%.o:%.c
	@$(CC) $(cflags) -c $^ -o $@

all: $(OBJ_FILES_ALL)
	$(CC) -o $(exe) $^
	$(SIZE) $(exe)

clean:
	@echo "clean *.o $(exe)"
	@rm -rf $(exe)
	@rm -rf *.o

.PHONY: clean
