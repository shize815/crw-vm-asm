/*
** startswith.c for minishell in /home/ecormi_p//Projets/Systeme Unix/Minishell1
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Dec 19 20:47:34 2011 pierre ecormier
** Last update Sun Feb 12 12:00:01 2012 pierre ecormier
*/

int		startswith(char *str, char *s)
{
  int		i;

  i = 0;
  while (s[i] && str[i] && s[i] == str[i])
    i++;
  if (!s[i] || s[i] == str[i])
    return (1);
  return (0);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
