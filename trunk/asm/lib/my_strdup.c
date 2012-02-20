/*
** my_strdup.c for minishell in /home/ecormi_p//Projets/Systeme Unix/Minishell1
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Dec 19 16:34:30 2011 pierre ecormier
** Last update Sun Feb 19 20:11:08 2012 pierre ecormier
*/

#include	<stdlib.h>

char		*my_strdup(char *s)
{
  int		len;
  char		*dest;

  len = 0;
  while (s[len])
    len++;
  if ((dest = malloc(len + 1)) == NULL)
    exit(1);
  dest[len] = '\0';
  while (--len >= 0)
    dest[len] = s[len];
  return (dest);
}
