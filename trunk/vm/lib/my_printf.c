/*
** my_printf.c for libtiny in /home/ecormi_p/Projets/Perso/libtiny
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Thu Mar 15 14:00:07 2012 pierre ecormier
** Last update Sun Mar 25 17:40:48 2012 pierre ecormier
*/

#include	<stdarg.h>

void		my_printf(char *s, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, s);
  i = -1;
  while (s[++i])
    {
      if (s[i] == '%' && s[i + 1] == 's' && ++i)
	my_putstr(va_arg(ap, char *));
      else if (s[i] == '%' && s[i + 1] == 'd' && ++i)
	my_putnbr(va_arg(ap, int));
      else
	my_putchar(s[i] == '%' && s[++i] == 'c' ? va_arg(ap, int) : s[i]);
    }
  va_end(ap);
}
