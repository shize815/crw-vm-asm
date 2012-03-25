##
## Makefile for corewar-vm in /home/boell_g/crw-vm-asm/vm
## 
## Made by guillaume boell
## Login   <boell_g@epitech.net>
## 
## Started on  Tue Mar 20 15:37:42 2012 guillaume boell


NAME=	corewar

MY=	lib/get_next_line.c	\
	lib/llist_utils.c	\
	lib/my_strlen.c		\
	lib/my_strcmp.c		\
	lib/my_putnbr.c		\
	lib/my_strdup.c		\
	lib/my_str_to_wordtab.c

APDIR=	vm_apply
APSRC=	$(APDIR)/count_champs.c		\
	$(APDIR)/home_vm.c		\
	$(APDIR)/initialisation_app.c	\
	$(APDIR)/kill_champ.c		\
	$(APDIR)/slct_kill.c		\
	$(APDIR)/print_commun.c		\
	$(APDIR)/print_special.c	\
	$(APDIR)/init_vm.c		\
	$(APDIR)/win_champ.c		\
	$(APDIR)/print_widget.c

VMDIR=	vm_funcs
VMSRC=	$(VMDIR)/live.c		\
	$(VMDIR)/st_ld.c	\
	$(VMDIR)/ops.c		\
	$(VMDIR)/zjmp.c		\
	$(VMDIR)/sti_ldi.c	\
	$(VMDIR)/fork.c		\
	$(VMDIR)/aff.c

SRC=	main.c			\
	vm_init.c		\
	setpix.c		\
	graphic.c		\
	events.c		\
	xappels.c		\
	$(VMSRC)		\
	$(APSRC)		\
	$(MY)

OBJ=	$(SRC:.c=.o)

CFLAGS=	-I include/								\
	-W -Wall -Wextra							\
	-ansi -pedantic								\
	-g

LIB=	-L./minilibx/ -lmlx_x86_64-linux -L/usr/lib/X11 -lXext -lX11 -lm

RM=	@rm -f

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB);

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
