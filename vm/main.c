/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Wed Mar 21 15:22:46 2012 guillaume boell
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"

int		get_arg_nbr(char c, char **argv, int wait_until)
{
  int		i;
  int		nb;

  i = nb = 0;
  while (argv[i])
    {
      if (argv[i][0] == '-' && argv[i][1] == c)
	{
	  if (nb >= wait_until)
	    {
	      if (argv[i + 1])
		return (my_getnbr(argv[i + 1]));
	    }
	  nb++;
	}
      i++;
    }
  return (-1);
}

/* int		get_nbr(char **argv, int wait_until) */
/* { */
/*   int		i; */
/*   int		nb; */

/*   nb = i = 0; */
/*   i++; */
/*   while (argv[i]) */
/*     { */
/*       if (argv[i][0] != '-') */
/* 	{ */
/* 	  if (nb >= wait_until) */
/* 	    { */
/* 	      if (argv[i + 1]) */
/* 		{ */
/* 		  printf("ret %d\n", nb); */
/* 		  return (nb); */
/* 		} */
/* 	    } */
/* 	  nb++; */
/* 	} */
/*       i++; */
/*     } */
/*   return (3); */
/* } */

void		rempl_tabl(int *tab, char c, char **argv)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      tab[i] = get_arg_nbr(c, argv, i);
      i++;
    }
}

char		*get_name(char **argv, int wait_until)
{
  int		i;
  int		nb;

  nb = 0;
  i = 1;
  while (argv[i])
    {
      if (argv[i][0] != '-' && i >= 1 && argv[i - 1][0] != '-')
	{
	  if (nb >= wait_until)
	    return (argv[i]);
	  nb++;
	}
      i++;
    }
  return (NULL);
}

int		get_valid_id(int *t)
{
  int		ret;

  ret = t[0];
  ret++;
  while (ret == t[0] || ret == t[1] || ret == t[2] || ret == t[3])
    ret++;
  return (ret);
}

t_champ		*gen_champs(t_champ *start, int *tab, char **argv)
{
  int		i;
  int		y;
  t_champ	*first;
  t_champ	*buf;

  i = 0;
  buf = first = start = xmalloc(sizeof(t_champ));
  while ((start->name = get_name(argv, i)) != NULL)
    {
      if (tab[i] == -1)
	tab[i] = get_valid_id(tab);
      start->num = tab[i];
      start->nb_live = start->last_live = 0;
      y = start->timer = 0;
      while (y <= 15)
	{
	  start->r[y] = 0;
	  y++;
	}
      buf = start;
      start->next = xmalloc(sizeof(t_champ));
      start = start->next;
      i++;
    }
  free(buf->next);
  buf->next = NULL;
  return (first);
}

int		write_one_champ(char *mem, char *file)
{
  int		fd;
  int		i;
  int		y;
  char		buf[2200];

  i = y = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  read(fd, buf, 2192);
  while (read(fd, buf, 128))
    {
      while (i < 128)
	{
	  mem[y % MEM_SIZE] = buf[i];
	  y++;
	  i++;
	}
      i = 0;
    }
  close(fd);
  return (1);
}

void		write_champs(char *mem, t_champ *champ, int *load_addr, int esp)
{
  int		max;

  max = 0;
  while (champ)
    {
      if (load_addr[max] != -1)
	{
	  write_one_champ(mem + (load_addr[max] % MEM_SIZE), champ->name);
	  champ->pc = (load_addr[max] % MEM_SIZE);
	}
      else
	{
	  write_one_champ(mem + (esp * max), champ->name);
	  champ->pc = (max * esp);
	}
      champ = champ->next;
      max++;
    }
}

void		write_memory(char *mem, t_champ *champ, int *load_addr)
{
  t_champ	*begin;
  int		max;
  int		esp;

  begin = champ;
  max = esp = 0;
  while (MEM_SIZE - 1 - max >= 0)
    {
      mem[MEM_SIZE - 1 - max] = 0;
      max++;
    }
  max = 0;
  while (champ)
    {
      max++;
      champ = champ->next;
    }
  if (max)
    esp = MEM_SIZE / max;
  champ = begin;
  write_champs(mem, champ, load_addr, esp);
}

void		aff_mem(char *mem)
{
  int		i;
  int		y;

  i = y = 0;
  while (y < MEM_SIZE)
    {
      i = 0;
      while (i == 0 || i < 128)
	{
	  my_putchar(mem[y] + '0');
	  i++;
	  y++;
	}
      my_putchar('\n');
    }
}

int		main(int argc, char **argv)
{
  int		cycles_max;
  int		load_addr[4];
  int		champ_id[4];
  t_champ	*start_champ;
  char		*map;
  t_arena	arena;

  cycles_max = get_arg_nbr('d', argv, 0);
  rempl_tabl(load_addr, 'a', argv);
  rempl_tabl(champ_id, 'n', argv);
  map = xmalloc(MEM_SIZE);
  start_champ = gen_champs(start_champ, champ_id, argv);
  write_memory(map, start_champ, load_addr);
  arena.champs = start_champ;
  arena.cycle_max = cycles_max;
  arena.cycle_to_die = CYCLE_TO_DIE;
  arena.nb_live = arena.nb_process = 0;
  arena.map = map;
  aff_mem(map);
  launch_game(&arena);
  apply_search(&arena);
  return (0);
}
