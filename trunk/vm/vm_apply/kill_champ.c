/*
** kill_champ.c for kill champions in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:43:00 2012 clovis kyndt
** Last update Sun Mar 25 19:31:22 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

static void	pnt_kill_my_champ(t_champ *tmp, int *pass)
{
  t_champ	*tmp2;

  pass[0] = 1;
  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  free(tmp2);
}

static t_champ	*kill_my_select_champ(t_champ *champs, int *pass)
{
  t_champ       *tmp;
  t_champ       *tmp2;

  tmp = champs;
  if (tmp->last_live == 0)
    {
      tmp = tmp->next;
      pass[0] = 1;
      free(champs);
      return (tmp);
    }
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->last_live == 0)
        {
	  pnt_kill_my_champ(tmp2, pass);
          return (champs);
        }
      tmp2 = tmp;
      tmp = tmp->next;
    }
  return (champs);
}

void            kill_champ(t_arena *arena)
{
  t_champ	*tmp;
  int		pass;

  pass = 1;
  tmp = arena->champs;
  while (pass != 0)
    {
      pass = 0;
      if (tmp != NULL && tmp->next != NULL)
	tmp = kill_my_select_champ(tmp, &pass);
    }
  arena->champs = tmp;
}
