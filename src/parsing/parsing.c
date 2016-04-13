/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Wed Apr 13 17:59:39 2016 Philippe Lefevre
*/

#include		"main.h"

static	t_scene		*my_puterror_s(char *str)
{
  t_scene		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}
t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_scene		*scene;

  ini = bunny_load_ini(file);
  if ((scene = xmalloc(sizeof(*scene), ptr_list)) == NULL)
    return (my_puterror_s("Error: xmalloc parsing.c:43\n"));
  if ((scene->player = load_player(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->object = load_object(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->sprite = load_sprite(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->decors = load_decors(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->npc = load_npc(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->sky = load_sky(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene = load_scene(ini, scene, ptr_list)) == NULL)
    return (NULL);
  (*player) = scene->player;
  bunny_delete_ini(ini);
  return (scene);
}
