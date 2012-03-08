/*
** my.h for my in /home/ecormi_p//afs/rendu/include
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Thu Oct 13 10:47:23 2011 pierre ecormier
** Last update Thu Mar  8 17:08:22 2012 pierre ecormier
*/

#ifndef	__MY_H__
#define	__MY_H__

#include	"corewar.h"
#include	"op.h"

#define	ISNUM(x)	((x) >= '0' && (x) <= '9')
#define	ISHMAX(x)	((x) >= 'A' && (x) <= 'F')
#define	ISHMIN(x)	((x) >= 'a' && (x) <= 'f')
#define	ISHEX(x)	(ISNUM(x) || ISHMAX(x) || ISHMIN(x))
#define	HEX_TO_DEC(x)	(ISNUM(x) ? (x) - 48 : (ISHMIN(x) ? (x) - 87 : (x) - 55))
#define	IS_SIGN(x)	((x) == '-' || (x) == '+')
#define	IS_SPACE(x)	((x) == ' ' || (x) == '\t' || (x) == SEPARATOR_CHAR)

#define	BUFF_SIZE	1024

typedef	struct	s_char
{
  char		*str;
  char		*to_free;
  int		len;
  struct s_char	*next;
}		t_char;

void	my_putchar(char c);
void	my_putstr(char *s);
int	my_putnbr(int nb);
int	my_getnbr(char *s);

char	*my_strdup(char *s);
int	my_strlen(char *s);
int	my_tablen(char **tab);
int	my_strcmp(char *s1, char *s2);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab(char *str);
int	my_push_back(t_char **end, char *str, int len);
int	get_word(char *str, char **dest);

#endif
