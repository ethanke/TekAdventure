/*
** parsing_scene.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Sun Apr 17 10:44:36 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*create_scene_node_link(t_scene *scene,
						t_scene *stockage)
{
  scene->player = stockage->player;
  scene->object = stockage->object;
  scene->sprite = stockage->sprite;
  scene->decors = stockage->decors;
  scene->npc = stockage->npc;
  scene->player = stockage->player;
  scene->player->inventory = stockage->player->inventory;
  return (scene);
}

t_scene			*create_scene_node(char *name, t_bunny_ini *ini,
					   t_scene *stockage,
					   t_ptr_list **ptr_list)
{
  t_scene		*scene;

  if ((scene = xmalloc(sizeof(t_scene), ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", name, ":xmalloc ",
			      -1, "failed in create_scene_node\n"));
  create_scene_node_link(scene, stockage);
  if ((scene->sky = load_sky(name, ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->sky = link_sky(scene->sky, scene->sprite)) == NULL)
    return (NULL);
  if ((scene->name = my_strdup(name, ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", name, ":my_strdup ", -1,
			      "failed in create_scene_node\n"));
  if ((scene = link_ground(ini, scene, ptr_list, name)) == NULL)
    return (NULL);
  if ((scene->ground->gate = load_gate(name, ini, ptr_list)) == NULL)
    return (NULL);
  if ((scene->ground->gate =
       link_gate(scene->ground->gate, scene->sprite)) == NULL)
    return (NULL);
  if (set_hitbox_ground(scene, (*ptr_list)))
    return (NULL);
  scene->next = NULL;
  scene->prev = NULL;
  return (scene);
}

t_scene			*list_add_scene(t_scene *list, char *name,
					t_bunny_ini *ini, t_scene *stockage,
					t_ptr_list **ptr_list)
{
  t_scene		*new;
  t_scene		*tmp;

  if ((new = create_scene_node(name, ini, stockage, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

char			**load_scene_init(t_bunny_ini *ini, char *str, int i,
					  t_ptr_list **ptr_list)
{
  char		**scene_tab;
  int		len;
  if ((len = my_getnbr(str)) < 0)
    return (my_puterror_chartab("Error: ", "scene", ":scene_count field ", -1
				, " should not be negative\n"));
  if ((scene_tab = xmalloc(sizeof(char *) * (len + 1), ptr_list)) == NULL)
    return (my_puterror_chartab("Error: ", "scene_tab",
				":xmalloc ", -1, "failed in load_scene\n"));
  while (++i < len)
    {
      if ((str = (char *)bunny_ini_get_field(ini, "scene",
					     "scene_name", i)) == NULL)
	return (my_puterror_chartab("Error: ", "scene", ":scene_name ",
				    i, "field not found, \
        or invalid scene:scene_count\n"));
      scene_tab[i] = my_strdup(str, ptr_list);
    }
  scene_tab[i] = 0;
  return (scene_tab);
}

t_scene			*load_scene(t_bunny_ini *ini, t_scene *stockage,
				    t_ptr_list **ptr_list)
{
  t_scene		*new_list;
  char 			**scene_tab;
  char			*str;
  int			i;

  if ((str = (char *)bunny_ini_get_field(ini, "scene",
					 "scene_count", 0)) == NULL)
    return (my_puterror_scene("Error: balise scene or ", "scene",
			      ":scene_count ", -1, "field not found, you \
			      must obligatorily include	\
			      this both fields\n"));
  if ((scene_tab = load_scene_init(ini, str, -1, ptr_list)) == NULL)
    return (NULL);
  new_list = NULL;
  i = -1;
  while (scene_tab[++i])
    {
      printf("%s\n", scene_tab[i]);
      if ((new_list = list_add_scene(new_list, scene_tab[i],
				     ini, stockage, ptr_list)) == NULL)
	return (NULL);
    }
  return (new_list);
}
