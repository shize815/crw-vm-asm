/*
** write_asm.c for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 17:21:11 2012 pierre ecormier
** Last update Fri Mar 23 08:47:07 2012 pierre ecormier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"corewar.h"
#include	"my.h"

static void	labels_loop(t_asmline *line, t_asmline *lbls,
			    int i[3], int *lsize)
{
  t_asmline	*it;

  while (++i[0] < 4 && line->type[*i] != 0)
    {
      i[1] = arg_size(line->code, *i, line->type[*i]);
      if (line->type[*i] == T_LAB || line->argv[*i][0] == LABEL_CHAR)
	{
	  it = lbls;
	  while (it && my_strcmp(line->argv[*i] + 1, it->argv[0]))
	    it = it->next;
	  if (it)
	    write_nb(line, lsize, it->size - i[2], i[1]);
	  else
	    *lsize += i[1];
	}
      else
	*lsize += i[1];
    }
}

static int	replace_labels(t_asmline *line, t_asmline *lbls)
{
  int		i[3];
  int		lsize;

  i[2] = 0;
  while (line != NULL)
    {
      if (line->code > 0)
	{
	  *i = -1;
	  lsize = (line->code != 1 && line->code != 9 &&
		   line->code != 12 && line->code != 15);
	  labels_loop(line, lbls, i, &lsize);
	  i[2] += line->size + 1;
	}
      line = line->next;
    }
  return (0);
}

static void	treat_asm(t_asmline *line, char *header[2],
			  t_asmline *asms[3], int *pos)
{
  int		i;

  if (line->code == -1)
    {
      replace_asm_list(asms, &asms[2], line);
      line->size = *pos;
    }
  else if (line->code == -2 || line->code == -3)
    header[line->code + 3] = line->argv[0];
  else
    {
      line->size = -1;
      line->bin[++(line->size)] = line->code;
      if (line->code != 1 && line->code != 9 &&
	  line->code != 12 && line->code != 15)
	fill_types(line, &(line->size));
      i = -1;
      while (++i < MAX_ARGS_NUMBER && line->type[i] != 0)
	write_nb(line, &(line->size), my_getnbr(line->argv[i]),
		 arg_size(line->code, i, line->type[i]));
      *pos += line->size + 1;
    }
}

void		write_asm(t_asmline *line, char *path)
{
  char		*header[2];
  t_asmline	*asms[3];
  int		pos;

  header[0] = header[1] = NULL;
  asms[2] = NULL;
  pos = 0;
  *asms = line;
  while (line)
    {
      line->size = -1;
      asms[1] = line->next;
      treat_asm(line, header, asms, &pos);
      line = asms[1];
    }
  replace_labels(*asms, asms[2]);
  write_file(*asms, header, pos, path);
}
