##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## finalstumper
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -lcsfml-graphics -lcsfml-audio

NAME	= 101pong2D

SRC 	= pong2D.c

all:	compil

compil:	$(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

PHONY:	re all clean fclean valgrind
