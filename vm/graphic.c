/*
** graphic.c for corewar-vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Tue Mar 20 15:27:18 2012 guillaume boell
** Last update Tue Mar 20 16:21:57 2012 guillaume boell
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
  t_args_events	args_events;

  img_data = NULL;
  if ((id_aff = mlx_init()) != NULL)
    if ((img_ptr = mlx_new_image(id_aff, LARG, HAUT)) != NULL)
      if ((img_data = mlx_get_data_addr(img_ptr, &bpp, &ppl, &info)) != NULL)
	if ((id_fenetre = mlx_new_window(id_aff, LARG, HAUT, "VM - Corewar")) != NULL)
	  {
	    args_events.id_aff = id_aff;
	    args_events.id_fenetre = id_fenetre;
	    args_events.img_data = img_data;
	    args_events.img_ptr = img_ptr;
	    args_events.arena = arena;
	    mlx_clear_window(id_aff, id_fenetre);
	    mlx_expose_hook(id_fenetre, gere_expose, &args_events);
	    mlx_key_hook(id_fenetre, key_hook, &args_events);
	    mlx_loop(id_aff);
	  }
}
