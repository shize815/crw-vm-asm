/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar  8 16:58:41 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"
#include	"my.h"

void		aff(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  my_putchar(champ->r[argv[0]] % 256);
  arena = arena;
  type = type;
}
