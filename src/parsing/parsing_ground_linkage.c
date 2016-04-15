/*
** parsing_sky.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 02:52:33 2016 Philippe Lefevre
** Last update Fri Apr 15 03:39:49 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*link_ground(t_bunny_ini *ini, t_scene *scene,
				     t_ptr_list **ptr_list, char *name)
{
  t_sprite		*tmp_sprite;
  t_ground		*ground;
  char			*str;
  int			i;

  ground = NULL;
  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_nb_x_case", 0)) == NULL)
    return (my_puterror_scene("Error: ", name, ":scene_nb_x_case field ", 1, " not found\n"));
  if ((scene->size.x = my_getnbr(str)) < 0)
    return (my_puterror_scene("Error ", name, ":scene_nb_x_case field ", 1, " should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_nb_y_case", 0)) == NULL)
    return (my_puterror_scene("Error: ", name, ":scene_nb_y_case field ", 1, " not found\n"));
  if ((scene->size.y = my_getnbr(str)) < 0)
    return (my_puterror_scene("Error ", name, ":scene_nb_y_case field ", 1, " should not be negative\n"));
  if ((ground = xmalloc((sizeof(*ground) * ((scene->size.x * scene->size.y) + 1)), ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", name, ":xmalloc ", -1, "failed in link_ground\n"));
  scene->ground = ground;
  if ((scene->ground = ground_fill(ini, scene, ptr_list, name)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_ground_sprite_id", 0)) == NULL)
    return (my_puterror_scene("Error: ", name, ":scene_ground_sprite_id field ", 1, " not found\n"));
  if ((scene->sol_id = my_getnbr(str)) < 0)
    return (my_puterror_scene("Error ", name, ":scene_ground_sprite_id field ", 1, " should not be negative\n"));
  if ((scene->sol_hitbox = create_sol_hitbox(0, ini, ptr_list, name)) == NULL)
    return (NULL);
  scene->height = 300;
  tmp_sprite = scene->sprite;
  while (tmp_sprite != NULL)
    {
      if (tmp_sprite->id == scene->sol_id)
	scene->sol = tmp_sprite->sprite;
      tmp_sprite = tmp_sprite->next;
    }
  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_start_pos", 0)) == NULL)
    return (my_puterror_scene("Error: ", name, ":scene_start_pos field ", 1, " not found\n"));
  if ((scene->start_pos = xmalloc(sizeof(*scene->start_pos), ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", "scene->start_pos", ":xmalloc ", -1, "failed in link_ground\n"", -1"));
    /* verif des negative apres str to wordtab de ca sur tous */
  scene->start_pos->x = my_getnbr(str);
  i = -1;
  while (str[++i] && str[i] != ';');
  scene->start_pos->y = my_getnbr(str + i + 1);
  return (scene);
}
