/*
** write_object3.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 09:48:17 2016 Gaëtan Léandre
** Last update Sat Apr 16 10:17:46 2016 Victor Sousa
*/

#include		"main.h"

void			write_object_critical(t_object *object, int fd,
					      int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_critical=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->critical);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->critical);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_strength(t_object *object, int fd,
					      int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_strength=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->strength);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->strength);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_stamina(t_object *object, int fd,
					     int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_stamina=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->caract->stamina);
      else
	my_printf(fd, "\"%d\"\n", tmp->caract->stamina);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_equip_slot(t_object *object, int fd,
						int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_equipable_slot=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->slot);
      else
	my_printf(fd, "\"%d\"\n", tmp->slot);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_equip(t_object *object, int fd,
					   int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_is_equipable=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->is_equipable);
      else
	my_printf(fd, "\"%d\"\n", tmp->is_equipable);
      tmp = tmp->next;
      i++;
    }
}
