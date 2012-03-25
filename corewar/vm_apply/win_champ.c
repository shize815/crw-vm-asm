/*
** win_champ.c for win_champ in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Sun Mar 25 18:10:18 2012 clovis kyndt
** Last update Sun Mar 25 18:12:45 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void		aff_rendu(t_arena *arena)
{
  my_putstr("The winner is ");
  if (arena->champs != NULL)
    my_putstr(arena->champs->name);
  else
    my_putstr(arena->last_name);
  my_putstr("\n");
}
