/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Sun Mar 25 16:14:16 2012 guillaume boell
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
      start->nb_live = start->last_live = start->timer = 0;
      start->parent = y = -1;
      while (++y < REG_NUMBER)
	start->r[y] = 0;
      start->r[1] = start->num;
      buf = start;
      start->next = xmalloc(sizeof(t_champ));
      start = start->next;
      i++;
    }
  free(buf->next);
  buf->next = NULL;
  return (first);
}
