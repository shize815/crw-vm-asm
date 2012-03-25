/*
** corewar.h for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Feb 13 16:32:13 2012 pierre ecormier
** Last update Sun Mar 25 18:23:47 2012 clovis kyndt
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
  char			last_name[80];
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
  char			*img_data;
  t_arena		*arena;
}			t_args_events;

int			my_getnbr(char *s);
void			my_putchar(char c);
void			set_pix(char r, char g, char b, char *img_data);
void			*xmalloc(size_t size);
int			gere_expose(t_args_events *args);
int			key_hook(int keycode, t_args_events *args);
int			do_refresh(t_args_events *args);

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

/*                      FILE:   init_vm.c    */
int			init_bc_vm(t_arena *arena);

/*			FILE:	kill_champ.c		*/
void			kill_champ(t_arena *arena);

/*			FILE:	print_commun.c		*/
void			print_my_arg(char *map, int *i, int arg[], char nb, char type[]);

/*                      FILE:	print_special.c		*/
int			print_my_char(char *map, int *i, int s);
int			print_my_short(char *map, int *i, int s);
int			print_my_int(char *map, int *i, int s);
void			print_my_arg_spec(char *map, int *i, int arg[], int s);
void			print_my_arg_spec_eval(char *map, int *i, int arg[], char act);

/*                      FILE:	print_commun.c          */
char			select_oct(char tb[], unsigned char c);
void			type_exep(char c, char type[]);
void			type_exp(char c, char type[]);

/*                      FILE:   slct_kill.c          */
int			kill_elm_list(t_champ *champs);

/*                      FILE:   win_champ.c          */
void			aff_rendu(t_arena *arena);

void			my_putbin(char c);
void			my_putstr(char *str);
int			get_arg_nbr(char c, char **argv, int wait_until);
void			rempl_tabl(int *tab, char c, char **argv);
t_champ			*gen_champs(t_champ *start, int *tab, char **argv);
void			launch_game(t_arena *arena);
void			refresh(t_args_events *args);
void			do_carre(t_args_events *args, int taille, t_pos *pos, t_col *color);

#endif
