SRC = 	./src/main.c

NAME = bin

CPPFLAGS = -iquote./include/

CFLAGS = -W -Wall

OBJ = $(SRC:.c=.o)

CC ?= gcc

RM ?= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
