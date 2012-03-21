/*
** test_fct.c for test in /home/kyndt_c/prog/crw/crw-asm
** 
** Made by clovis kyndt
** Login   <kyndt_c@epitech.net>
** 
** Started on  Tue Feb 14 13:00:49 2012 clovis kyndt
** Last update Wed Mar 21 09:41:40 2012 pierre ecormier
*/

#include        <stdio.h>
#include        "corewar.h"
#include        "my.h"

/*
**              a supprimer avant rendu!
*/

void            aff_my_nb(char *s)
{
  int           i;

  i = 0;
  while (s[i])
    {
      if (i > 0)
        printf(", %d", s[i]);
      else
        printf("%d", s[i]);
      i++;
    }
}

void            aff_my_str(char **s)
{
  int           i;

  i = 0;
  while (s[i])
    {
      if (i > 0)
        printf(", %s", s[i]);
      else
        printf("%s", s[i]);
      i++;
    }
}

void            aff_my_bin(unsigned char *s)
{
  int           i;

  i = 0;
  while (s[i])
    {
      printf("%d;", s[i]);
      i++;
    }
}


void            aff_asm_struct(t_asmline *l_asm)
{
  while (l_asm != NULL)
    {
      printf("bin: ");
      aff_my_bin(l_asm->bin);
      printf("\nsize: %d\nposition: %d\ncode: %d\n", l_asm->size, l_asm->position, l_asm->code);
      printf("type: ");
      aff_my_nb(l_asm->type);
      printf("\nargv: ");
      aff_my_str(l_asm->argv);
      printf("\n\n");
      l_asm = l_asm->next;
    }
}
