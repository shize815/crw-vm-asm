/*
** llist_utils.c for gnl in /home/ecormi_p//Projets/C Prog Elem/GetNextLine/v2
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Sat Dec 10 14:15:12 2011 pierre ecormier
** Last update Thu Mar  8 17:08:08 2012 pierre ecormier
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
