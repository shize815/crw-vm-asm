/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar 22 14:36:56 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		zjmp(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  printf("zjmp %d\n", argv[0]);
  if (champ->carry == 1)
    champ->pc += argv[0] % IDX_MOD;
  arena = arena;
  type = type;
}
