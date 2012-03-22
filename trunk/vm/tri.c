/*
** tri.c for tri in /home/kyndt/crw-vm-asm/vm
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 15 13:48:52 2012 clovis kyndt
** Last update Thu Mar 22 13:28:14 2012 clovis kyndt
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

void		print_my_arg(char *map, int *i, int arg[], char nb, char type[])
{
  int		n;
  int		s;
  int		is;

  n = 0;
  while (nb > 0 && n < 4)
    {
      s = 0;
      if (type[n] == 1)
	s = REG_SIZE;
      else if (type[n] == 2)
	s = DIR_SIZE;
      else if (type[n] == 3)
	s = IND_SIZE;
      is = s;
      while (s)
	{
          *i = (*i + 1) % MEM_SIZE;
	  if (is == s)
	    arg[n] = map[*i];
	  else
	    {
	      arg[n] = arg[n] << 8;
	      arg[n] = map[*i] | arg[n];
	    }
	  s--;
	}
      printf("n:%d val:%d \n", n, arg[n]);
      n++;
      nb--;
    }
  arg[n] = '\0';
}

void            print_my_arg_spec(char *map, int *i, int arg[], int s)
{
  int           is;

  is = s;
  while (s)
    {
      if (is == s)
	{
	  arg[0] = (char unsigned)map[*i];
	}
      else
	{
	  arg[0] = arg[0] << 8;
	  arg[0] = (char unsigned)map[*i] | arg[0];
	}
      *i = (*i + 1) % MEM_SIZE;
      s--;
    }
  printf("ARG[0] : %d\n", arg[0]);
  arg[1] = '\0';
}

void            print_my_arg_spec_eval(char *map, int *i, int arg[], char act)
{
  if (act == LIVE)
    print_my_arg_spec(map, i, arg, 4);
  else if (act == ZJMP)
    print_my_arg_spec(map, i, arg, IND_SIZE);
  else if (act == FORK || act == LFORK)
    print_my_arg_spec(map, i, arg, IND_SIZE);
}

int		dedi_no_tab(t_champ *champ, t_arena *arena, int *i, char index, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), char act)
{
  int		arg[4];
  char		type[4];
  int		nb;
  int		ptr_i;

  ptr_i = *i + 1;
  type[0] = '\0';
  if (index)
    {
      nb = (arena->map)[ptr_i % MEM_SIZE];
      nb = select_oct(type, nb);
      print_my_arg(arena->map, &ptr_i, arg, nb, type);
    }
  else 
    print_my_arg_spec_eval(arena->map, &ptr_i, arg, act);
  champ->pc = ptr_i;
  nb = (arena->map)[*i] - 1;
  printf("nb:%d champ->pc(old):%d champ->pc(new):%d\n", nb, *i, champ->pc);
  /* DEBUG */
  int		d = 0;
  while (arg[d] == '\0' && d < 4)
    {
      if (type[d] != '\0')
	printf("type[%d]:%d ", d, type[d]);
      printf("arg[%d]:%d\n", d, arg[d]);
      d++;
    }
  /* END */
  if (nb < 16 && nb >= 0)
    (act_fct[nb])(arena, champ, type, arg);
  return (0);
}

void		init_time_tab(int time_tab[])
{
  time_tab[0] = 10;
  time_tab[1] = 5;
  time_tab[2] = 5;
  time_tab[3] = 10;
  time_tab[4] = 10;
  time_tab[5] = 6;
  time_tab[6] = 6;
  time_tab[7] = 6;
  time_tab[8] = 20;
  time_tab[9] = 25;
  time_tab[10] = 25;
  time_tab[11] = 800;
  time_tab[12] = 10;
  time_tab[13] = 50;
  time_tab[14] = 1000;
  time_tab[15] = 2;
}

int		time_action(char c)
{
  int		time_tab[16];
  int		i;

  i = c;
  init_time_tab(time_tab);
  if (c >= 0 && c < 16)
    return (time_tab[i]);
  return (0);
}

int		dec_type(char c)
{
  /* DEBUG */
  if (c == LIVE)
    printf("LIVE ");
  else if (c == LD)
    printf("LD ");
  else if (c == ST)
    printf("ST ");
  else if (c == ADD)
    printf("ADD ");
  else if (c == SUB)
    printf("SUB ");
  else if (c == AND)
    printf("AND ");
  else if (c == OR)
    printf("OR ");
  else if (c == XOR)
    printf("XOR ");
  else if (c == ZJMP)
    printf("ZJMP ");
  else if (c == LDI)
    printf("LDI ");
  else if (c == STI)
    printf("STI ");
  else if (c == FORK)
    printf("FORK ");
  else if (c == LLD)
    printf("LLD ");
  else if (c == LLDI)
    printf("LLDI ");
  else if (c == LFORK)
    printf("LFORK ");
  else if (c == AFF)
    printf("AFF ");
  /* END */
  if (c == LIVE || c == ZJMP || c == FORK || c == LFORK)
    return (0);
  return (1);
}

int		read_arg(t_arena *arena, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), int cycle)
{
  int		i;
  t_champ	*champ;
  char		*mem;
  char		type;
  int		time_act;

  champ = arena->champs;
  mem = arena->map;
  while (champ != NULL)
    {
      i = champ->pc;
      time_act = time_action(mem[i]);
      if ((champ->cycle + time_act) <= cycle)
	{
	  type = dec_type(mem[i]);
	  dedi_no_tab(champ, arena, &i, type, act_fct, mem[i]);
	  champ->cycle = cycle;
	}
      champ = champ->next;
    }
  return (0);
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

int		champ_count(t_champ *champ)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

t_champ		*kill_champ(t_champ *champs)
{
  t_champ	*tmp;
  t_champ	*tmp2;

  tmp = champs;
  if (tmp->last_live == 0)
    {
      tmp = tmp->next;
      printf("1champ name : %s ; live : %d\n", champs->name, tmp->last_live);
      free(champs);
      return (tmp);
    }
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->last_live == 0)
	{
	  printf("2champ name : %s ; live : %d\n", champs->name, tmp->last_live);
	  tmp2->next = tmp->next;
	  free(tmp);
	  return (champs);
	}
      tmp = tmp->next;
    }
  return (champs);
}


void		init_live(t_champ *champ)
{
  t_champ	*tmp;

  while (tmp != NULL)
    {
      tmp->nb_live = 0;
      tmp = tmp->next;
    }
}

void		apply_search(t_arena *arena, t_args_events *args)
{
  int		cycle;
  int		cycle_m;
  void		(*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]);

  init_fct_tab(act_fct);
  cycle_m = arena->cycle_to_die;
  while (champ_count(arena->champs) > 1)
    {
      cycle = 0;
      arena->nb_live = 0;
      init_live(arena->champs);
      while (cycle < arena->cycle_to_die && arena->nb_live < NBR_LIVE)
	{
	  do_refresh(args);
	  read_arg(arena, act_fct, cycle);
	  cycle++;
	}
      if (arena->nb_live >= NBR_LIVE)
	arena->cycle_to_die -= CYCLE_DELTA;
      arena->champs = kill_champ(arena->champs);
      puts("Boucle");
    }
  puts("END");
}
