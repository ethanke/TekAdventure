/*
** write_scene4.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 20:53:36 2016 Gaëtan Léandre
** Last update Sat Apr 16 21:47:48 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_scene_gate_sprite_id(t_scene *scene, int fd,
						   int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_gate_sprite_id=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].gate->sprite_id);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].gate->sprite_id);
	      i++;
	    }
	  y++;
	}
      x++;
    }
}

void			write_scene_gate_pos_x(t_scene *scene, int fd,
						 int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_gate_pos_x=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", y);
	      else
		my_printf(fd, "\"%d\"\n", y);
	      i++;
	    }
	  y++;
	}
      x++;
    }
}

void			write_scene_gate_pos_y(t_scene *scene, int fd,
					       int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_gate_pos_y=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", x);
	      else
		my_printf(fd, "\"%d\"\n", x);
	      i++;
	    }
	  y++;
	}
      x++;
    }
}

void			write_scene_gate_name(t_scene *scene, int fd,
					      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_gate_name=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%s\", ", scene->ground[x + y * scene->size.x].gate->name);
	      else
		my_printf(fd, "\"%s\"\n", scene->ground[x + y * scene->size.x].gate->name);
	      i++;
	    }
	  y++;
	}
      x++;
    }
}

void			write_scene_gate_count(t_scene *scene, int fd)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].gate)
	    i++;
	  y++;
	}
      x++;
    }
  my_printf(fd, "scene_gate_count=\"%d\"\n", i);
  write_scene_gate_name(scene, fd, i);
  write_scene_gate_pos_x(scene, fd, i);
  write_scene_gate_pos_y(scene, fd, i);
  write_scene_gate_sprite_id(scene, fd, i);
  write_scene_gate_sprite_hit_x(scene, fd, i);
  write_scene_gate_sprite_hit_y(scene, fd, i);
  write_scene_gate_sprite_hit_w(scene, fd, i);
  write_scene_gate_sprite_hit_h(scene, fd, i);
}
