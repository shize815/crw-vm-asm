/*
** count_champs.c for count champion in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:44:56 2012 clovis kyndt
** Last update Thu Mar 22 21:45:17 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

int             champ_count(t_champ *champ)
{
  int           i;
  t_champ       *tmp;

  i = 0;
  tmp = champ;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
