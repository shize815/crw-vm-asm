/*
** parsing.c for asm in /home/boell_g/crw-asm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Feb 13 17:10:01 2012 guillaume boell
** Last update Thu Mar 22 12:55:59 2012 pierre ecormier
*/

#include <stdio.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

char	get_command_id(char *command)
{
  int	i;

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

void	get_command_arg_type(char **words, char *types)
{
  int	i;

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

void	get_command_args(char **words, char **argv)
{
  int	i;
  int	y;

  i = y = 0;
  while (i < 4 && words[i] && words[i][0])
    {
      /* if (words[i][0] == LABEL_CHAR) */
      /* 	words[i] = words[i] + 1; */
      /* else  */if (words[i][0] == 'r' || words[i][0] == DIRECT_CHAR)
	words[i] = words[i] + 1;
      argv[i] = words[i];
      i++;
    }
  if (i < 4)
    argv[i] = NULL;
}

void	get_code(char **words, t_asmline *line, char **s)
{
  if (!my_strcmp(words[0], NAME_CMD_STRING))
    line->code = -2;
  else if (!my_strcmp(words[0], COMMENT_CMD_STRING))
    line->code = -3;
  else
    line->code = 0;
  *s = *s + 3;
}

int	is_definition(t_asmline *line, char *s, char **words)
{
  int	i;

  get_code(words, line, &s);
  if (line->code != 0)
    {
      while (*s && *(s - 1) != '\"')
	s++;
      line->argv[0] = malloc(my_strlen(s) + 1);
      if (!line->argv[0])
	exit (0);
      i = 0;
      while (*s && *s != '\"')
	{
	  line->argv[0][i] = *s;
	  s++;
	  i++;
	}
      line->argv[0][i] = 0;
      line->argv[1] = NULL;
      return (1);
    }
  return (0);
}

void	aff_error(char *what_it_is, char *s, char *wrong_thing)
{
  my_putstr("Error: Wrong ");
  my_putstr(what_it_is);
  my_putstr(" for \"");
  my_putstr(wrong_thing);
  my_putstr("\" @ line below :\n");
  my_putstr(s);
  my_putchar('\n');
  exit(0);
}

void	verif_label(char *s)
{
  int	i;
  int	y;

  i = y = 0;
  while (s[i] && s[i] != ':')
    {
      if (i == 0 && (ISNUM(s[i])))
	aff_error("label (number as first char)", s, s + i);
      while (LABEL_CHARS[y] && LABEL_CHARS[y] != s[i])
	y++;
      if (!LABEL_CHARS[y])
	aff_error("label (invalid char)", s, s + i);
      y = 0;
      i++;
    }
  if (s[i] == 0 || s[i + 1] != 0)
    aff_error("label (char after \':\')", s, s + i);
  if (i == 0)
    aff_error("label (no name)", s, s);
}

int	is_label(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == LABEL_CHAR)
	{
	  verif_label(str);
	  return (1);
	}
      i++;
    }
  return (0);
}

void	verif_args(t_asmline *line, char *s)
{
  int	nbr_arg;
  int	is_reg;

  if (line->code > 0)
    {
      nbr_arg = 0;
      while (nbr_arg <= 3 && line->argv[nbr_arg])
	nbr_arg++;
      if (op_tab[line->code - 1].nbr_args != nbr_arg)
	aff_error("number of arguments", s, op_tab[line->code - 1].mnemonique);
      nbr_arg = 0;
      while (nbr_arg <= 3 && line->argv[nbr_arg])
	{
	  is_reg = 0;
	  if ((line->type[nbr_arg] & T_LAB) > 0)
	    {
	      is_reg = 1;
	      line->type[nbr_arg] = T_DIR;
	    }
	  if ((op_tab[line->code - 1].type[nbr_arg] & line->type[nbr_arg]) == 0)
	    aff_error("type of argument", s, line->argv[nbr_arg]);
	  if (is_reg)
	    line->type[nbr_arg] = T_LAB;
	  nbr_arg++;
	}
    }
}

int	gere_instruction(char **words, char *s, t_asmline *line)
{
  char	*lbl;

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
  verif_args(line, s);
  return (1);
}

int	parse_line(char *s, t_asmline *line, int ignore_flag)
{
  char	**words;
  int	i;

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
