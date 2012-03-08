/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar  8 16:53:23 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		sti(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[argv[1] + argv[2]]);
  *addr = champ->r[argv[0]];
  type = type;
}

void		ldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[champ->pc + (*argv % IDX_MOD)]);
  *addr += argv[1];
  addr = (unsigned int *) &(arena->map[champ->pc + (*addr % IDX_MOD)]);
  champ->r[argv[2]] = *addr;
  champ->carry = (champ->r[argv[2]] == 0);
  type = type;
}

void		lldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[champ->pc + *argv]);
  *addr += argv[1];
  addr = (unsigned int *) &(arena->map[champ->pc + *addr]);
  champ->r[argv[2]] = *addr;
  champ->carry = (champ->r[argv[2]] == 0);
  type = type;
}
