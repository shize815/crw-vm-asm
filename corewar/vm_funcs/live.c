/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sun Mar 25 19:59:54 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"corewar.h"
#include	"vm_funcs.h"

void		my_cpy_last_l(char name[], char *s)
{
  int		i;
  int		n;

  i = 0;
  if (s == NULL)
    return;
  while (s[i + 1])
    i++;
  while (i >= 0 && s[i] != '/')
    i--;
  if (s[i] == '/')
    i++;
  n = 0;
  while (n < 80 && s[i])
    {
      name[n] = s[i];
      n++;
      i++;
    }
  name[n] = '\0';
}

void		live(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*it;

  my_printf("live (%d)\n", argv[0]);
  it = arena->champs;
  while (it && it->num != *argv)
    it = it->next;
  if (it)
    {
      it->last_live = 1;
      it->nb_live++;
      arena->nb_live++;
      my_cpy_last_l(arena->last_name, it->name);
    }
  type = type;
  champ = champ;
}
