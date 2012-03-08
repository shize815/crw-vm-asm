/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar  8 16:52:35 2012 pierre ecormier
*/

#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"

void		add(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  champ->r[argv[2]] = champ->r[argv[0]] + champ->r[argv[1]];
  champ->carry = (champ->r[argv[2]] == 0);
  arena = arena;
  type = type;
}

void		sub(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  champ->r[argv[2]] = champ->r[argv[0]] - champ->r[argv[1]];
  champ->carry = (champ->r[argv[2]] == 0);
  arena = arena;
  type = type;
}

void		and(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  champ->r[argv[2]] = champ->r[argv[0]] & champ->r[argv[1]];
  champ->carry = (champ->r[argv[2]] == 0);
  arena = arena;
  type = type;
}

void		or(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  champ->r[argv[2]] = champ->r[argv[0]] | champ->r[argv[1]];
  champ->carry = (champ->r[argv[2]] == 0);
  arena = arena;
  type = type;
}

void		xor(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  champ->r[argv[2]] = champ->r[argv[0]] ^ champ->r[argv[1]];
  champ->carry = (champ->r[argv[2]] == 0);
  arena = arena;
  type = type;
}
