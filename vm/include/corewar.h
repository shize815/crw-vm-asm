/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Sun Feb 19 20:06:18 2012 pierre ecormier
*/

#ifndef	__COREWAR_H__
#define	__COREWAR_H__

#include "op.h"

typedef	struct		s_asmline
{
  unsigned char		bin[20];
  int			size;
  char			code;
  char			type[MAX_ARGS_NUMBER];
  char			*argv[MAX_ARGS_NUMBER];
  struct s_asmline	*next;
}			t_asmline;

int	is_label(char *str);
int	write_file(t_asmline *line, char *header[2], int size, char *path);
int	write_asm(t_asmline *line, char *path);
int	parse_line(char *s, t_asmline *line, int ignore_flag);

#endif
