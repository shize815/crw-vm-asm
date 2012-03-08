/*
** get_next_line.c for get_next_line in /home/ecormi_p//Projets/GetNextLine
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Mon Nov  7 07:40:39 2011 pierre ecormier
** Last update Thu Mar  8 17:04:41 2012 pierre ecormier
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

int		get_line_length(t_char *begin)
{
  int		size;
  int		i;

  if (begin == NULL)
    return (0);
  size = 0;
  while (begin->next != NULL)
    {
      size += begin->len;
      begin = begin->next;
    }
  i = -1;
  while (begin->str[++i] && begin->str[i] != '\n')
    size++;
  if (begin->str[i] != '\n')
    return (-size);
  return (size);
}

void		free_and_next(t_char **begin, t_char **end)
{
  t_char	*old;

  old = *begin;
  *begin = (*begin)->next;
  if (old == *end)
    *end = NULL;
  free(old->to_free);
  free(old);
}

char		*list_to_string(t_char **begin, t_char **end, int size)
{
  char		*str;
  int		i;
  int		j;

  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while ((*begin) != NULL && j < size)
    {
      j = -1;
      while ((*begin)->str[++j] && (*begin)->str[j] != '\n')
	str[++i] = (*begin)->str[j];
      if ((*begin)->str[j] == '\n')
	{
	  (*begin)->str += j + 1;
	  (*begin)->len -= j + 1;
	  j = size;
	}
      else
	free_and_next(begin, end);
    }
  str[++i] = '\0';
  return (str);
}

void		fill_list(int fd, t_char **begin, t_char **end)
{
  char		*buff;
  int		stop;
  int		ret;
  int		i;

  stop = 0;
  if ((buff = malloc(BUFF_SIZE + 1)) == NULL)
    exit(1);
  while (!stop && (ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
      i = -1;
      while (!stop && ++i < ret)
	{
	  if (buff[i] == '\n')
	    stop = 1;
	}
      buff[ret] = '\0';
      my_push_back(end, buff, ret);
      if (*begin == NULL)
	*begin = *end;
      if (!stop && (buff = malloc(BUFF_SIZE + 1)) == NULL)
	exit(1);
    }
  if (!stop)
    free(buff);
}

char		*get_next_line(const int fd)
{
  static t_char	*begin;
  static t_char	*end;
  char		*line;
  int		size;

  if (begin == NULL || (size = get_line_length(begin)) <= 0)
    fill_list(fd, &begin, &end);
  size = get_line_length(begin);
  if (size == 0 && begin == NULL)
    {
      if (begin != NULL)
	{
	  free(begin->to_free);
	  free(begin);
	}
      return (NULL);
    }
  if (size < 0)
    size = -size;
  line = list_to_string(&begin, &end, size);
  return (line);
}
