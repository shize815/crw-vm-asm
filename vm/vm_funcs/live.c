/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Wed Mar 21 23:58:22 2012 clovis kyndt
*/

#include	"corewar.h"
#include	"vm_funcs.h"

void		live(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*it;

  puts("o");
  it = arena->champs;
  printf("LIVE:%d\n", argv[0]);
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
