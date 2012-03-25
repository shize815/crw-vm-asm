/*
** home_vm.c for home_vm in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:27:16 2012 clovis kyndt
** Last update Sun Mar 25 16:27:02 2012 guillaume boell
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
  int		o = 0;

  ptr_i = (*i + 1) % MEM_SIZE;
  /*  printf(">");*/
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
    {
      printf("[%06d %06d] ", tmp->pc, tmp->num);
      (act_fct[nb])(arena, tmp, type, arg);
    }
  else
    printf("<RIEN>");
  /* printf("Name:%s  | last_champ: %s ", tmp->name, arena->champs->name); */
  while (arg[o] && o < 4)
    {
      /* printf(" argv[%d] : %d ;", o, arg[o]); */
      o++;
    }
  /* printf("\n"); */
  if (act != ZJMP || tmp->carry == 0)
    tmp->pc = ptr_i;
  /* WHATTTTTTTTT THEEEEEEEEEEEEE FUUUUUUUUUUUUUUUUUUUUCK */
  return (0);
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
      time_act = time_action(mem[i]);
      if ((champ->cycle + time_act) <= cycle && mem[i] >= 0 && mem[i] < 16)
        {
          type = decript_type(mem[i]);
	  dedi_no_tab(champ, arena, &i, type, act_fct, mem[i]);
          champ->cycle = cycle;
        }
      else if ((champ->cycle + time_act) <= cycle && (mem[i] < 0 || mem[i] >= 16))
	{
	  printf("Error Mem[i],%d\n", mem[i]);
	}
      champ = champ->next;
    }
  return (0);
}

void            home_vm(t_arena *arena, t_args_events *args)
{
  int           cycle;
  int           cycle_m;
  void          (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]);

  init_fct_tab(act_fct);
  cycle_m = arena->cycle_to_die;
  while (champ_count(arena->champs) > 1)
    {
      cycle = 0;
      arena->nb_live = 0;
      init_live(arena->champs);
      while (cycle < arena->cycle_to_die && arena->nb_live < NBR_LIVE)
        {
          cycle_action(arena, act_fct, cycle);
	  do_refresh(args);
          cycle++;
        }
      if (arena->nb_live >= NBR_LIVE)
        arena->cycle_to_die -= CYCLE_DELTA;
      champ_count(arena->champs);
      kill_champ(arena);
      puts("Boucle");
    }
  puts("END");
}
