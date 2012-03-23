/*
** verif.c for corewar in /home/ecormi_p/crw-vm-asm/asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Fri Mar 23 09:20:36 2012 pierre ecormier
** Last update Fri Mar 23 09:27:07 2012 pierre ecormier
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"corewar.h"
#include	"my.h"

static void	aff_error(char *what_it_is, char *s, char *wrong_thing)
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

static void	verif_label(char *s)
{
  int		i;
  int		y;

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

int		is_label(char *str)
{
  int		i;

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

void		verif_args(t_asmline *line, char *s)
{
  int		nbr_arg;
  int		is_reg;

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

int		is_definition(t_asmline *line, char *s, char **words)
{
  int		i;

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
