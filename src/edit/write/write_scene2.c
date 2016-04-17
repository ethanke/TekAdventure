/*
** write_scene2.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 20:18:15 2016 Gaëtan Léandre
** Last update Sun Apr 17 02:06:25 2016 Victor Sousa
*/

#include		"main.h"

void			write_scene_npc_pos_y(t_scene *scene, int fd, int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = -1;
  my_printf(fd, "scene_npc_pos_y=");
  while (++x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].npc != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", y);
	      else
		my_printf(fd, "\"%d\"\n", y);
	      i++;
	    }
	  y++;
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_npc_pos_x(t_scene *scene, int fd, int size)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = -1;
  my_printf(fd, "scene_npc_pos_x=");
  while (++x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].npc != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", x);
	      else
		my_printf(fd, "\"%d\"\n", x);
	      i++;
	    }
	  y++;
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_npc_id(t_scene *scene, int fd, int size)
{
  int			x;
  int			y;
  int			i;

  i = 0 * (x = -1);
  my_printf(fd, "scene_npc_id=");
  while (++x < scene->size.x)
    {
      y = -1;
      while (++y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].npc != NULL)
	    {
	      if (i != size - 1)
		my_printf(fd, "\"%d\", ", scene->ground[x + y * scene->size.x].
			  npc->npc_id);
	      else
		my_printf(fd, "\"%d\"\n", scene->ground[x + y * scene->size.x].
			  npc->npc_id);
	      i++;
	    }
	}
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_scene_npc_count(t_scene *scene, int fd)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  while (x < scene->size.x)
    {
      y = 0;
      while (y < scene->size.y)
	{
	  if (scene->ground[x + y * scene->size.x].npc != NULL)
	    i++;
	  y++;
	}
      x++;
    }
  my_printf(fd, "scene_npc_count=\"%d\"\n", i);
  write_scene_npc_id(scene, fd, i);
  write_scene_npc_pos_x(scene, fd, i);
  write_scene_npc_pos_y(scene, fd, i);
}
