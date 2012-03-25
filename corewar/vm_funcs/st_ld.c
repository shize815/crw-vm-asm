/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sun Mar 25 21:50:59 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

static void	print_int(char *mem, int nb)
{
  mem[0] = (nb >> 24) & 0xFF;
  mem[1] = (nb >> 16) & 0xFF;
  mem[2] = (nb >> 8) & 0xFF;
  mem[3] = (nb >> 0) & 0xFF;
}

static void	read_int(char *mem, int *nb)
{
  *nb = (unsigned char) mem[0] << 24;
  *nb |= (unsigned char) mem[1] << 16;
  *nb |= (unsigned char) mem[2] << 8;
  *nb |= (unsigned char) mem[3];
}

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
      print_int((char *) addr, champ->r[argv[0]]);
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
      read_int((char *) addr, &(champ->r[argv[1]]));
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
      read_int((char *) addr, &(champ->r[argv[1]]));
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
