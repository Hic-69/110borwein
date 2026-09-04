##
## EPITECH PROJECT, 2026
## 110borwein
## File description:
## bonus makefile (benchmark of the integration methods)
##

CC	=	epiclang

MAIN	=	src/benchmark.c \

SRC_FILES	=	src/error_cases.c \
			src/function.c \
			src/parsing.c \
			src/midpoint.c \
			src/trapezoidal.c \
			src/simpson.c \
			src/display_result.c \

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_SRC_FILES	=	$(SRC_FILES:.c=.o)

NAME	=	benchmark

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

fclean:	clean
	rm -f $(NAME)

re: fclean all
