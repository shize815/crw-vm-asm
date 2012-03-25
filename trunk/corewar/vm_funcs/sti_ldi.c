/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sun Mar 25 21:51:07 2012 pierre ecormier
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

void		sti(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  int		offset;
  unsigned int	*addr;

  if (!REG_VALID(argv[0]) || ((type[1] == T_REG && !REG_VALID(argv[1]))) ||
      (type[2] == T_REG && !REG_VALID(argv[2])))
    return;
  my_printf("sti (r%d=%d -> i@pc+(", argv[0], champ->r[argv[0]]);
  offset = type[1] == T_REG ? champ->r[argv[1]] : argv[1];
  my_printf(type[1] == T_REG ? "r%d=" : "d=%d", argv[1]);
  if (type[1] == T_REG)
    my_printf("%d", champ->r[argv[1]]);
  offset += type[2] == T_REG ? champ->r[argv[2]] : argv[2];
  my_printf(type[2] == T_REG ? " + r%d=" : " + d=%d", argv[2]);
  if (type[2] == T_REG)
    my_printf("%d", champ->r[argv[2]]);
  my_printf("))\n");
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + offset)]);
  print_int((char *) addr, champ->r[*argv]);
}

void		ldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  short		*ad;
  int		i;
  unsigned int	*addr;

  my_printf("ldi %d %d %d\n", argv[0], argv[1], argv[2]);
  ad = (short *) &(arena->map[VM_BORD(champ->pc + (*argv % IDX_MOD))]);
  i = *ad + argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + (i % IDX_MOD))]);
  if (REG_VALID(argv[2]))
    read_int((char *) addr, &(champ->r[argv[2]]));
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}

void		lldi(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  short		*ad;
  int		i;
  unsigned int	*addr;

  my_printf("lldi %d %d %d\n", argv[0], argv[1], argv[2]);
  ad = (short *) &(arena->map[VM_BORD(champ->pc + *argv)]);
  i = *ad + argv[1];
  addr = (unsigned int *) &(arena->map[VM_BORD(champ->pc + i)]);
  if (REG_VALID(argv[2]))
    read_int((char *) addr, &(champ->r[argv[2]]));
  champ->carry = REG_VALID(argv[2]) ? (champ->r[argv[2]] == 0) : 0;
  type = type;
}
