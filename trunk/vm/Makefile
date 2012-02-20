##
## Makefile for minilib_test in /home/ecormi_p//ExosPiscine/minilib_test
## 
## Made by pierre ecormier
## Login   <ecormi_p@epitech.net>
## 
## Started on  Mon Oct 24 16:56:40 2011 pierre ecormier
## Last update Mon Feb 20 16:59:24 2012 guillaume boell
##

NAME=	corewar

MY=	lib/get_next_line.c	\
	lib/llist_utils.c	\
	lib/my_strlen.c		\
	lib/my_strcmp.c		\
	lib/my_putnbr.c		\
	lib/my_strdup.c		\
	lib/my_str_to_wordtab.c

SRC=	main.c			\
	$(MY)

OBJ=	$(SRC:.c=.o)

CFLAGS=	-I include/		\
	-W -Wall -Wextra	\
	-ansi -pedantic		\
	-g

RM=	@rm -f

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB);

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
