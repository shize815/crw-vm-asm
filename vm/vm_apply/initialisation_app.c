/*
** initialisation_app.c for init fct in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:45:58 2012 clovis kyndt
** Last update Fri Mar 23 15:25:34 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            init_time_tab(int time_tab[])
{
  time_tab[0] = 10;
  time_tab[1] = 5;
  time_tab[2] = 5;
  time_tab[3] = 10;
  time_tab[4] = 10;
  time_tab[5] = 6;
  time_tab[6] = 6;
  time_tab[7] = 6;
  time_tab[8] = 20;
  time_tab[9] = 25;
  time_tab[10] = 25;
  time_tab[11] = 800;
  time_tab[12] = 10;
  time_tab[13] = 50;
  time_tab[14] = 1000;
  time_tab[15] = 2;
}

int             time_action(char c)
{
  int           time_tab[16];
  int           i;

  i = c;
  init_time_tab(time_tab);
  if (c >= 0 && c < 16)
    return (time_tab[i]);
  else
    printf("- RIEN");
  return (0);
}

int             decript_type(char c)
{
  /* DEBUG */
  if (c == LIVE)
    printf("- LIVE ");
  else if (c == LD)
    printf("- LD ");
  else if (c == ST)
    printf("- ST ");
  else if (c == ADD)
    printf("- ADD ");
  else if (c == SUB)
    printf("- SUB ");
  else if (c == AND)
    printf("- AND ");
  else if (c == OR)
    printf("- OR ");
  else if (c == XOR)
    printf("- XOR ");
  else if (c == ZJMP)
    printf("- ZJMP ");
  else if (c == LDI)
    printf("- LDI ");
  else if (c == STI)
    printf("- STI ");
  else if (c == FORK)
    printf("- FORK ");
  else if (c == LLD)
    printf("- LLD ");
  else if (c == LLDI)
    printf("- LLDI ");
  else if (c == LFORK)
    printf("- LFORK ");
  else if (c == AFF)
    printf("- AFF ");
  /* END */
  if (c == LIVE || c == ZJMP || c == FORK || c == LFORK)
    return (0);
  if (c > 0 && c <= 16)
    return (1);
  return (-1);
}

void            init_fct_tab(void  (*act_fct[])(t_arena *arena, t_champ *champ, char type[4], int argv[4]))
{
  act_fct[0] = live;
  act_fct[1] = ld;
  act_fct[2] = st;
  act_fct[3] = add;
  act_fct[4] = sub;
  act_fct[5] = and;
  act_fct[6] = or;
  act_fct[7] = xor;
  act_fct[8] = zjmp;
  act_fct[9] = ldi;
  act_fct[10] = sti;
  act_fct[11] = fork;
  act_fct[12] = lld;
  act_fct[13] = lldi;
  act_fct[14] = lfork;
  act_fct[15] = aff;
}

void            init_live(t_champ *champ)
{
  t_champ       *tmp;

  tmp = champ;
  while (tmp != NULL)
    {
      tmp->nb_live = 0;
      tmp->cycle = 0;
      tmp = tmp->next;
    }
}
