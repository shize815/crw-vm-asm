/*
** live.c for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:33:22 2012 pierre ecormier
** Last update Wed Mar 21 23:27:57 2012 clovis kyndt
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"
#include	"vm_funcs.h"
#include	"my.h"

void		fork(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*elm;

  /*
  if ((elm = malloc(sizeof(*elm))) == NULL)
    exit(1);
  *elm = *champ;
  elm->next = arena->champs;
  elm->name = my_strdup(champ->name);
  elm->comment = my_strdup(champ->comment);
  elm->pc = champ->pc + (argv[0] % IDX_MOD);
  arena->champs = elm;
  type = type;
  */
}

void		lfork(t_arena *arena, t_champ *champ, char type[4], int argv[4])
{
  t_champ	*elm;

  /*
  if ((elm = malloc(sizeof(*elm))) == NULL)
    exit(1);
  champ->carry = 0;
  *elm = *champ;
  elm->next = arena->champs;
  elm->name = my_strdup(champ->name);
  elm->comment = my_strdup(champ->comment);
  elm->pc = champ->pc + argv[0];
  arena->champs = elm;
  type = type;
  */
}
