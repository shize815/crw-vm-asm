/*
** graphic.c for corewar-vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Tue Mar 20 15:27:18 2012 guillaume boell
** Last update Sun Mar 25 16:15:36 2012 guillaume boell
*/
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "corewar.h"

void		launch_game(t_arena *arena)
{
  void		*id_aff;
  void		*id_fen;
  char		*img_data;
  void		*img_ptr;
  int		bpp;
  int		ppl;
  int		info;
  t_args_events	args;

  if ((id_aff = mlx_init()) != NULL)
    if ((img_ptr = mlx_new_image(id_aff, LARG, LARG)) != NULL)
      if ((img_data = mlx_get_data_addr(img_ptr, &bpp, &ppl, &info)) != NULL)
	if ((id_fen = mlx_new_window(id_aff, LARG, LARG, "VM - Corewar")) != NULL)
	  {
	    args.id_aff = id_aff;
	    args.id_fenetre = id_fen;
	    args.img_data = img_data;
	    args.img_ptr = img_ptr;
	    args.arena = arena;
	    mlx_clear_window(id_aff, id_fen);
	    mlx_expose_hook(id_fen, gere_expose, &args);
	    mlx_key_hook(id_fen, key_hook, &args);
	    mlx_loop_hook(id_aff, do_refresh, &args);
	    mlx_loop(id_aff);
	  }
}

void	do_refresh(t_args_events *args)
{
  refresh(args);
  mlx_put_image_to_window(args->id_aff, args->id_fenetre, args->img_ptr, 0, 0);
}

void	do_carre(t_args_events *args, int taille, t_pos *pos, t_col *color)
{
  char	*i;
  int	c_x;
  int	c_y;

  i = args->img_data + ((pos->x + (pos->y * LARG)) * 4);
  c_x = c_y = 0;
  while (c_y < taille)
    {
      while (c_x < taille)
	{
	  set_pix(color->r, color->g, color->b, i + ((c_x + (c_y * LARG)) * 4));
	  c_x++;
	}
      c_x = 0;
      c_y++;
    }
}
