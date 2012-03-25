/*
** print_special.c for print_special in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:58:18 2012 clovis kyndt
** Last update Sun Mar 25 17:30:50 2012 pierre ecormier
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

int		print_my_char(char *map, int *i, int s)
{
  char          d;
  int		is;

  is = s;
  while (s)
    {
      if (is == s)
	d = (unsigned char)map[*i];
      else
	{
	  d = d << 8;
	  d = (unsigned char)map[*i] | d;
	}
      *i = (*i + 1) % MEM_SIZE;
      s--;
    }
  return ((int)d);
}

int             print_my_short(char *map, int *i, int s)
{
  short		d;
  int           is;

  is = s;
  while (s)
    {
      if (is == s)
        d = (unsigned char)map[*i];
      else
        {
          d = d << 8;
          d = (unsigned char)map[*i] | d;
        }
      *i = (*i + 1) % MEM_SIZE;
      s--;
    }
  return ((int)d);
}

int             print_my_int(char *map, int *i, int s)
{
  int		d;
  int           is;

  is = s;
  while (s)
    {
      if (is == s)
        d = (unsigned char)map[*i];
      else
        {
          d = d << 8;
          d = (unsigned char)map[*i] | d;
        }
      *i = (*i + 1) % MEM_SIZE;
      s--;
    }
  return (d);
}

void            print_my_arg_spec(char *map, int *i, int arg[], int s)
{
  if (s == 1)
    arg[0] = print_my_char(map, i, s);
  else if (s == 2)
    arg[0] = print_my_short(map, i, s);
  else if (s == 4)
    arg[0] = print_my_int(map, i, s);
  arg[1] = '\0';
}

void            print_my_arg_spec_eval(char *map, int *i, int arg[], char act)
{
  if (act == LIVE)
    print_my_arg_spec(map, i, arg, 4);
  else if (act == ZJMP)
    print_my_arg_spec(map, i, arg, IND_SIZE);
  else if (act == FORK || act == LFORK)
    print_my_arg_spec(map, i, arg, IND_SIZE);
}
