/*
** slct_kill.c for select kill in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Sun Mar 25 17:37:39 2012 clovis kyndt
** Last update Sun Mar 25 17:56:56 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

int		kill_elm_list(t_champ *champs)
{
  t_champ       *tmp;

  if (champs == NULL)
    return (0);
  if (champs->next == NULL)
    return (0);
  tmp = champs->next;
  champs->next = tmp->next;
  free(tmp);
  return (0);
}
