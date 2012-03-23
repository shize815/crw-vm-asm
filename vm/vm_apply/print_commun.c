/*
** print_commun.c for print commun in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:59:06 2012 clovis kyndt
** Last update Thu Mar 22 22:51:32 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            print_my_arg(char *map, int *i, int arg[], char nb, char type[])
{
  int           n;
  int           s;
  int           is;

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
      is = s;
      while (s)
        {
          if (is == s)
            arg[n] = map[*i];
          else
            {
              arg[n] = (unsigned char)arg[n] << 8;
              arg[n] = (unsigned char)map[*i] | (unsigned char)arg[n];
            }
          *i = (*i + 1) % MEM_SIZE;
          s--;
        }
      printf("\tn:%d val:%d \n", n, arg[n]);
      n++;
      nb--;
    }
  arg[n] = '\0';
}
