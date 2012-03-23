/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Fri Mar 23 09:27:42 2012 pierre ecormier
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

void	get_code(char **words, t_asmline *line, char **s);
int	gere_instruction(char **words, char *s, t_asmline *line);
int	is_definition(t_asmline *line, char *s, char **words);
void	verif_args(t_asmline *line, char *s);
int	is_label(char *str);

void	fill_types(t_asmline *line, int *i);
void	write_nb(t_asmline *line, int *i, int nb, int size);
int	arg_size(int code, int offset, int type);

int	is_label(char *str);
int	write_file(t_asmline *line, char *header[2], int size, char *path);
void	write_asm(t_asmline *line, char *path);

#endif
