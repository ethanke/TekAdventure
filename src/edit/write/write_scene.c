/*
** write_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 19:43:02 2016 Gaëtan Léandre
** Last update Sat Apr 16 22:48:26 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_sky_hitbox_h(t_sky *sky, int fd,
					   int size)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  my_printf(fd, "scene_sky_sprite_hitbox_height=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->hitbox->height);
      else
	my_printf(fd, "\"%d\"\n", tmp->hitbox->height);
      tmp = tmp->next;
      i++;
    }
}

void			disp_scene_ground(t_scene *tmp, int fd)
{
  my_printf(fd, "scene_ground_sprite_id=\"%d\"\n", tmp->sol_id);
  my_printf(fd, "scene_ground_sprite_hitbox_x=\"%d\"\n", tmp->sol_hitbox->x);
  my_printf(fd, "scene_ground_sprite_hitbox_y=\"%d\"\n", tmp->sol_hitbox->y);
  my_printf(fd, "scene_ground_sprite_hitbox_width=\"%d\"\n", tmp->sol_hitbox->width);
  my_printf(fd, "scene_ground_sprite_hitbox_height=\"%d\"\n", tmp->sol_hitbox->height);
}

void			write_particular_scene(t_scene *scene, int fd)
{
  t_scene		*tmp;

  tmp = scene;
  while (tmp != NULL)
    {
      my_printf(fd, "[%s]\n", tmp->name);
      my_printf(fd, "scene_start_pos_x=\"%d\"\n", tmp->start_pos->x);
      my_printf(fd, "scene_start_pos_y=\"%d\"\n", tmp->start_pos->y);
      my_printf(fd, "scene_nb_x_case=\"%d\"\n", tmp->size.x);
      my_printf(fd, "scene_nb_y_case=\"%d\"\n", tmp->size.y);
      my_printf(fd, "scene_grid_height=\"%d\"\n", tmp->height);
      write_scene_npc_count(tmp, fd);
      write_scene_decors_count(tmp, fd);
      write_scene_gate_count(tmp, fd);
      disp_scene_ground(tmp, fd);
      write_sprite_sky(tmp->sky, fd);
      tmp = tmp->next;
    }
}

void			write_scene_name(t_scene *scene, int fd, int size)
{
  t_scene		*tmp;
  int			i;

  i = 0;
  tmp = scene;
  my_printf(fd, "scene_name=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", tmp->name);
      else
	my_printf(fd, "\"%s\"\n\n", tmp->name);
      tmp = tmp->next;
      i++;
    }
}

void			write_scene(t_scene *scene, int fd)
{
  t_scene		*tmp;
  int			i;

  i = 0;
  tmp = scene;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "[scene]\nscene_count=\"%d\"\n", i);
  write_scene_name(scene, fd, i);
  write_particular_scene(scene, fd);
  my_printf(fd, "\n\n");
}
