/*
** main.c for corewar in /home/ecormi_p//Projets/C Prog Elem/Corewar
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 15:22:42 2012 pierre ecormier
** Last update Fri Mar 23 09:23:55 2012 pierre ecormier
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"corewar.h"

static int	parse_line(char *s, t_asmline *line, int ignore_flag)
{
  char		**words;
  int		i;

  i = -1;
  while (s[++i])
    if (s[i] == COMMENT_CHAR || s[i] == ';')
      s[i--] = '\0';
  words = my_str_to_wordtab(s);
  if (ignore_flag)
    words = words + 1;
  if (words[0] && !is_definition(line, s, words))
    {
      if (!gere_instruction(words, s, line))
	return (0);
    }
  else if (!words || !words[0])
    return (0);
  return (1);
}

static int	asm_loop(int fd, t_asmline **op_start, t_asmline **op_end)
{
  char		*s;
  t_asmline	*current_op;

  while ((s = get_next_line(fd)))
    {
      if ((current_op = malloc(sizeof(t_asmline))) == NULL)
	return (1);
      if (parse_line(s, current_op, 0))
	{
	  push_asm_back(op_start, op_end, current_op);
	  if (current_op->code == -1 && current_op->argv[1])
	    {
	      if ((current_op = malloc(sizeof(t_asmline))) == NULL)
		return (1);
	      parse_line(s, current_op, 1);
	      push_asm_back(op_start, op_end, current_op);
	    }
	}
      else
	free(current_op);
    }
  return (0);
}

static void	convert_file(char *path)
{
  int		fd;
  t_asmline	*op_start;
  t_asmline	*op_end;

  op_start = op_end = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    return;
  if (asm_loop(fd, &op_start, &op_end))
    return;
  close(fd);
  write_asm(op_start, path);
}

int		main(int argc, char **argv)
{
  int		i;

  i = 0;
  while (++i < argc)
    convert_file(argv[i]);
  return (0);
}
