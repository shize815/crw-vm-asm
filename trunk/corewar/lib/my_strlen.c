/*
** my_strlen.c for asm in /home/ecormi_p//Projets/C Prog Elem/Corewar
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 15:35:36 2012 pierre ecormier
** Last update Mon Feb 13 15:35:45 2012 pierre ecormier
*/

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}

int		my_tablen(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}
