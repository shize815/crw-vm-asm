/*
** tri.c for tri in /home/kyndt/crw-vm-asm/vm
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 15 13:48:52 2012 clovis kyndt
** Last update Tue Mar 20 13:21:22 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

char            select_oct(char tb[], char c)
{
  int           i;
  int           n;
  char		arg;
  char          d1;
  char          d2;

  i = 7;
  n = 0;
  arg = 0;
  while (i >= 0)
    {
      d1 = !!(c & (1 << i));
      i--;
      d2 = !!(c & (1 << i));
      tb[n] = d1 * 2 + d2;
      if (tb[n++] > 0)
	arg++;
      i--;
    }
  tb[n] = '\0';
  return (arg);
}

void		print_my_arg(char *map, int *i, int arg[], char nb)
{
  char		n;

  n  = 0;
  while (nb > 0 && n < 4)
    {
      *i = (*i + 1) % MEM_SIZE;
      arg[n++] = map[*i];
      nb--;
    }
  arg[n] = '\0';
}

int		dedi_no_tab(t_champ *champ, t_arena *arena, int *i, char index, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]))
{
  int		arg[4];
  char		type[4];
  char		nb;
  int		ptr_i;

  ptr_i = *i + 1;
  type[0] = '\0';
  if (index)
    {
      nb = (arena->map)[ptr_i % MEM_SIZE];
      nb = select_oct(type, nb);
      print_my_arg(arena->map, &ptr_i, arg, nb);
    }
  else
    print_my_arg(arena->map, i, arg, 1);
  nb = (arena->map)[*i] - 1;
  if (nb < 16)
    (act_fct[nb])(arena, champ, type, arg);
  return (0);
}

int		read_arg(t_champ *champ, t_arena *arena, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]))
{
  int		i;
  int		cycle_d;
  char		*mem;
  char		type;

  mem = arena->map;
  cycle_d = arena->cycle_to_die;
  i = champ->pc;
  while (cycle_d > 0)
    {
      type = 1;
      if (mem[i] == LIVE || mem[i] == ZJMP || mem[i] == FORK || mem[i] == LFORK)
	type = 0;
      cycle_d = dedi_no_tab(champ, arena, &i, type, act_fct);
    }
}


void		init_fct_tab(void  (*act_fct[])(t_arena *arena, t_champ *champ, char type[4], int argv[4]))
{
  act_fct[0] = live;
  act_fct[1] = ld;
  act_fct[2] = st;
  act_fct[3] = add;
  act_fct[4] = sub;
  act_fct[5] = and;
  act_fct[6] = or;
  act_fct[7] = xor;
  act_fct[8] = zjmp;
  act_fct[9] = ldi;
  act_fct[10] = sti;
  act_fct[11] = fork;
  act_fct[12] = lld;
  act_fct[13] = lldi;
  act_fct[14] = lfork;
  act_fct[15] = aff;
}

void		apply_search(t_arena *arena)
{
  t_champ	*champ;
  void		(*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]);

  init_fct_tab(act_fct);
  champ = arena->champs;
  while (champ != NULL)
    {
      read_arg(champ, arena->map, act_arg);
      champ = champ->next;
    }
}
