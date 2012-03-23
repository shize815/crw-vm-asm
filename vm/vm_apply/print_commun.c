/*
** print_commun.c for print commun in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:59:06 2012 clovis kyndt
** Last update Fri Mar 23 12:00:42 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            print_my_arg(char *map, int *i, int arg[], char nb, char type[])
{
  int           n;
  int           s;
  int           is;
  int		u;
  short		y;
  char		d;

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
      if (s == 1)
	{
	  while (s)
	    {
	      if (is == s)
		d = map[*i];
	      else
		{
		  d = d << 8;
		  d = map[*i] | d;
		}
	      *i = (*i + 1) % MEM_SIZE;
	      s--;
	    }
	  arg[n] = (int)d;
	}
      else if (s == 2)
	{
	  while (s)
	    {
	      if (is == s)
		y = map[*i];
	      else
		{
		  y = y << 8;
		  y = map[*i] | y;
		}
	      *i = (*i + 1) % MEM_SIZE;
	      s--;
	    }
	  arg[n] = (int)y;
	}
      else if (s == 4)
        {
          while (s)
            {
              if (is == s)
                u = map[*i];
              else
                {
                  u = u << 8;
                  u = map[*i] | u;
                }
              *i = (*i + 1) % MEM_SIZE;
              s--;
            }
          arg[n] = u;
        }
      /*      printf("\tn:%d val:%d \n", n, arg[n]);*/
      n++;
      nb--;
    }
  arg[n] = '\0';
}
