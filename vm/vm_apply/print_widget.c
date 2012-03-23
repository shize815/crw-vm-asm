/*
** print_widget.c for fct le decoupage in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 22:01:01 2012 clovis kyndt
** Last update Fri Mar 23 15:28:08 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

char            select_oct(char tb[], unsigned char c)
{
  int           i;
  int           n;
  char          arg;
  char          d1;
  char          d2;

  i = 7;
  n = 0;
  arg = 0;
  while (i >= 0)
    {
      d1 = !!(c & (1 << i));
      i--;
      d2 = !!(c & (1 << i));
      tb[n] = d1 * 2 + d2;
      if (tb[n++] > 0)
        arg++;
      i--;
    }
  tb[n] = '\0';
  return (arg);
}

void             type_exp(char c, char type[])
{
  if (c == LD)
    type[1] = 1;
  if (c == ZJMP)
    type[0] = 2;
  if (c == STI)
    {
      if (type[1] != 1)
        type[1] = 4;
      if (type[2] != 1)
        type[2] = 4;
    }
  if (c == LDI)
    {
        type[0] = 4;
        type[1] = 4;
    }
}
