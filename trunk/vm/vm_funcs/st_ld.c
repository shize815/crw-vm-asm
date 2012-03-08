/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar  8 16:51:55 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		st(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[champ->pc + (argv[1] % IDX_MOD)]);
  *addr = champ->r[argv[0]];
  type = type;
}

void		ld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[champ->pc + (*argv % IDX_MOD)]);
  champ->r[argv[1]] = *addr;
  champ->carry = (champ->r[argv[1]] == 0);
  type = type;
}

void		lld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[champ->pc + *argv]);
  champ->r[argv[1]] = *addr;
  champ->carry = (champ->r[argv[1]] == 0);
  type = type;
}
