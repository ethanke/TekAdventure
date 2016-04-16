/*
** write_object.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 08:44:31 2016 Gaëtan Léandre
** Last update Sat Apr 16 10:10:09 2016 Gaëtan Léandre
*/

void			write_object_damage(t_object *object, int fd, int size)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_damage=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->damage);
      else
	my_printf(fd, "\"%d\"\n", tmp->damage);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_name(t_object *object, int fd, int size)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_name=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", tmp->name);
      else
	my_printf(fd, "\"%s\"\n", tmp->name);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_id(t_object *object, int fd, int size)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->object_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->object_id);
      tmp = tmp->next;
      i++;
    }
}

void			write_object_launch(t_object *object, int fd, int size)
{
  write_object_id(object, fd, size);
  write_object_name(object, fd, size);
  write_object_damage(object, fd, size);
  write_object_sprite_id(object, fd, size);
  write_object_sprite_hit_x(object, fd, size);
  write_object_sprite_hit_y(object, fd, size);
  write_object_sprite_hit_w(object, fd, size);
  write_object_sprite_hit_h(object, fd, size);
  write_object_equip(object, fd, size);
  write_object_slot(object, fd, size);
  write_object_stamina(object, fd, size);
  write_object_strength(object, fd, size);
  write_object_critical(object, fd, size);
  write_object_intellect(object, fd, size);
  write_object_armor(object, fd, size);
  write_object_agility(object, fd, size);
}

void			write_object(t_object *object, int fd)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  tmp = object;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "[object]\nobject_count=\"%d\"\n", i);
  write_object_launch(object, fd, size);
  my_printf(fd, "\n\n");
}
