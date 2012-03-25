/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Sun Mar 25 22:03:19 2012 pierre ecormier
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"
#include	"my.h"

void		my_fork(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*elm;

  if ((elm = malloc(sizeof(*elm))) == NULL)
    exit(1);
  my_printf("fork (%d)\n", argv[0]);
  *elm = *champ;
  elm->next = arena->champs;
  elm->num = ++arena->nb_process;
  elm->parent = champ->num;
  elm->pc = VM_BORD(champ->pc + (argv[0] % IDX_MOD));
  arena->champs = elm;
  type = type;
}

void		lfork(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*elm;

  if ((elm = malloc(sizeof(*elm))) == NULL)
    exit(1);
  my_printf("lfork (%d)\n", argv[0]);
  champ->carry = 0;
  *elm = *champ;
  elm->next = arena->champs;
  elm->num = ++arena->nb_process;
  elm->parent = champ->num;
  elm->pc = VM_BORD(champ->pc + argv[0]);
  arena->champs = elm;
  type = type;
}
