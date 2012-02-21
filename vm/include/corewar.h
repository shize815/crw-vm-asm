/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Tue Feb 21 16:16:04 2012 guillaume boell
*/

#ifndef	__COREWAR_H__
#define	__COREWAR_H__

#include <stdlib.h>

typedef	struct		s_champ
{
  char			*name;
  char			*comment;
  int			num;
  int			last_live;
  int			nb_live;
  int			timer;
  int			pc;
  int			r[16];
  struct s_champ	*next;
}			t_champ;

typedef	struct		s_arena
{
  t_champ		*champs;
  int			cycle_to_die;
  int			nb_live;
  int			nb_process;
  char			*map;
}			t_arena;

int	my_getnbr(char *s);
void	*xmalloc(size_t size);

#endif
