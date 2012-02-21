/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Tue Feb 21 15:50:36 2012 guillaume boell
*/
#include "corewar.h"

int	get_arg_nbr(char c, char **argv, int wait_until)
{
  int	i;
  int	nb;

  i = nb = 0;
  while (argv[i])
    {
      if (argv[i][0] == c)
	{
	  if (nb == wait_until)
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

int	main(int argc, char **argv)
{
  int		i;
  t_champ	*champ;

  i = 1;
  printf("%d\n");
  if (argc >= 3)
    while (argv[i])
      {
	i++;
      }
  return (0);
}
