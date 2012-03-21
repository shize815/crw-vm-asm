/*
** main.c for corewar in /home/ecormi_p//Projets/C Prog Elem/Corewar
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 15:22:42 2012 pierre ecormier
** Last update Wed Mar 21 08:25:36 2012 pierre ecormier
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"corewar.h"

int		convert_file(char *path)
{
  int		fd;
  char		*s;
  t_asmline	*op_start;
  t_asmline	*op_end;
  t_asmline	*current_op;

  op_start = op_end = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    return (1);
  get_next_line(-1);
  while ((s = get_next_line(fd)))
    {
      if ((current_op = malloc(sizeof(t_asmline))) == NULL)
	return (1);
      if (parse_line(s, current_op, 0))
	{
	  push_asm_back(&op_start, &op_end, current_op);
	  if (current_op->code == -1 && current_op->argv[1])
	    {
	      if ((current_op = malloc(sizeof(t_asmline))) == NULL)
		return (1);
	      parse_line(s, current_op, 1);
	      push_asm_back(&op_start, &op_end, current_op);
	    }
	}
      else
	free(current_op);
    }
  close(fd);
  write_asm(op_start, path);
  return (0);
}

int		main(int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    convert_file(argv[i]);
  return (0);
}
