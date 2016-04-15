/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Sat Apr 16 00:41:25 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_scene		*stockage;
  t_scene		*scene;

  ini = bunny_load_ini(file);
  if ((stockage = xmalloc(sizeof(*stockage), ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", "stockage", ":xmalloc ", -1, "failed\n"));
  /* Load All ini information */
  if ((stockage->player = load_player(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->sprite = load_sprite(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->object = load_object(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->decors = load_decors(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->npc = load_npc(ini, ptr_list)) == NULL)
    return (NULL);

  /* Link All ptr sprite to texture */
  if ((stockage->object = link_object(stockage->object, stockage->sprite)) == NULL)
    return (NULL);
  if ((stockage->decors = link_decors(stockage->decors, stockage->sprite)) == NULL)
    return (NULL);
  if ((stockage->npc = link_npc(stockage->npc, stockage->sprite, stockage->object)) == NULL)
    return (NULL);
  if ((stockage->player = link_player(stockage->player, stockage->sprite)) == NULL)
    return (NULL);

  /* Link inventory with default ini inventory */
  if ((stockage->player->inventory = link_inventory_item(stockage->player->inventory,
							 stockage->object)) == NULL)
    return (NULL);
  (*player) = stockage->player;
  if ((scene = load_scene(ini, stockage, ptr_list)) == NULL)
    return (NULL);
  bunny_delete_ini(ini);
  return (scene);
}
