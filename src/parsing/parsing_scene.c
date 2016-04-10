/*
** parsing_scene.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Sun Apr 10 18:13:22 2016 Gaëtan Léandre
*/

#include		"main.h"

static t_scene		*my_puterror_s(char *str)
{
  t_scene		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

static t_ground		*my_puterror_g(char *str)
{
  t_ground		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_object		*link_object(t_object *object, t_sprite *sprite)
{
  t_object		*tmp_object;
  t_sprite		*tmp_sprite;

  tmp_object = object;
  while (tmp_object != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_object->sprite_id)
	    tmp_object->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_object = tmp_object->next;
    }
  return (object);
}

t_decors		*link_decors(t_decors *decors, t_sprite *sprite)
{
  t_decors		*tmp_decors;
  t_sprite		*tmp_sprite;

  tmp_decors = decors;
  while (tmp_decors != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_decors->sprite_id)
	    tmp_decors->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_decors = tmp_decors->next;
    }
  return (decors);
}

t_npc			*link_npc(t_npc *npc, t_sprite *sprite)
{
  t_npc			*tmp_npc;
  t_sprite		*tmp_sprite;

  tmp_npc = npc;
  while (tmp_npc != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_npc->sprite_id)
	    tmp_npc->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_npc = tmp_npc->next;
    }
  return (npc);
}

t_item			*link_inventory_item(t_item *inventory, t_object *object)
{
  t_object		*tmp_object;
 int			i;

  i = -1;
  while (++i != SIZE_INVENTORY)
    {
      tmp_object = object;
      while (tmp_object != NULL)
	{
	  if (tmp_object->object_id == inventory[i].id)
	    inventory[i].object = tmp_object;
	  tmp_object = tmp_object->next;
	}
    }
  return (inventory);
}

t_ground		*ground_fill(t_bunny_ini *ini, t_scene *scene)
{
  t_npc			*npc;
  t_decors		*decors;
  int			tab[3];
  char			*str;
  int			i;
  int			j;

  i = -1;
  while (++i != (scene->size.x * scene->size.y))
    {
      scene->ground[i].npc = NULL;
      scene->ground[i].decors = NULL;
    }
  scene->ground[i].npc = NULL;
  scene->ground[i].decors = NULL;
  if ((str = (char *)bunny_ini_get_field(ini, "count", "scene_npc_count", 0)) == NULL)
    return (NULL);
  i = my_getnbr(str);
  j = 0;
  while (j <= i)
    {
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "npc_id", j)) == NULL)
	return (my_puterror_g("Error: scene or scene:npc_id not set\n"));
      tab[0] = my_getnbr(str);
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "npc_pos", j)) == NULL)
	return (my_puterror_g("Error: scene or scene:npc_pos not set\n"));
      tab[1] = my_getnbr(str);
      i = -1;
      while (str[++i] && str[i] != ';');
      tab[2] = my_getnbr(str + i + 1);
      npc = scene->npc;
      while (npc != NULL)
	{
	  if (npc->npc_id == tab[0])
	    scene->ground[(tab[1] + (tab[2] * scene->size.x))].npc = npc;
	  npc = npc->next;
	}
      j++;
    }
  if ((str = (char *)bunny_ini_get_field(ini, "count", "scene_decors_count", 0)) == NULL)
    return (NULL);
  i = my_getnbr(str);
  j = 0;
  while (j < i)
    {
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "decors_id", j)) == NULL)
	return (my_puterror_g("Error: scene or scene:decors_id not set\n"));
      tab[0] = my_getnbr(str);
      if ((str = (char *)bunny_ini_get_field(ini, "scene", "decors_pos", j)) == NULL)
	return (my_puterror_g("Error: scene or scene:decors_pos not set\n"));
      tab[1] = my_getnbr(str);
      i = -1;
      while (str[++i] && str[i] != ';');
      tab[2] = my_getnbr(str + i + 1);
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

t_scene			*link_ground(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list)
{
  t_ground		*ground;
  char			*str;

  ground = NULL;
  if ((str = (char *)bunny_ini_get_field(ini, "scene", "nb_x_case", 0)) == NULL)
    return (my_puterror_s("Error: scene or scene:nb_x_case not set\n"));
  scene->size.x = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "scene", "nb_y_case", 0)) == NULL)
    return (my_puterror_s("Error: scene or scene:nb_y_case not set\n"));
  scene->size.y = my_getnbr(str);
  if ((ground = xmalloc((sizeof(*ground) * ((scene->size.x * scene->size.y) + 1)), ptr_list)) == NULL)
    return (my_puterror_s("Error: Malloc failed ground.c:t_ground\n"));
  scene->ground = ground;
  if ((scene->ground = ground_fill(ini, scene)) == NULL)
    return (NULL);
  scene->height = 300;
  return (scene);
}

t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list)
{
  /* Penser gestion d'erreur id deja existant ou inexistant sur toute les list, sprite objet ... */
  /* Penser verifé taille image, image 25cm, hibox 26cms */
  scene->object = link_object(scene->object, scene->sprite);
  scene->player->inventory = link_inventory_item(scene->player->inventory, scene->object);
  scene->decors = link_decors(scene->decors, scene->sprite);
  scene->npc = link_npc(scene->npc, scene->sprite);
  scene = link_ground(ini, scene, ptr_list);
  set_hitbox_ground(scene, (*ptr_list));
  return (scene);
}
