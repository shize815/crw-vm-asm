/*
** expose.c for wolf in /home/boell_g//Documents/projets/wolf
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jan 13 11:00:18 2012 guillaume boell
** Last update Wed Mar 21 15:15:24 2012 guillaume boell
*/
#include <math.h>
#include "corewar.h"
#include "minilibx/mlx.h"
#include "op.h"

int	gere_expose(t_args_events *args)
{
  mlx_put_image_to_window(args->id_aff, args->id_fenetre, args->img_ptr, 0, 0);
  return (0);
}

void	do_refresh(t_args_events *args)
{
  refresh(args);
  args->hero_pos.y = args->hero_pos.y + 1;
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

void	print_hero(t_args_events *args)
{
  t_col	color;

  color.r = 250;
  do_carre(args, 12,  &args->hero_pos, &color);
}

void	refresh(t_args_events *args)
{
  int	i;
  int	n;
  t_col	color;
  t_pos	pos;
  int	taille;

  i = n = 0;
  taille = LARG / sqrt(MEM_SIZE);
  args->hero_pos.y = args->hero_pos.y + 1;
  while (i < MEM_SIZE)
    {
      pos.x = (n * taille) % (LARG - taille);
      pos.y = ((i * taille) / (LARG - taille)) * taille;
      color.r = color.g = color.b = args->arena->map[i] * 15;
      if (args->arena->map[i] + 1)
	do_carre(args, taille, &pos, &color);
      i++;
      n++;
      if (LARG / taille <= n)
	n = 0;
    }
  print_hero(args);
}
int	key_hook(int keycode, t_args_events *args)
{
  printf("%d\n", keycode);
  if (keycode == LEFT)
    args->hero_pos.x = args->hero_pos.x - 10;
  if (keycode == RIGHT)
    args->hero_pos.x = args->hero_pos.x + 10;
  if (keycode == 65307)
    exit(0);
  return (0);
}
