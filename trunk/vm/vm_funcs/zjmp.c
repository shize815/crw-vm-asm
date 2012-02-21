/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Tue Feb 21 16:43:18 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		zjmp(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  if (champ->carry == 1)
    champ->pc += argv[0] % IDX_MOD;
  arena = arena;
  type = type;
}
