/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sat Mar 24 15:48:25 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		zjmp(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  printf("zjmp (%d) carry=%d\n", argv[0], champ->carry);
  if (champ->carry == 1)
    champ->pc += argv[0] % IDX_MOD;
  arena = arena;
  type = type;
}
