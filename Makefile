SRC = 	./src/main.c

NAME = bin

CPPFLAGS = -iquote./include/

CFLAGS = -W -Wall

OBJ = $(SRC:.c=.o)

CC ?= gcc

RM ?= rm -f

all: $(NAME)

UT_SRC	=	tests/test_reg.c
UT_NAME	=	unit_tests
UT_FLAGS=	--coverage -lcriterion
tests_run:
	$(CC) -o $(UT_NAME) $(UT_SRC) $(UT_FLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(UT_NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(UT_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
