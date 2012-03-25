/*
** draw_line_custom.c for wolf3D in /home/boell_g/Documents/projets/wolf
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Wed Dec 21 21:32:49 2011 guillaume boell
** Last update Fri Mar 23 17:10:19 2012 guillaume boell
*/
void	set_pix(char r, char g, char b, char *img_data)
{
  img_data[0] = b;
  img_data[1] = g;
  img_data[2] = r;
}
