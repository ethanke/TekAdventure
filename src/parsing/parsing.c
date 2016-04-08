/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Fri Apr  8 06:02:48 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_object		*object;
  t_sprite		*sprite;
  t_decors		*decors;
  t_npc			*npc;
  t_scene		*scene;

  ini = bunny_load_ini(file);
  if (((*player) = load_player(ini, ptr_list)) == NULL)
    return (NULL);

  if ((object = load_object(ini, ptr_list)) == NULL)
    return (NULL);
  if ((sprite = load_sprite(ini, ptr_list)) == NULL)
    return (NULL);
  if ((decors = load_decors(ini, ptr_list)) == NULL)
    return (NULL);
  if ((npc = load_npc(ini, ptr_list)) == NULL)
    return (NULL);

  /*
  if ((scene = load_scene(ini, ptr_list)) == NULL)
    return (NULL);
  */
  scene = xmalloc(sizeof(*scene), ptr_list);
  scene->npc = npc;
  scene->object = object;
  scene->decors = decors;
  return (scene);
}
