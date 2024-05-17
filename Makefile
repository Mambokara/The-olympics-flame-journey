##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## All rules to build the program
##

NAME	=	flame

SRC =   $(shell find src -name '*.c')

OBJ		=	$(SRC:.c=.o)

CSFML_FLAGS    = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS += -g

all:
	$(MAKE) -k --shuffle -j $(shell nproc) $(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(CSFML_FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
