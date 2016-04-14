/*
** parsing_sky.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 02:52:33 2016 Philippe Lefevre
** Last update Thu Apr 14 03:00:29 2016 Philippe Lefevre
*/

#include		"main.h"

t_ground		*ground_fill(t_bunny_ini *ini, t_scene *scene)
{
  t_npc			*npc;
  t_decors		*decors;
  int			tab[3];
  char			*str;
  int			i;
  int			j;
  int			k;

  i = -1;
  while (++i != (scene->size.x * scene->size.y))
    {
      scene->ground[i].npc = NULL;
      scene->ground[i].decors = NULL;
    }
  scene->ground[i].npc = NULL;
  scene->ground[i].decors = NULL;
  if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_npc_count", 0)) == NULL)
    return (my_puterror_ground("Error scene:scene_npc_count field ", -1, "not found\n"));
  if ((i = my_getnbr(str)) < 0)
  return (my_puterror_ground("Error scene:scene_npc_count ", -1, "should not be negative\n"));
  j = 0;
  while (j < i)
    {
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_npc_id", j)) == NULL)
	return (my_puterror_ground("Error: scene:scene_npc_id field ", -1, "not found\n"));
      if ((tab[0] = my_getnbr(str)) < 0)
	return (my_puterror_ground("Error scene:scene_npc_id field ", j, " should not be negative\n"));
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_npc_pos", j)) == NULL)
	return (my_puterror_ground("Error: scene:scene_npc_pos field ", j, " not found\n"));
      tab[1] = my_getnbr(str);
      k = -1;
      while (str[++k] && str[k] != ';');
      tab[2] = my_getnbr(str + k + 1);
      npc = scene->npc;
      while (npc != NULL)
	{
	  if (npc->npc_id == tab[0])
	    scene->ground[(tab[1] + (tab[2] * scene->size.x))].npc = npc;
	  npc = npc->next;
	}
      j++;
    }
  if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_decors_count", 0)) == NULL)
    return (my_puterror_ground("Error scene:scene_decors_count field ", -1, "not found\n"));
  if ((i = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error scene:scene_decors_count ", -1, "should not be negative\n"));
  j = 0;
  while (j < i)
    {
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_decors_id", j)) == NULL)
	return (my_puterror_ground("Error: scene:scene_decors_id field ", j, " not found\n"));
      if ((tab[0] = my_getnbr(str)) < 0)
	return (my_puterror_ground("Error scene:scene_decors_id field ", j, " should not be negative\n"));
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_decors_pos", j)) == NULL)
	return (my_puterror_ground("Error: scene:scene_decors_pos field ", j, " not found\n"));
      tab[1] = my_getnbr(str);
      k = -1;
      while (str[++k] && str[k] != ';');
      tab[2] = my_getnbr(str + k + 1);
      decors = scene->decors;
      while (decors != NULL)
      {
	if (decors->decors_id == tab[0])
	    scene->ground[(tab[1] + (tab[2] * scene->size.x))].decors = decors;
	  decors = decors->next;
      }
      j++;
    }
  return (scene->ground);
}

t_hitbox		*create_sol_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "scene", "scene_ground_sprite_hitbox", id)) == NULL)
    return (my_puterror_hitbox("Error: scene:scene_ground_sprite_hitbox field ", id, " not found\n"));
  i = -1;
  hitbox->x = my_getnbr(str);
  while (str[++i] && str[i] != ';');
  hitbox->y = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->width = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->height = my_getnbr(str + i + 1);
  return (hitbox);
}
