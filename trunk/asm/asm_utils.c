/*
** asm_utils.c for corewar in /home/ecormi_p/crw-vm-asm/asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Fri Mar 23 08:43:28 2012 pierre ecormier
** Last update Fri Mar 23 08:45:26 2012 pierre ecormier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"corewar.h"
#include	"my.h"

void		fill_types(t_asmline *line, int *i)
{
  int		j;
  int		type;

  (*i)++;
  line->bin[*i] = 0;
  j = -1;
  while (++j < MAX_ARGS_NUMBER)
    {
      if (line->type[j] == T_IND || line->type[j] == T_LAB)
	type = line->type[j] == T_IND ? 3 : T_DIR;
      else
	type = line->type[j];
      line->bin[*i] |= type << ((MAX_ARGS_NUMBER - 1 - j) * 2);
    }
}

void		write_nb(t_asmline *line, int *i, int nb, int size)
{
  char		charn;
  short		shortn;
  void		*ptr;
  int		j;

  charn = (char) nb;
  shortn = (short) nb;
  if (size <= 2)
    ptr = size == 1 ? (void *) &charn : (void *) &shortn;
  else
    ptr = (void *) &nb;
  j = -1;
  while (++j < size)
    line->bin[++(*i)] = ((char *) ptr)[size - 1 - j];
}

int		arg_size(int code, int offset, int type)
{
  if (code == 9 || code == 0x0c || code == 0x0F)
    return (IND_SIZE);
  if (code == 0x02 && offset == 0 && type == T_LAB)
    return (DIR_SIZE);
  if (code == 0x0a && offset < 2 && type != T_REG)
    return (IND_SIZE);
  if (code == 0x0b && offset > 0 && type != T_REG)
    return (IND_SIZE);
  if (type == T_LAB || type == T_IND)
    return (IND_SIZE);
  if (type == T_DIR)
    return (DIR_SIZE);
  return (REG_SIZE);
}
