/*
** write_object4.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 10:10:36 2016 Gaëtan Léandre
** Last update Sat Apr 16 10:25:44 2016 Victor Sousa
*/

#include		"main.h"

void			write_object_agility(t_object *object, int fd,
					      int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_agility=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->agility);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->agility);
      tmp = tmp->next;
      i++;
    }
}
void			write_object_armor(t_object *object, int fd,
					   int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_armor=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->armor);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->armor);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_intellect(t_object *object, int fd,
					       int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_intellect=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->intellect);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->intellect);
      tmp = tmp->next;
      i++;
    }
}
