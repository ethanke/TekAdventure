/*
** parsing_scene.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Thu Apr 14 03:00:40 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list)
{
  scene->sky = link_sky(scene->sky, scene->sprite);
  scene->object = link_object(scene->object, scene->sprite);
  scene->player = link_player(scene->player, scene->sprite);
  scene->player->inventory = link_inventory_item(scene->player->inventory, scene->object);
  scene->decors = link_decors(scene->decors, scene->sprite);
  scene->npc = link_npc(scene->npc, scene->sprite, scene->object);
  scene = link_ground(ini, scene, ptr_list);
  set_hitbox_ground(scene, (*ptr_list));
  return (scene);
}
