/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Tue Feb 21 17:10:28 2012 guillaume boell
*/
#include "op.h"
#include "corewar.h"

int	get_arg_nbr(char c, char **argv, int wait_until)
{
  int	i;
  int	nb;

  i = nb = 0;
  while (argv[i])
    {
      if (argv[i][0] == '-' && argv[i][1] == c && !argv[i][2])
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

void	rempl_tabl(int *tab, char c, char **argv)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      tab[i] = get_arg_nbr(c, argv, i);
      i++;
    }
}

char	*get_name(char **argv, int wait_until)
{
  int	i;
  int	nb;

  i = nb = 0;
  while (argv[i])
    {
      if (argv[i][0] != '-' && i >= 1)
	{
	  if (nb >= wait_until)
	    return (argv[i]);
	  nb++;
	}
      i++;
    }
  return (NULL);
}

int	get_valid_id(int *t)
{
  int	ret;

  ret = t[0];
  ret++;
  while (ret == t[0] || ret == t[1] || ret == t[2] || ret == t[3])
    ret++;
  return (ret);
}

void	gen_champs(t_champ *start, int *tab, char **argv)
{
  int	i;
  int	y;

  i = 0;
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
    start->next = xmalloc(sizeof(t_champ));
    start = start->next;
    i++;
  }
  start->name = NULL;
}

int	main(int argc, char **argv)
{
  int		i;
  int		cycles_max;
  int		load_addr[4];
  int		champ_id[4];
  t_champ	*start_champ;
  char		*map;
  t_arena	*arena;

  i = 1;
  cycles_max = get_arg_nbr('d', argv, 0);
  rempl_tabl(load_addr, 'a', argv);
  map = xmalloc(MEM_SIZE);
  gen_champs(start_champ, champ_id, argv);
  return (0);
}
