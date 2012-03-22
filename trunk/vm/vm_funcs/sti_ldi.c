/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar 22 13:29:42 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		sti(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[VM_BORD(argv[1] + argv[2])]);
  if (REG_VALID(*argv))
    *addr = champ->r[*argv];
  type = type;
}

void		ldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (*argv % IDX_MOD))]);
  *addr += argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (*addr % IDX_MOD))]);
  if (REG_VALID(argv[2]))
    champ->r[argv[2]] = *addr;
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}

void		lldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + *argv)]);
  *addr += argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + *addr)]);
  if (REG_VALID(argv[2]))
    champ->r[argv[2]] = *addr;
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}
