/*
** kill_champ.c for kill champions in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:43:00 2012 clovis kyndt
** Last update Thu Mar 22 21:43:46 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

t_champ         *kill_my_select_champ(t_champ *champs)
{
  t_champ       *tmp;
  t_champ       *tmp2;

  tmp = champs;
  if (tmp->last_live == 0)
    {
      tmp = tmp->next;
      printf("Kill champ name : %s ; live : %d\n", champs->name, tmp->last_live);
      free(champs);
      return (tmp);
    }
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->last_live == 0)
        {
          printf("Kill champ name : %s ; live : %d\n", champs->name, tmp->last_live);
          tmp2->next = tmp->next;
          free(tmp);
          return (champs);
        }
      tmp2 = tmp;
      tmp = tmp->next;
    }
  return (champs);
}

void            kill_champ(t_arena *arena)
{
  int           i;

  i = arena->nb_process;
  while (i)
    {
      arena->champs = kill_my_select_champ(arena->champs);
      i--;
    }
}
