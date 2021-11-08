CC = gcc
SRC_DIR = .
INC_DIR = .
CFLAGS = -std=gnu11 -Wall -Wextra -Wpedantic -Wno-unused-parameter -O2
LIBS = -lm
NAME = math

OBJS = main.o parse.o eval.o

all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@ $(GTK)

clean:
	@rm -f $(NAME) $(OBJS)