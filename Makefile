CC = gcc
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = .
CFLAGS = -std=gnu18 -Wall -Wextra -Wpedantic -O3
LIBS = -lm
NAME = math

OBJS = $(addprefix $(OBJ_DIR)/, main.o parse.o eval.o)

all: pre $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

test: all
	python3 tests/tests.py

pre:
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi;

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) -DLINUX $< -o $@ $(GTK)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then rm -r -f $(OBJ_DIR); fi;

distclean: clean
	@rm -f $(NAME)