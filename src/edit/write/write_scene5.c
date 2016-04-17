/*
** write_scene5.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 21:06:33 2016 Gaëtan Léandre
** Last update Sun Apr 17 02:08:18 2016 Victor Sousa
*/

#include		"main.h"

void			write_scene_gate_sprite_hit_h(t_scene *scene, int fd,
						      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0 * (x = -1);
  my_printf(fd, "scene_gate_sprite_hitbox_height=");
  while (++x < scene->size.x)
    {
      y = -1;
      while (++y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->height);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->height);
	      i++;
	    }
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_gate_sprite_hit_w(t_scene *scene, int fd,
						      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0 * (x = -1);
  my_printf(fd, "scene_gate_sprite_hitbox_width=");
  while (++x < scene->size.x)
    {
      y = -1;
      while (++y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->width);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->width);
	      i++;
	    }
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_gate_sprite_hit_y(t_scene *scene, int fd,
						      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0 * (x = -1);
  my_printf(fd, "scene_gate_sprite_hitbox_y=");
  while (++x < scene->size.x)
    {
      y = -1;
      while (++y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->y);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->y);
	      i++;
	    }
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_gate_sprite_hit_x(t_scene *scene, int fd,
						      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0 * (x = -1);
  my_printf(fd, "scene_gate_sprite_hitbox_x=");
  while (++x < scene->size.x)
    {
      y = -1;
      while (++y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->x);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].
			  gate->texture_hitbox->x);
	      i++;
	    }
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}
