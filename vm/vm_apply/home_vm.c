/*
** home_vm.c for home_vm in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:27:16 2012 clovis kyndt
** Last update Fri Mar 23 00:36:46 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

int             dedi_no_tab(t_champ *tmp, t_arena *arena, int *i, char index, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), unsigned char act)
{
  int           arg[4];
  char          type[4];
  int           nb;
  int           ptr_i;

  ptr_i = (*i + 1) % MEM_SIZE;
  printf(">");
  if (index > 0)
    {
      nb = (arena->map)[ptr_i % MEM_SIZE];
      nb = select_oct(type, nb);
      type_exp(act, type);
      ptr_i++;
      print_my_arg(arena->map, &ptr_i, arg, nb, type);
    }
  else if (!(index))
    print_my_arg_spec_eval(arena->map, &ptr_i, arg, act);
  nb = (arena->map)[*i] - 1;
  if (nb < 16 && nb >= 0)
    (act_fct[nb])(arena, tmp, type, arg);
  if (act != ZJMP || tmp->carry == 0)
    tmp->pc = ptr_i;
  printf("NAME:%s NAME:%s\n",  tmp->name, arena->champs->name);
  printf("\tPOSITION_OLD(%d) / POSITION_NEW(%d) / POSITION_NEW_CHA(%d) / nb : %d\n",*i, tmp->pc, arena->champs->pc, nb);
  /* WHATTTTTTTTT THEEEEEEEEEEEEE FUUUUUUUUUUUUUUUUUUUUCK */
  return (ptr_i);
}

int             cycle_action(t_arena *arena, void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), int cycle)
{
  int           i;
  t_champ       *champ;
  char          *mem;
  char          type;
  int           time_act;

  champ = arena->champs;
  mem = arena->map;
  while (champ != NULL)
    {
      i = champ->pc;
      printf("PC:%d\n", arena->champs->pc);
      time_act = time_action(mem[i]);
      if ((champ->cycle + time_act) <= cycle)
        {
          type = decript_type(mem[i]);
          champ->pc = dedi_no_tab(champ, arena, &i, type, act_fct, mem[i]);
          champ->cycle = cycle;
        }
      printf("PC::%d\n", arena->champs->pc);
      champ = champ->next;
      printf("PC::%d\n", arena->champs->pc);
    }
  printf("PC:::%d\n", arena->champs->pc);
  return (0);
}

void            home_vm(t_arena *arena, t_args_events *args)
{
  int           cycle;
  int           cycle_m;
  void          (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]);

  init_fct_tab(act_fct);
  cycle_m = arena->cycle_to_die;
  while (champ_count(arena->champs) > 0)
    {
      cycle = 0;
      arena->nb_live = 0;
      init_live(arena->champs);
      while (cycle < arena->cycle_to_die && arena->nb_live < NBR_LIVE)
        {
	  printf("PC>%d\n", arena->champs->pc);
          do_refresh(args);
          cycle_action(arena, act_fct, cycle);
	  printf("PC>>%d\n\n", arena->champs->pc);
          cycle++;
        }
      if (arena->nb_live >= NBR_LIVE)
        arena->cycle_to_die -= CYCLE_DELTA;
      kill_champ(arena);
      puts("Boucle");
    }
  puts("END");
}
