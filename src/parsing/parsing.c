/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Sun Apr 17 09:38:25 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*link_ptr_gate(t_scene *scene)
{
  t_scene		*tmp_scene;
  t_scene		*scene_finder;
  t_gate		*gate;

  tmp_scene = scene;
  while (tmp_scene != NULL)
    {
      gate = tmp_scene->ground->gate;
      while (gate != NULL)
	{
	  scene_finder = scene;
	  while (scene_finder != NULL)
	    {
	      if (!(my_strcmp(scene_finder->name, gate->name)))
		tmp_scene->ground->gate->scene = scene_finder;
	      scene_finder = scene_finder->next;
	    }
	  gate = gate->next;
	}
      tmp_scene = tmp_scene->next;
    }
  return (scene);
}

t_scene			*parsing_link_all(t_scene *stockage)
{
  if ((stockage->object =
       link_object(stockage->object, stockage->sprite)) == NULL)
    return (NULL);
  if ((stockage->decors =
       link_decors(stockage->decors, stockage->sprite)) == NULL)
    return (NULL);
  if ((stockage->npc =
       link_npc(stockage->npc, stockage->sprite, stockage->object)) == NULL)
    return (NULL);
  if ((stockage->player->inventory =
       link_inventory_item(stockage->player->inventory,
			   stockage->object)) == NULL)
    return (NULL);
  return (stockage);
}

t_scene			*parsing_load_all(t_bunny_ini *ini, t_scene *stockage,
					  t_ptr_list **ptr_list)
{
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
  return (stockage);
}

int			parsing_check_spawn_zone(t_scene *scene)
{
  int			x;
  int			y;
  int			i;
  t_scene		*tmp_scene;

  tmp_scene = scene;
  while (tmp_scene != NULL)
    {
      i = -1;
      y = -1;
      while (++y < tmp_scene->size.y)
	{
	  x = -1;
	  while (++x < tmp_scene->size.x)
	    {
	      i = x + (y * tmp_scene->size.x);
	      if ((tmp_scene->ground[i].npc != NULL)
		  && (tmp_scene->ground[i].decors != NULL))
		return (my_printf(2, "Error: npc id %d and decors id %d set on same case in %d;%d\n",
				  tmp_scene->ground[i].npc->npc_id,
				  tmp_scene->ground[i].decors->decors_id, x, y) - 1);
	      if (((tmp_scene->ground[i].npc != NULL)
		   || (tmp_scene->ground[i].decors != NULL))
		  && (tmp_scene->ground[i].gate != NULL))
		{
		  printf("(%s)(%d)\n", "conflict double set object\n", i);
		}
	      else if (((tmp_scene->ground[i].npc != NULL)
			|| (tmp_scene->ground[i].decors != NULL)
			|| (tmp_scene->ground[i].gate != NULL))
		       && (tmp_scene->start_pos->x == x)
		       && (tmp_scene->start_pos->y == y))
		{
		  return (my_printf(2, "Error: Spawn on same case of [decors|npc|gate] %d;%d\n", x, y) - 1);
		}
	    }
	}
      tmp_scene = tmp_scene->next;
    }
  return (0);
}

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_scene		*stockage;
  t_scene		*scene;

  if ((ini = bunny_load_ini(file)) == NULL)
    return (my_puterror_scene("Error: ", "", (char *)file,
			      -1, ":No such file or directory\n"));
  if ((stockage = xmalloc(sizeof(*stockage), ptr_list)) == NULL)
    return (my_puterror_scene("Error: ", "stockage",
			      ":xmalloc ", -1, "failed\n"));
  if ((stockage = parsing_load_all(ini, stockage, ptr_list)) == NULL)
    return (NULL);
  if ((stockage = parsing_link_all(stockage)) == NULL)
    return (NULL);
  if ((scene = load_scene(ini, stockage, ptr_list)) == NULL)
    return (NULL);
  scene->player->x = scene->start_pos->x;
  scene->player->y = scene->start_pos->y;
  (*player) = stockage->player;
  bunny_delete_ini(ini);
  if ((scene = link_ptr_gate(scene)) == NULL)
    return (NULL);
  if (parsing_check_spawn_zone(scene))
    return (NULL);
  return (scene);
}
