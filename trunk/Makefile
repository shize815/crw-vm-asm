##
## Makefile for minilib_test in /home/ecormi_p//ExosPiscine/minilib_test
## 
## Made by pierre ecormier
## Login   <ecormi_p@epitech.net>
## 
## Started on  Mon Oct 24 16:56:40 2011 pierre ecormier
## Last update Sun Mar 25 21:18:46 2012 pierre ecormier
##

ASMDIR=	asm
VMDIR=	corewar

all: asm corewar

asm:
	cd $(ASMDIR) && make

corewar:
	cd $(VMDIR) && make

clean:
	cd $(ASMDIR) && make clean
	cd $(VMDIR) && make clean

fclean:	clean
	cd $(ASMDIR) && make fclean
	cd $(VMDIR) && make fclean

re: fclean all

.PHONY: asm corewar
