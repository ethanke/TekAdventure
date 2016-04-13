/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Wed Apr 13 07:00:10 2016 Philippe Lefevre
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
  t_scene		*stockage;

  ini = bunny_load_ini(file);
  if ((stockage = xmalloc(sizeof(*stockage), ptr_list)) == NULL)
    return (my_puterror_s("Error: xmalloc parsing.c:43\n"));
  if ((stockage->player = load_player(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->object = load_object(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->sprite = load_sprite(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->decors = load_decors(ini, ptr_list)) == NULL)
    return (NULL);
  if ((stockage->npc = load_npc(ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene = load_scene(ini, stockage, ptr_list)) == NULL)
    return (NULL);
  (*player) = stockage->player;
  bunny_delete_ini(ini);
  return (scene);
}
