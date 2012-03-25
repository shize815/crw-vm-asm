##
## Makefile for corewar in /home/ecormi_p/crw-vm-asm/vm
## 
## Made by pierre ecormier
## Login   <ecormi_p@epitech.net>
## 
## Started on  Sun Mar 25 18:46:25 2012 pierre ecormier
## Last update Sun Mar 25 22:30:18 2012 pierre ecormier
##

NAME=	corewar

MY=	lib/get_next_line.c	\
	lib/llist_utils.c	\
	lib/my_strlen.c		\
	lib/my_strcmp.c		\
	lib/my_putnbr.c		\
	lib/my_strdup.c		\
	lib/my_printf.c		\
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
	dump_mem.c		\
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
