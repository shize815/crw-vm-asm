##
## Makefile for minilib_test in /home/ecormi_p//ExosPiscine/minilib_test
## 
## Made by pierre ecormier
## Login   <ecormi_p@epitech.net>
## 
## Started on  Mon Oct 24 16:56:40 2011 pierre ecormier
## Last update Tue Feb 21 15:32:51 2012 guillaume boell
##

NAME=	corewar

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
