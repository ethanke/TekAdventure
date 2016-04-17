/*
** add_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 07:10:26 2016 Gaëtan Léandre
** Last update Sun Apr 17 10:41:06 2016 Gaëtan Léandre
*/

#include		"main.h"

void			end_scene(t_scene *spr, t_ini *ini)
{
  if (get_dec_collect("Do you want to add it in ini?  (yes or no) : ", ini)
      == 1)
    {
      list_add_new_scene(ini, spr);
      my_printf(1, "Decors added in your ini file :D\nYou can write it using");
      my_printf(1, " 'write ini path_to_file.ini'\n\n");
    }
}

void			resum_scene(t_scene *scene)
{
  t_sky			*sky;

  my_printf(1, "\n\nHere is your scene\n");
  my_printf(1, "name: %s\n", scene->name);
  my_printf(1, "map size: %d %d\n", scene->size.x, scene->size.y);
  my_printf(1, "start pos: %d %d\n", scene->start_pos->x, scene->start_pos->y);
  my_printf(1, "ground height: %d\n", scene->height);
  my_printf(1, "ground texture: %d\n", scene->sol_id);
  my_printf(1, "ground pos x: %d\n", scene->sol_hitbox->x);
  my_printf(1, "ground pos y: %d\n", scene->sol_hitbox->y);
  my_printf(1, "ground width: %d\n", scene->sol_hitbox->width);
  my_printf(1, "ground height: %d\n", scene->sol_hitbox->height);
  my_printf(1, "\nHere is your sky\n");
  sky = scene->sky;
  while (sky != NULL)
    {
      my_printf(1, "sprite id: %d\n", sky->sky_sprite_id);
      my_printf(1, "sprite pos x: %d\n", sky->hitbox->x);
      my_printf(1, "sprite pos y: %d\n", sky->hitbox->y);
      my_printf(1, "sprite width: %d\n", sky->hitbox->width);
      my_printf(1, "sprite height: %d\n", sky->hitbox->height);
      my_printf(1, "sprite distance: %d\n", sky->distance);
      sky = sky->next;
    }
}

void			add_scene(t_ini *ini)
{
  t_scene		*spr;

  if ((spr = xmalloc(sizeof(t_scene), &ini->ptr_list)) == NULL
      || (spr->start_pos = xmalloc(sizeof(t_bunny_position), &ini->ptr_list))
      == NULL
      || (spr->sol_hitbox = xmalloc(sizeof(t_hitbox), &ini->ptr_list)) == NULL)
    return;
  init_scene_null(spr);
  spr->name = get_sce_name(ini);
  spr->size.x = get_major("size x", ini);
  spr->size.y = get_major("size y", ini);
  if ((spr->ground = xmalloc(spr->size.x * spr->size.y * sizeof(t_ground),
			     &ini->ptr_list)) == NULL)
    return;
  init_gound(spr);
  spr->start_pos->x = get_major_2("start x", ini, spr->size.x);
  spr->start_pos->y = get_major_2("start y", ini, spr->size.y);
  spr->height = get_major("ground height", ini);
  init_scene_sol(ini, spr);
  create_sky(ini, spr);
  while (get_dec_collect("Add more sky?  (yes or no) : ", ini) == 1)
    create_sky(ini, spr);
  resum_scene(spr);
  end_scene(spr, ini);
}
