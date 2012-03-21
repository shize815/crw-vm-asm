/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Wed Mar 21 16:01:25 2012 clovis kyndt
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
#define			LARG	1000
#define			LEFT	65361
#define			RIGHT	65363
#define			HERO_H	12

typedef	struct		s_champ
{
  char			*name;
  char			*comment;
  int			num;
  int			last_live;
  int			nb_live;
  int			timer;
  int			cycle;
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

typedef struct          s_pos
{
  int			x;
  int			y;
}                       t_pos;

typedef struct          s_col
{
  char			r;
  char			g;
  char			b;
}                       t_col;

typedef	struct		s_args_events
{
  void			*id_aff;
  void			*id_fenetre;
  void			*img_ptr;
  t_pos			hero_pos;
  t_col			hero_color;
  char			*img_data;
  t_arena		*arena;
}			t_args_events;

int			my_getnbr(char *s);
void			my_putchar(char c);
void			set_pix(char r, char g, char b, char *img_data);
void			*xmalloc(size_t size);
int			gere_expose(t_args_events *args);
int			key_hook(int keycode, t_args_events *args);
void			do_refresh(t_args_events *args);

#endif
