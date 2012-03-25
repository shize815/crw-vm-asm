/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sun Mar 25 18:30:57 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		st(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;
  int		offset;

  if (!REG_VALID(argv[0]) || (type[1] == T_REG && !REG_VALID(argv[1])))
    return;
  my_printf("st (r%d=%d -> ", argv[0], champ->r[argv[1]]);
  if (type[1] == T_REG)
    {
      champ->r[argv[1]] = champ->r[argv[0]];
      my_printf("r%d)\n", argv[1]);
    }
  else
    {
      offset = VM_BORD(champ->pc + (argv[1] % IDX_MOD));
      addr = (unsigned int *) &(arena->map[offset]);
      *addr = champ->r[argv[0]];
      my_printf("i@pc+(d=%d)\n", argv[1]);
    }
}

void		ld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;
  int		offset;

  if (!REG_VALID(argv[1]))
    return;
  if (type[0] == T_IND)
    {
      offset = VM_BORD(champ->pc + (*argv % IDX_MOD));
      addr = (unsigned int *) &(arena->map[offset]);
      champ->r[argv[1]] = *addr;
      my_printf("ld (i@pc+(d=%d)=%d -> r%d) ", argv[0], *addr, argv[1]);
    }
  else
    {
      champ->r[argv[1]] = argv[0];
      my_printf("ld (d=%d -> r%d) ", argv[0], argv[1]);
    }
  champ->carry = champ->r[argv[1]] == 0;
  my_printf("carry=%d\n", champ->carry);
}

void		lld(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  if (!REG_VALID(argv[1]))
    return;
  if (type[0] == T_IND)
    {
      addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + *argv)]);
      champ->r[argv[1]] = *addr;
      my_printf("lld (i@pc+(d=%d)=%d -> r%d) ", argv[0], *addr, argv[1]);
    }
  else
    {
      champ->r[argv[1]] = argv[0];
      my_printf("lld (d=%d -> r%d) ", argv[0], argv[1]);
    }
  champ->carry = champ->r[argv[1]] == 0;
  my_printf("carry=%d\n", champ->carry);
}
