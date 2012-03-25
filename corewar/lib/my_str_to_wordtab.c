/*
** my_str_to_wordtab.c for minishell in /home/ecormi_p//Projets/Systeme Unix/Minishell1
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Dec 19 23:49:04 2011 pierre ecormier
** Last update Mon Feb 13 15:55:42 2012 pierre ecormier
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"

int		count_words(char *str)
{
  int		i;
  int		words;

  words = 0;
  i = -1;
  while (str[++i])
    {
      if (i == 0 || (!IS_SPACE(str[i]) && IS_SPACE(str[i - 1])))
	words++;
    }
  return (words);
}

int		get_word(char *str, char **dest)
{
  int		i;
  int		j;

  if ((*dest = malloc(my_strlen(str) + 1)) == NULL)
    exit(1);
  i = -1;
  j = -1;
  while (str[++i] && IS_SPACE(str[i]));
  i--;
  while (str[++i] && !IS_SPACE(str[i]))
    (*dest)[++j] = str[i];
  (*dest)[++j] = '\0';
  return (i);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		size;
  int		i;
  int		j;

  if ((size = count_words(str)) == -1)
    return (NULL);
  if ((tab = malloc((size + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (++i < size)
    j += get_word(str + j, &(tab[i]));
  tab[i] = NULL;
  return (tab);
}
