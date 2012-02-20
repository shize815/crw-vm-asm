/*
** my_putnbr.c for allum1 in /home/ecormi_p//Projets/C Prog Elem/Allum1/cur
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Sun Feb 12 18:49:03 2012 pierre ecormier
** Last update Wed Feb 15 09:08:18 2012 pierre ecormier
*/

#include	<unistd.h>
#include	<stdio.h>

void		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    {
      if (write(2, &c, 1) == -1)
	return;
    }
}

void		my_putstr(char *s)
{
  int		i;

  i = -1;
  while (s[++i]);
  if (write(1, s, i) == -1)
    {
      if (write(2, s, i) == -1)
	return;
    }
}

int		my_putnbr(int nb)
{
  my_putchar(nb < 0 && (nb *= -1) ? '-' : '\0');
  my_putchar(nb - (nb >= 10 ? my_putnbr(nb / 10) : 0) + 48);
  return (nb * 10);
}

int		my_getnbr(char *s)
{
  int		sign;
  int		nb;
  int		i;

  if (s == NULL)
    return (0);
  sign = 1;
  nb = 0;
  i = -1;
  while (s[++i] && (s[i] == '-' || s[i] == '+'))
    sign *= s[i] == '-' ? -1 : 1;
  i--;
  while (s[++i] >= '0' && s[i] <= '9')
    nb = nb * 10 - 48 + s[i];
  return (nb * sign);
}
