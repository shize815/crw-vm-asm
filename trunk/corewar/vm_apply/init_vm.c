/*
** init_vm.c for init in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Sun Mar 25 17:52:16 2012 clovis kyndt
** Last update Sun Mar 25 18:00:15 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

int		init_bc_vm(t_arena *arena)
{
  arena->nb_live = 0;
  init_live(arena->champs);
  return (0);
}
