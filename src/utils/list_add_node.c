/*
** list_add_node.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/list/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Tue Mar 29 20:05:23 2016 Philippe Lefevre
** Last update Fri Apr 15 22:57:27 2016 Ethan Kerdelhue
*/

#include		"my_list.h"

t_list			*list_add_node(t_list *list, void *data)
{
  t_list		*new;
  t_list		*tmp;

  if ((new = list_create_node(data)) != NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}
