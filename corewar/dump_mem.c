/*
** dump_mem.c for corewar in /home/ecormi_p/crw-vm-asm/corewar
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Sun Mar 25 22:16:17 2012 pierre ecormier
** Last update Sun Mar 25 22:32:09 2012 pierre ecormier
*/

#include	"my.h"
#include	"op.h"

void		dump_mem(char *mem)
{
  int		i;
  int		j;

  i = -32;
  while ((i += 32) < MEM_SIZE)
    {
      j = -1;
      while (++j < 32 && i + j < MEM_SIZE)
	{
	  if (j != 0)
	    my_putchar(' ');
	  my_putchar("0123456789ABCDEF"[(mem[i + j] >> 4) & 0xF]);
	  my_putchar("0123456789ABCDEF"[mem[i + j] & 0xF]);
	}
      my_putchar('\n');
    }
  exit(EXIT_SUCCESS);
}
