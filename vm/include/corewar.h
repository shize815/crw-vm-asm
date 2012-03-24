/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Sat Mar 24 19:25:12 2012 pierre ecormier
*/

#ifndef			__COREWAR_H__
#define			__COREWAR_H__

#include		<stdlib.h>
#include		<stdio.h>  /* A SUPP !!!!*/
#include		<string.h> /* A SUPP !!!!*/

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
  int			parent;
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
  unsigned char		*map;
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

/***			DIR:	vm_apply	        */
/*			FILE:	count_champs.c		*/
int			champ_count(t_champ *champ);

/*                      FILE:	home_vm.c		*/
int			dedi_no_tab(t_champ *champ, t_arena *arena, int *i, char index,
				    void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), unsigned char act);
int			cycle_action(t_arena *arena,
				     void (*act_fct[16])(t_arena *arena, t_champ *champ, char type[4], int argv[4]), int cycle);
void			home_vm(t_arena *arena, t_args_events *args);

/*			FILE:	initialisation_app.c	*/
void			init_time_tab(int time_tab[]);
int			time_action(char c);
int			decript_type(char c);
void			init_fct_tab(void  (*act_fct[])(t_arena *arena, t_champ *champ, char type[4], int argv[4]));
void			init_live(t_champ *champ);

/*			FILE:	kill_champ.c		*/
t_champ			*kill_my_select_champ(t_champ *champs);
void			kill_champ(t_arena *arena);

/*			FILE:	print_commun.c		*/
void			print_my_arg(char *map, int *i, int arg[], char nb, char type[]);

/*                      FILE:	print_special.c		*/
void			print_my_arg_spec(char *map, int *i, int arg[], int s);
void			print_my_arg_spec_eval(char *map, int *i, int arg[], char act);

/*                      FILE:	print_commun.c          */
char			select_oct(char tb[], unsigned char c);
void			type_exp(char c, char type[]);

#endif
