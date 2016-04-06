/*
** xmalloc.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Wed Apr  6 23:01:47 2016 victor sousa
** Last update Thu Apr  7 00:22:56 2016 victor sousa
*/

#include		"main.h"

void			*xmalloc(int size, t_ptr_list **ptr_list)
{
  void			*ptr;

  if ((ptr = malloc(size)) == NULL)
    write(2, "Impossible to allocate Memory\n", 30);
  if (((*ptr_list) = push_ptr(*ptr_list, ptr)) == NULL)
    return (NULL);
  return (ptr);
}
