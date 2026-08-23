##
## EPITECH PROJECT, 2026
## 110borwein
## File description:
## makefile
##

CC	=	epiclang

MAIN	=	src/main.c \

SRC_FILES	=	src/error_cases.c \
			src/function.c \
			src/parsing.c \

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_SRC_FILES	=	$(SRC_FILES:.c=.o)

NAME	=	110borwein

all:	$(NAME)

$(NAME):	$(OBJ_MAIN) $(OBJ_SRC_FILES)
	$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ_SRC_FILES) -lm

clean:
	find . -type f \( \
		-name "*.o" -o \
		-name "*~" -o \
		-name "a.out" -o \
		-name "#*#" -o \
		-name "vgcore.*" -o \
		-name "*.gcno" -o \
		-name "*.gcda" \
		\) \
	-delete


tests_run:
	$(CC) --coverage -o unit_tests $(SRC_FILES) tests/test_borwein.c -lcriterion -lm
	./unit_tests

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all
