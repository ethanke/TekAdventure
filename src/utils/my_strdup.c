/*
** my_strdup.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 02:54:15 2016 Ethan Kerdelhue
** Last update Thu Apr  7 03:00:29 2016 Ethan Kerdelhue
*/

#include	"main.h"

char		*my_strdup(char *str, t_ptr_list *ptr_list)
{
  int		i;
  char		*new;

  i = 0;
  if ((new = xmalloc(my_strlen(str), &ptr_list)) == NULL)
      return (NULL);
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}
