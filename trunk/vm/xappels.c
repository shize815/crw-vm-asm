/*
** xappels.c for vm in /home/boell_g/crw-vm-asm/vm
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Tue Feb 21 15:27:24 2012 guillaume boell
** Last update Tue Feb 21 15:29:32 2012 guillaume boell
*/
#include <stdlib.h>

void	*xmalloc(size_t size)
{
  void	*ret;

  ret = malloc(size);
  return (ret);
}
