# Compiler Options
CC = gcc
WINCC = x86_64-w64-mingw32-gcc
LIBS =
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -O2 $(LIBS)
LOPS = $(LIBS)

# File Options
SRC_DIR = ./src
DEST_DIR = ./target
EXEC = $(DEST_DIR)/demo
FILES = $$(find $(src) -name '*.c')
OBJS = $(DEST_DIR)/draw.o $(DEST_DIR)/main.o $(DEST_DIR)/rand.o $(DEST_DIR)/sched.o

# Recipes
.PHONY: all build build-win run clean

all: build build_win

$(DEST_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "\x1b[33m ! \x1b[00m%s\n" "Compiling object files!"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build $(EXEC): $(OBJS)
	@printf "\x1b[33m ! \x1b[00m%s\n" "Linking object for Unix-like"
	$(CC) $(LOPS) -o $(EXEC) $(OBJS)

build_win $(EXEC).exe: $(OBJS)
	@printf "\x1b[33m ! \x1b[00m%s\n" "Linking object for Windows"
	$(WINCC) $(CFLAGS) -o $(EXEC).exe $(FILES)

run: $(EXEC)
	@$(EXEC)

clean:
	@printf "\x1b[31m ! \x1b[00m%s\n" "Cleaning directory"
	rm -rf $(DEST_DIR)

