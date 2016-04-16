/*
** write_scene3.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 20:38:05 2016 Gaëtan Léandre
** Last update Sat Apr 16 21:49:27 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_scene_decors_pos_x(t_scene *scene, int fd,
						 int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_decors_pos_y=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].decors != NULL)
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

void			write_scene_decors_pos_y(t_scene *scene, int fd,
						 int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_decors_pos_x=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].decors != NULL)
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

void			write_scene_decors_id(t_scene *scene, int fd,
					      int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  my_printf(fd, "scene_decors_id=");
  while(x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].decors != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].decors->decors_id);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].decors->decors_id);
	      i++;
	    }
	  y++;
	}
      x++;
    }
}

void			write_scene_decors_count(t_scene *scene, int fd)
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
	  if (scene->ground[x + y * scene->size.x].decors)
	    i++;
	  y++;
	}
      x++;
    }
  my_printf(fd, "scene_decors_count=\"%d\"\n", i);
  write_scene_decors_id(scene, fd, i);
  write_scene_decors_pos_x(scene, fd, i);
  write_scene_decors_pos_y(scene, fd, i);
}
