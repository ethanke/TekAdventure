/*
** parsing_sky.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 02:52:33 2016 Philippe Lefevre
** Last update Sun Apr 17 08:41:30 2016 Philippe Lefevre
*/

#include		"main.h"

t_ground		*ground_fill_npc_id(t_bunny_ini *ini, char *name,
					   int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_npc_id", tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_npc_id field ", -1, "not found\n"));
  if ((tmp[0] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_npc_id field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_npc_x(t_bunny_ini *ini, char *name,
					  int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_npc_pos_x", tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_npc_pos_x field ",
			       -1, "not found\n"));
  if ((tmp[1] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_npc_pos_x field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_npc_y(t_bunny_ini *ini, char *name,
					   int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_npc_pos_y", tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_npc_pos_y field ", -1,
			       "not found\n"));
  if ((tmp[2] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_npc_pos_y field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_npc(t_bunny_ini *ini, char *name,
					 t_scene *scene, int i)
{
  t_npc			*npc;
  int			tab[4];

  tab[3] = -1;
  while (++tab[3] < i)
    {
      if ((ground_fill_npc_id(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      if ((ground_fill_npc_x(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      if ((ground_fill_npc_y(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      npc = scene->npc;
      while (npc != NULL)
	{
	  if (npc->npc_id == tab[0])
	    scene->ground[(tab[1] + (tab[2] * scene->size.x))].npc = npc;
	  npc = npc->next;
	}
    }
  return (scene->ground);
}

t_ground		*ground_fill_decors_id(t_bunny_ini *ini, char *name,
					   int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_decors_id", tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_decors_id field ", -1, "not found\n"));
  if ((tmp[0] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_decors_id field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_decors_x(t_bunny_ini *ini, char *name,
					  int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_decors_pos_x",
					 tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_decors_pos_x field ",
			       -1, "not found\n"));
  if ((tmp[1] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_decors_pos_x field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_decors_y(t_bunny_ini *ini, char *name,
					   int *tmp, t_ground *ground)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name, "scene_decors_pos_y",
					 tmp[3])) == NULL)
    return (my_puterror_ground("Error: ", name,
			       ":scene_decors_pos_y field ", -1,
			       "not found\n"));
  if ((tmp[2] = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name,
			       ":scene_decors_pos_y field ", tmp[3],
			       " should not be negative\n"));
  return (ground);
}

t_ground		*ground_fill_decors(t_bunny_ini *ini, char *name,
					 t_scene *scene, int i)
{
  t_decors			*decors;
  int			tab[4];

  tab[3] = -1;
  while (++tab[3] < i)
    {
      if ((ground_fill_decors_id(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      if ((ground_fill_decors_x(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      if ((ground_fill_decors_y(ini, name, tab, scene->ground)) == NULL)
	return (NULL);
      decors = scene->decors;
      while (decors != NULL)
	{
	  if (decors->decors_id == tab[0])
	    scene->ground[(tab[1] + (tab[2] * scene->size.x))].decors = decors;
	  decors = decors->next;
	}
    }
  return (scene->ground);
}

t_ground		*ground_fill_npc_init(t_bunny_ini *ini,
					      t_scene *scene,
					      char *name, int i)
{
  char			*str;
  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_decors_count", 0)) == NULL)
    return (my_puterror_ground("Error ", name, ":scene_decors_count field ",
			       -1, "not found\n"));
  if ((i = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name, ":scene_decors_count ",
			       -1, "should not be negative\n"));
  if ((scene->ground = ground_fill_decors(ini, name, scene, i)) == NULL)
    return (NULL);
  return (scene->ground);
}

t_ground		*ground_fill_decors_init(t_bunny_ini *ini,
						 t_scene *scene,
					      char *name, int i)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_npc_count", 0)) == NULL)
    return (my_puterror_ground("Error ", name,
			       ":scene_npc_count field ", -1, "not found\n"));
  if ((i = my_getnbr(str)) < 0)
    return (my_puterror_ground("Error ", name, ":scene_npc_count ", -1,
			       "should not be negative\n"));
  if ((scene->ground = ground_fill_npc(ini, name, scene, i)) == NULL)
    return (NULL);
  return (scene->ground);
}

t_ground		*ground_fill(t_bunny_ini *ini, t_scene *scene,
				     char *name)
{
  int			i;

  i = -1;
  while (++i <= (scene->size.x * scene->size.y))
    {
      scene->ground[i].npc = NULL;
      scene->ground[i].decors = NULL;
      scene->ground[i].gate = NULL;
    }
  if ((scene->ground = ground_fill_npc_init(ini, scene, name, i)) == NULL)
    return (NULL);
  if ((scene->ground = ground_fill_decors_init(ini, scene, name, i)) == NULL)
    return (NULL);
  return (scene->ground);
}

t_hitbox		*sol_hitbox_x(int id, t_bunny_ini *ini, char *name,
				      t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_ground_sprite_hitbox_x", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_x field ",
				 id, " not found\n"));
    }
  if ((hitbox->x = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_x field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*sol_hitbox_y(int id, t_bunny_ini *ini, char *name,
				      t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_ground_sprite_hitbox_y", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_y field ",
				 id, " not found\n"));
    }
  if ((hitbox->y = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_y field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*sol_hitbox_width(int id, t_bunny_ini *ini,
					  char *name, t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_ground_sprite_hitbox_width",
					 id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_width field ",
				 id, " not found\n"));
    }
  if ((hitbox->width = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_width field ",
				 id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*sol_hitbox_height(int id, t_bunny_ini *ini,
					   char *name, t_hitbox *hitbox)
{
  char		*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "scene_ground_sprite_hitbox_height",
					 id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_height field ",
				 id, " not found\n"));
    }
  if ((hitbox->height = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":scene_ground_sprite_hitbox_height field ",
				 id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*create_sol_hitbox(int id, t_bunny_ini *ini,
					   t_ptr_list **ptr_list,
					   char *name)
{
  t_hitbox		*hitbox;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: hitbox:xmalloc ", -1,
			       "failed in create_sol_hitbox\n"));
  if ((hitbox = sol_hitbox_x(id, ini, name, hitbox)) == NULL)
    return (NULL);
  if ((hitbox = sol_hitbox_y(id, ini, name, hitbox)) == NULL)
    return (NULL);
  if ((hitbox = sol_hitbox_width(id, ini, name, hitbox)) == NULL)
    return (NULL);
  if ((hitbox = sol_hitbox_height(id, ini, name, hitbox)) == NULL)
    return (NULL);
  return (hitbox);
}
