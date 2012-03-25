/*
** print_commun.c for print commun in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:59:06 2012 clovis kyndt
** Last update Sun Mar 25 18:55:22 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            print_my_arg(char *map, int *i, int arg[],
			     char nb, char type[])
{
  int           n;
  int           s;

  n = 0;
  while (nb > 0 && n < 4)
    {
      s = 0;
      if (type[n] == 1)
        s = REG_SIZE;
      else if (type[n] == 2)
        s = DIR_SIZE;
      else if (type[n] == 3 || type[n] == 4)
        s = IND_SIZE;
      if (s == 1)
	arg[n] = print_my_char(map, i);
      else if (s == 2)
	arg[n] = print_my_short(map, i, s);
      else if (s == 4)
	arg[n] = print_my_int(map, i, s);
      n++;
      nb--;
    }
  arg[n] = '\0';
}
