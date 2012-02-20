/*
** main.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 20 16:53:47 2012 guillaume boell
** Last update Mon Feb 20 17:14:05 2012 guillaume boell
*/
int	main(int argc, char **argv)
{
  int		i;
  t_champ	*champ;

  i = 1;
  if (argc >= 3)
    while (argv[i])
      {
	init_champ(champ);
	i++;
      }
  return (0);
}
