/*
** write_to_file.c for corewar in /home/ecormi_p//crw-asm
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Wed Feb 15 11:15:45 2012 pierre ecormier
** Last update Wed Mar 21 10:15:52 2012 pierre ecormier
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"corewar.h"
#include	"my.h"

char		*get_path(char *old)
{
  int		len;
  int		i;
  char		*new;

  len = my_strlen(old);
  if (len >= 2 && old[len - 1] == 's' && old[len - 2] == '.')
    old[len - 2] = '\0';
  if ((new = malloc(my_strlen(old) + 5)) == NULL)
    return (NULL);
  len = -1;
  while (old[++len])
    new[len] = old[len];
  i = -1;
  while (++i < 5)
    new[i + len] = ".cor"[i];
  return (new);
}

void		write_header(char *header[2], int size, int fd)
{
  int		i;
  char		c;

  write(fd, "\0\xea\x83\xf3", 4);
  i = -1;
  while (header[1] && ++i < 132 && header[1][i] != '\0');
  if (header[1])
    write(fd, header[1], i);
  while (i++ < 132)
    write(fd, "", 1);
  i = -1;
  while (++i < 4)
    {
      c = ((char *) &size)[3 - i];
      write(fd, &c, 1);
    }
  i = -1;
  while (header[0] && ++i < 2050 && header[0][i] != '\0');
  if (header[0])
    write(fd, header[0], i);
  while (i++ < 2050)
    write(fd, "", 1);
}

int		write_file(t_asmline *line, char *header[2], int size, char *path)
{
  t_asmline	*next;
  int		fd;
  char		*dest;

  if ((dest = get_path(path)) == NULL)
    return (1);
  if ((fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (1);
  write_header(header, size, fd);
  while (line)
    {
      if (write(fd, line->bin, line->size) == -1)
	my_putstr("Write error\n");
      line = line->next;
    }
  free(dest);
  close(fd);
  while (line)
    {
      next = line->next;
      free(line);
      line = next;
    }
  return (0);
}
