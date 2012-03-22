/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Thu Mar 22 14:36:33 2012 pierre ecormier
*/

#include	<stdio.h>
#include	"corewar.h"
#include	"vm_funcs.h"

void		live(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*it;

  printf("live %d\n", argv[0]);
  it = arena->champs;
  while (it && it->num != *argv)
    it = it->next;
  if (it)
    {
      puts("live!");
      it->last_live = 1;
      it->nb_live++;
      arena->nb_live++;
    }
  type = type;
  champ = champ;
}
