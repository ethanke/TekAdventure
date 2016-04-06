/*
** list_create_node.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/list/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Tue Mar 29 19:43:31 2016 Philippe Lefevre
** Last update Thu Apr  7 01:02:45 2016 Philippe Lefevre
*/

#include		"my_list.h"

t_list			*list_create_node(void *data)
{
  t_list		*list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return (NULL);
  list->data = data;
  list->prev = NULL;
  list->next = NULL;
  return (list);
}
