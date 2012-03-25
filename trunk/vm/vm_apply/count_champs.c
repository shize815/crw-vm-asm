/*
** count_champs.c for count champion in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:44:56 2012 clovis kyndt
** Last update Sun Mar 25 18:06:38 2012 pierre ecormier
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
  my_printf("NB CHAMP live : %d\n", i);
  return (i);
}
