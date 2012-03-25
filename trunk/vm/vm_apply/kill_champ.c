/*
** kill_champ.c for kill champions in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:43:00 2012 clovis kyndt
** Last update Sun Mar 25 11:53:43 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

static int	kill_elm_list(t_champ *champs)
{
  t_champ	*tmp;

  if (champs == NULL)
    return (0);
  if (champs->next == NULL)
    return (0);
  tmp = champs->next;
  champs->next = tmp->next;
  free(tmp);
}

static t_champ	*kill_first_elm(t_champ *champs)
{
  t_champ	*tmp;

  tmp = champs;
  if (tmp == NULL)
    return (NULL);
  if (tmp->next == NULL)
    {
      free(tmp);
      return (NULL);
    }
  tmp = tmp->next;
  free(champs);
  return (tmp);
}

static t_champ	*kill_fils(t_champ *champs, int pid)
{
  t_champ	*tmp;
  t_champ	*tmp2;
  t_champ	*tmp_return;

  tmp = champs;
  while (tmp->next != NULL)
    {
      tmp2 = tmp->next;
      if (tmp2->parent == pid)
	kill_elm_list(tmp);
      tmp = tmp->next;
    }
  if (champs != NULL && champs->parent == pid)
    tmp_return = kill_first_elm(champs);
  return (tmp_return);
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
	  pass[0] = 1;
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
  t_champ	*tmp;
  int		pass;

  pass = 1;
  tmp = arena->champs;
  while (pass != 0)
    {
      pass = 0;
      tmp = kill_my_select_champ(tmp, &pass);
    }
  arena->champs = tmp;
}
