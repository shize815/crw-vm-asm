/*
** expose.c for wolf in /home/boell_g//Documents/projets/wolf
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jan 13 11:00:18 2012 guillaume boell
** Last update Tue Mar 20 16:32:05 2012 guillaume boell
*/
#include "corewar.h"
#include "minilibx/mlx.h"
#include "op.h"

int	gere_expose(t_args_events *args)
{
  refresh(args);
  mlx_put_image_to_window(args->id_aff, args->id_fenetre, args->img_ptr, 0, 0);
  return (0);
}

void	refresh(t_args_events *args)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      set_pix(args->arena->map[i] * 15, args->arena->map[i] * 15, 0, args->img_data + i * 4);
      i++;
    }
}

int	key_hook(int keycode, t_args_events *args)
{

  return (0);
}
