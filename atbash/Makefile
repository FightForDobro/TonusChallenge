NAME = atbash

SRC = main library utils

INC = library

SRCS = $(addsuffix .c, $(SRC))

INCS = $(addsuffix .h, $(INC))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INCS)) .
	clang $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCS)

uninstall:
	rm -rf $(INC).a
	clean

clean:
	rm -rf obj $(INCS) $(SRCS) $(SRCS:.c=.o)

reinstall:
	uninstall all
