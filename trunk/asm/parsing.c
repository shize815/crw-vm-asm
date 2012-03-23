/*
** parsing.c for asm in /home/boell_g/crw-asm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 13 17:10:01 2012 guillaume boell
** Last update Fri Mar 23 09:26:14 2012 pierre ecormier
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"corewar.h"
#include	"my.h"

static char	get_command_id(char *command)
{
  int		i;

  i = 0;
  while (op_tab[i].code)
    {
      if (my_strcmp(command, op_tab[i].mnemonique) == 0)
	return (op_tab[i].code);
      i++;
    }
  my_putstr("Error: \"");
  my_putstr(command);
  my_putstr("\" command invalid.\n");
  exit(0);
  return (0);
}

static void	get_command_arg_type(char **words, char *types)
{
  int		i;

  i = 0;
  while (i < 4 && words[i] && words[i][0])
    {
      if (words[i][0] == 'r')
	types[i] = T_REG;
      else if (words[i][0] == DIRECT_CHAR)
	{
	  if (words[i][1] == LABEL_CHAR)
	    types[i] = T_LAB;
	  else
	    types[i] = T_DIR;
	}
      else
	types[i] = T_IND;
      i++;
    }
  while (i < 4)
    {
      types[i] = 0;
      i++;
    }
}

static void	get_command_args(char **words, char **argv)
{
  int		i;
  int		y;

  i = y = 0;
  while (i < 4 && words[i] && words[i][0])
    {
      if (words[i][0] == 'r' || words[i][0] == DIRECT_CHAR)
	words[i] = words[i] + 1;
      argv[i] = words[i];
      i++;
    }
  if (i < 4)
    argv[i] = NULL;
}

void		get_code(char **words, t_asmline *line, char **s)
{
  if (!my_strcmp(words[0], NAME_CMD_STRING))
    line->code = -2;
  else if (!my_strcmp(words[0], COMMENT_CMD_STRING))
    line->code = -3;
  else
    line->code = 0;
  *s = *s + 3;
}

int		gere_instruction(char **words, char *s, t_asmline *line)
{
  char		*lbl;

  if (words[0] && is_label(words[0]))
    {
      line->code = -1;
      lbl = my_strdup(words[0]);
      get_command_args(words, line->argv);
      line->argv[0] = lbl;
    }
  else if (words[0] && words[1])
    {
      line->code = get_command_id(words[0]);
      get_command_arg_type(words + 1, line->type);
      get_command_args(words + 1, line->argv);
    }
  else
    return (0);
  if (line->code > 0)
    verif_args(line, s);
  return (1);
}
