/*
** write_asm.c for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 17:21:11 2012 pierre ecormier
** Last update Wed Mar 21 10:30:29 2012 pierre ecormier
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
  if (code == 9)
    return (IND_SIZE);
  if (code == 0x0b && offset > 0 && type != T_REG)
    return (IND_SIZE);
  if (code == 0x02 && offset == 0 && type == T_LAB)
    return (DIR_SIZE);
  if (code == 0x0a && offset < 2 && type != T_REG)
    return (IND_SIZE);
  if (type == T_LAB || type == T_IND)
    return (IND_SIZE);
  if (type == T_DIR)
    return (DIR_SIZE);
  return (1);
}

int		replace_labels(t_asmline *line, t_asmline *lbls)
{
  t_asmline	*it;
  int		i;
  int		offset;
  int		lsize;

  offset = 0;
  while (line != NULL)
    {
      if (line->code > 0)
	{
	  i = -1;
	  if (line->code != 1 && line->code != 9 && line->code != 12 && line->code != 15)
	    lsize = 1;
	  else
	    lsize = 0;
	  while (++i < 4 && line->type[i] != 0)
	    {
	      if (line->type[i] == T_LAB)
		{
		  it = lbls;
		  while (it && my_strcmp(line->argv[i] + 1, it->argv[0]))
		    it = it->next;
		  if (it)
		    write_nb(line, &lsize, it->size - offset, arg_size(line->code, i, line->type[i]));
		  else
		    lsize += arg_size(line->code, i, line->type[i]);
		}
	      else
		lsize += arg_size(line->code, i, line->type[i]);
	    }
	  offset += line->size + 1;
	}
      line = line->next;
    }
  return (0);
}

int		write_asm(t_asmline *line, char *path)
{
  char		*header[2];
  t_asmline	*begin;
  t_asmline	*next;
  t_asmline	*lbls;
  int		size;
  int		pos;
  int		i;

  header[0] = header[1] = NULL;
  pos = 0;
  lbls = NULL;
  begin = line;
  while (line)
    {
      line->size = -1;
      next = line->next;
      if (line->code == -1)
	{
	  replace_asm_list(&begin, &lbls, line);
	  line->size = pos;
	}
      else if (line->code == -2 || line->code == -3)
	header[line->code + 3] = line->argv[0];
      else
	{
	  line->size = -1;
	  line->bin[++(line->size)] = line->code;
	  if (line->code != 1 && line->code != 9 && line->code != 12 && line->code != 15)
	    fill_types(line, &(line->size));
	  i = -1;
	  while (++i < MAX_ARGS_NUMBER && line->type[i] != 0)
	    {
	      size = arg_size(line->code, i, line->type[i]);
	      write_nb(line, &(line->size), my_getnbr(line->argv[i]), size);
	    }
	  pos += line->size + 1;
	}
      line = next;
    }
  replace_labels(begin, lbls);
  write_file(begin, header, pos, path);
  return (0);
}
