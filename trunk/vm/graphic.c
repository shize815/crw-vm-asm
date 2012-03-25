/*
** graphic.c for corewar-vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Tue Mar 20 15:27:18 2012 guillaume boell
** Last update Sun Mar 25 12:34:43 2012 guillaume boell
*/
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "corewar.h"

void		launch_game(t_arena *arena)
{
  void		*id_aff;
  void		*id_fenetre;
  char		*img_data;
  void		*img_ptr;
  int		bpp;
  int		ppl;
  int		info;
  t_args_events	args;

  if ((id_aff = mlx_init()) != NULL)
    if ((img_ptr = mlx_new_image(id_aff, LARG, LARG)) != NULL)
      if ((img_data = mlx_get_data_addr(img_ptr, &bpp, &ppl, &info)) != NULL)
	if ((id_fenetre = mlx_new_window(id_aff, LARG, LARG, "VM - Corewar")) != NULL)
	  {
	    args.id_aff = id_aff;
	    args.id_fenetre = id_fenetre;
	    args.img_data = img_data;
	    args.img_ptr = img_ptr;
	    args.arena = arena;
	    mlx_clear_window(id_aff, id_fenetre);
	    mlx_expose_hook(id_fenetre, gere_expose, &args);
	    mlx_key_hook(id_fenetre, key_hook, &args);
	    mlx_loop_hook(id_aff, do_refresh, &args);
	    mlx_loop(id_aff);
	  }
}
