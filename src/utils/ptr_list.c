/*
** ptr_list.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Wed Apr  6 23:05:56 2016 victor sousa
** Last update Thu Apr  7 02:14:10 2016 victor sousa
*/

#include		"main.h"

int			push_ptr(t_ptr_list **head, void *ptr)
{
  t_ptr_list		*new;
  t_ptr_list		*tmp;

  if ((new = malloc(sizeof(t_ptr_list))) == NULL)
    {
      write(2, "Impossible to allocate Memory\n", 30);
      return (ERROR);
    }
  new->ptr = ptr;
  new->next = NULL;
  if (*head == NULL)
    {
      *head = new;
      return (SUCCESS);
    }
  tmp = *head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (SUCCESS);
}

void			free_ptr(t_ptr_list *ptr_list)
{
  t_ptr_list		*tmp;

  while (ptr_list != NULL)
    {
      tmp = ptr_list;
      ptr_list = ptr_list->next;
      free(tmp->ptr);
      free(tmp);
    }
}
