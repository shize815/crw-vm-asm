/*
** tri.c for tri in /home/kyndt/crw-vm-asm/vm
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 15 13:48:52 2012 clovis kyndt
** Last update Tue Mar 20 10:36:22 2012 clovis kyndt
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

int		dedi_no_tab(t_champ *champ, t_arena *arena, int *i, char index)
{
  int		arg[4];
  char		type[4];
  char		nb;
  int		ptr_i;

  ptr_i = *i + 1;
  nb = (arena->map)[ptr_i % MEM_SIZE];
  if (index)
    {
      nb = select_oct(type, nb);
      print_my_arg(arena->map, &ptr_i, arg, nb);
    }
  /* Je transforme totu ça en tableau priorité au fonctionnement */
  if ((arena->map)[*i] == LD)
    ld(arena, champ, type, arg);
  else if ((arena->map)[*i] == ST)
    st(arena, champ, type, arg);
  else if ((arena->map)[*i] == ADD)
    add(arena, champ, type, arg);
  else if ((arena->map)[*i] == SUB)
    sub(arena, champ, type, arg);
  else if ((arena->map)[*i] == AND)
    and(arena, champ, type, arg);
  else if ((arena->map)[*i] == OR)
    or(arena, champ, type, arg);
  else if ((arena->map)[*i] == XOR)
    xor(arena, champ, type, arg);
  else if ((arena->map)[*i] == LDI)
    ldi(arena, champ, type, arg);
  else if ((arena->map)[*i] == STI)
    sti(arena, champ, type, arg);
  else if ((arena->map)[*i] == LLD)
    lld(arena, champ, type, arg);
  else if ((arena->map)[*i] == LLDI)
    lldi(arena, champ, type, argv);
  else if ((arena->map)[*i] == AFF)
    aff(arena, champ, type, arg);
  return (0);
}

int		dedicace_pas_de_tableau_sans_argument(t_champ *champ, t_arena *arena, int *i, char index)
{
  int           arg[4];
  char          type[4];
  char          nb;
  int           ptr_i;

  ptr_i = *i + 1;
  arg[0] = (arena->map)[ptr_i % MEM_SIZE];
  arg[1] = '\0';
  type[0] = '\0';
  if ((arena->map)[*i] == LIVE)
    live(arena, champ, type, arg);
  else if ((arena->map)[*i] == ZJMP)
    zjmp(arena, champ, type, arg);
  else if ((arena->map)[*i] == FORK)
    fork(arena, champ, type, arg);
  else if ((arena->map)[*i] == LFORK)
    lfork(arena, champ, type, arg);
  return (0);
}

int		read_arg(t_champ *champ, t_arena *arena)
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
        cycle_d = dedicace_pas_de_tableau_sans_argument(champ, arena, &i, type);
      else
	cycle_d = dedi_no_tab(champ, arena, &i, type);
    }
}

void		apply_search(t_arena *arena)
{
  t_champ	*champ;

  champ = arena->champs;
  while (champ != NULL)
    {
      read_arg(champ, arena->map);
      champ = champ->next;
    }
}
