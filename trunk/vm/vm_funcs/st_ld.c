/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar 22 14:36:40 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		st(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  printf("st %d\n", champ->r[argv[0]]);
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (argv[1] % IDX_MOD))]);
  if (REG_VALID(*argv))
    *addr = champ->r[argv[0]];
  type = type;
}

void		ld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  printf("ld %d\n", champ->r[argv[1]]);
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (*argv % IDX_MOD))]);
  if (REG_VALID(argv[1]))
    champ->r[argv[1]] = *addr;
  champ->carry = REG_VALID(argv[1]) ? (champ->r[argv[1]] == 0) : 0;
  type = type;
}

void		lld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  printf("lld %d\n", champ->r[argv[1]]);
  addr = (unsigned int *) &(arena->map[champ->pc + *argv]);
  if (REG_VALID(argv[1]))
    champ->r[argv[1]] = *addr;
  champ->carry = REG_VALID(argv[1]) ? (champ->r[argv[1]] == 0) : 0;
  type = type;
}
