/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Tue Mar 20 13:38:16 2012 clovis kyndt
*/

#ifndef			__COREWAR_H__
#define			__COREWAR_H__

#include		<stdlib.h>

#define			LIVE	1
#define			LD	2
#define			ST	3
#define			ADD	4
#define			SUB	5
#define			AND	6
#define			OR	7
#define			XOR	8
#define			ZJMP	9
#define			LDI	10
#define			STI	11
#define			FORK	12
#define			LLD	13
#define			LLDI	14
#define			LFORK	15
#define			AFF	16


typedef	struct		s_champ
{
  char			*name;
  char			*comment;
  int			num;
  int			last_live;
  int			nb_live;
  int			timer;
  char			carry;
  int			pc;
  int			r[16];
  struct s_champ	*next;
}			t_champ;

typedef	struct		s_arena
{
  t_champ		*champs;
  int			cycle_to_die;
  int			cycle_max;
  int			nb_live;
  int			nb_process;
  char			*map;
}			t_arena;

int			my_getnbr(char *s);
void			my_putchar(char c);
void			*xmalloc(size_t size);

#endif
