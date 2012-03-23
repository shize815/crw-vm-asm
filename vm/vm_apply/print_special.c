/*
** print_special.c for print_special in /home/kyndt/crw-vm-asm/vm/vm_apply
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Thu Mar 22 21:58:18 2012 clovis kyndt
** Last update Fri Mar 23 15:24:37 2012 clovis kyndt
*/

#include        "op.h"
#include        "corewar.h"
#include        "vm_funcs.h"

void            print_my_arg_spec(char *map, int *i, int arg[], int s)
{
  int           is;
  int		n;
  short         oct_2;
  int		u;
  short		y;
  char		d;

  is = s;
  n = 0;
  if (s == 1)
    {
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
      arg[n] = (int)d;
    }
  else if (s == 2)
    {
      while (s)
	{
	  if (is == s)
	    y = (unsigned char)map[*i];
	  else
	    {
	      y = y << 8;
	      y = (unsigned char)map[*i] | y;
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
	    u = (unsigned char)map[*i];
	  else
	    {
	      u = u << 8;
	      u = (unsigned char)map[*i] | u;
	    }
	  *i = (*i + 1) % MEM_SIZE;
	  s--;
	}
      arg[n] = u;
    }
  /* printf("\t ARG[d0] : %d\n\n", arg[0]);*/
  arg[1] = '\0';
}

void            print_my_arg_spec_eval(char *map, int *i, int arg[], char act)
{
  if (act == LIVE)
    print_my_arg_spec(map, i, arg, 4);
  else if (act == ZJMP)
    {
      /*      printf("ZJMP >> i:%d\n", *i);*/
      print_my_arg_spec(map, i, arg, IND_SIZE);
    }
  else if (act == FORK || act == LFORK)
    print_my_arg_spec(map, i, arg, IND_SIZE);
}
