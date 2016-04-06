/*
** ptr_list.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Wed Apr  6 23:05:56 2016 victor sousa
** Last update Wed Apr  6 23:07:56 2016 victor sousa
*/

#include		"main.h"

t_ptr_list		*push_ptr(t_ptr_list *prev, void *ptr)
{
  t_ptr_list		*new;

  if ((new = malloc(sizeof(t_ptr_list))) == NULL)
    return (NULL);
  new->ptr = ptr;
  new->next = prev;
  return (new);
}
