/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Fri Mar 23 15:30:55 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		sti(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  if ((type[1] == T_REG && !REG_VALID(argv[1])) || (type[2] == T_REG && !REG_VALID(argv[2])))
    return;
  if (REG_VALID(argv[0]))
    printf("sti %d\n", champ->r[*argv]);
  addr = (unsigned int *) &(arena->map[VM_BORD((type[1] == T_REG ? champ->r[argv[1]] : argv[1]) + (type[2] == T_REG ? champ->r[argv[2]] : argv[2]))]);
  if (REG_VALID(*argv))
    *addr = champ->r[*argv];
  type = type;
}

void		ldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  short		*ad;
  unsigned int	*addr;

  if (REG_VALID(argv[2]))
    printf("ldi %d\n", champ->r[argv[2]]);
  ad = (short *) &(arena->map[VM_BORD(champ->pc + (*argv % IDX_MOD))]);
  *addr = *ad + argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (*addr % IDX_MOD))]);
  if (REG_VALID(argv[2]))
    champ->r[argv[2]] = *addr;
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}

void		lldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  short		*ad;
  unsigned int	*addr;

  if (REG_VALID(argv[2]))
    printf("ldi %d\n", champ->r[argv[2]]);
  ad = (unsigned short *) &(arena->map[VM_BORD(champ->pc + (*argv))]);
  *addr = *ad + argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (*addr))]);
  if (REG_VALID(argv[2]))
    champ->r[argv[2]] = *addr;
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}
