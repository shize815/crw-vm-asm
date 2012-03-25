/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Sun Mar 25 16:48:50 2012 guillaume boell
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"

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
	  my_putchar('.');
	  my_putbin(mem[y]);
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

  start_champ = NULL;
  cycles_max = get_arg_nbr('d', argv, 0);
  rempl_tabl(load_addr, 'a', argv);
  rempl_tabl(champ_id, 'n', argv);
  map = xmalloc(MEM_SIZE);
  start_champ = gen_champs(start_champ, champ_id, argv);
  write_memory(map, start_champ, load_addr);
  arena.champs = start_champ;
  arena.cycle_max = cycles_max;
  arena.cycle_to_die = CYCLE_TO_DIE;
  arena.nb_live = arena.nb_process = argc = 0;
  while (start_champ && (start_champ = start_champ->next))
    arena.nb_process++;
  arena.map = map;
  aff_mem(map);
  launch_game(&arena);
  return (0);
}
