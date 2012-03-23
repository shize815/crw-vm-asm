/*
** print_special.c for print_special in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:58:18 2012 clovis kyndt
** Last update Thu Mar 22 21:58:38 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            print_my_arg_spec(char *map, int *i, int arg[], int s)
{
  int           is;
  short         oct_2;

  is = s;
  while (s > 0)
    {
      if (is == s)
        {
          printf("e:%d\n", (unsigned char)map[*i]);
          arg[0] = map[*i];
        }
      else
        {
          printf("e:%d\n", map[*i]);
          arg[0] = arg[0] << 8;
          arg[0] = map[*i] | arg[0];
        }
      *i = (*i + 1) % MEM_SIZE;
      s--;
    }
  printf("\t ARG[0] : %d\n\n", arg[0]);
  arg[1] = '\0';
}

void            print_my_arg_spec_eval(char *map, int *i, int arg[], char act)
{
  if (act == LIVE)
    print_my_arg_spec(map, i, arg, 4);
  else if (act == ZJMP)
    {
      printf("ZJMP >> i:%d\n", *i);
      print_my_arg_spec(map, i, arg, IND_SIZE);
    }
  else if (act == FORK || act == LFORK)
    print_my_arg_spec(map, i, arg, IND_SIZE);
}
