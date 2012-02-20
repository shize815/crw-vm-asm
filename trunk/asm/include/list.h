/*
** list.h for manager in /home/ecormi_p//Projets/Perso/winmanager
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Thu Feb  9 18:36:46 2012 pierre ecormier
** Last update Mon Feb 13 14:33:47 2012 pierre ecormier
*/

#ifndef	__LIST_H__
#define	__LIST_H__

#include	<X11/Xlib.h>

typedef	struct	s_list
{
  Window	win;
  struct s_list	*next;
}		t_list;

typedef	struct	s_name
{
  char		*name;
  struct s_name	*next;
}		t_name;

void		load_conf(t_name **begin);
void		push_front(t_list **begin, Window win);
void		push_name_front(t_name **begin, char *name);

#endif
