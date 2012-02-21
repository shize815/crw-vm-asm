/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Tue Feb 21 16:34:45 2012 guillaume boell
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
  while (ret == t[0] || ret == t[1] || ret
}

void	gen_champs(t_champ *start, int *tab, char **argv)
{
  int		i;

  i = 0;
  while ((get_name = start) != NULL);
  {
    if (tab[i] == -1)
      tab[i] = get_valid_id(tab);
    start->num = tab[i];
    i++;
  }
}

int	main(int argc, char **argv)
{
  int		i;
  int		cycles_max;
  int		load_addr[4];
  int		champ_addr[4];
  t_champ	*start_champ;
  char		*map;
  t_arena	*arena;

  i = 1;
  cycles_max = get_arg_nbr('d', argv, 0);
  rempl_tabl(load_addr, 'a', argv);
  map = xmalloc(MEM_SIZE);
  gen_champs(start_champ);
  if (argc >= 3)
    while (argv[i])
      {
	/* parsing -> do*/
	i++;
      }
  return (0);
}
