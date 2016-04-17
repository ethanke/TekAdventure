/*
** get_decors_break.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 03:36:50 2016 Gaëtan Léandre
** Last update Sun Apr 17 05:29:34 2016 Gaëtan Léandre
*/

#include		"main.h"

int			get_dec_collect(char *msg, t_ini *ini)
{
  char			*str;

  (void)ini;
  my_printf(1, msg);
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n : ");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (my_strcmp(str, "yes") == 0)
    return (1);
  return (0);
}

int			get_object(char *msg, t_ini *ini)
{
  t_object		*tmp;
  char			*str;
  int			id;

  my_printf(1, msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr_free(str);
      tmp = ini->scene->object;
      while (tmp != NULL)
	{
	  if (tmp->object_id == id)
	    return (id);
	  tmp = tmp->next;
	}
      my_printf(1, "no item with that id\nTry again : ");
    }
  return (0);
}

int			get_id_posi(char *msg, t_ini *ini)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr_free(str);
      if (id > 0)
	return (id);
      my_printf(1, "Id must be superior to 0\nTry again : ");
    }
  return (0);
}
