/*
** llist_utils.c for gnl in /home/ecormi_p//Projets/C Prog Elem/GetNextLine/v2
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Sat Dec 10 14:15:12 2011 pierre ecormier
** Last update Wed Feb 15 10:09:26 2012 pierre ecormier
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"

int		my_push_back(t_char **end, char *str, int len)
{
  t_char	*elm;

  elm = malloc(sizeof(t_char));
  if (elm == NULL)
    exit(EXIT_FAILURE);
  elm->str = str;
  elm->to_free = str;
  elm->len = len;
  elm->next = NULL;
  if (*end != NULL)
    (*end)->next = elm;
  *end = elm;
  return (0);
}

int		push_asm_back(t_asmline **begin, t_asmline **end, t_asmline *elm)
{
  elm->next = NULL;
  if (*begin == NULL)
    *begin = elm;
  else
    (*end)->next = elm;
  *end = elm;
  return (0);
}

int		replace_asm_list(t_asmline **rmbegin, t_asmline **replace, t_asmline *elm)
{
  t_asmline	*it;

  it = *rmbegin;
  while (it && it->next != elm)
    it = it->next;
  if (it && it->next == elm)
    it->next = elm->next;
  elm->next = *replace;
  *replace = elm;
  elm->argv[0][my_strlen(elm->argv[0]) - 1] = '\0';
  /* printf("Label : %s\n", elm->argv[0]); */
  return (0);
}
