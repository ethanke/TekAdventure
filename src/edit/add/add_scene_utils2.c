/*
** add_scene_utils2.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 10:39:15 2016 Gaëtan Léandre
** Last update Sun Apr 17 10:41:03 2016 Gaëtan Léandre
*/

#include		"main.h"

void			list_add_new_scene(t_ini *ini, t_scene *new)
{
  t_scene		*tmp;

  tmp = ini->scene;
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else
    ini->scene = new;
}

void			init_sprite_hitbox(t_ini *ini, t_sky *sky)
{
  my_printf(1, "Choose a sprite id for your sky : ");
  sky->sky_sprite_id = get_existing_sprite(ini);
  my_printf(1, "top left position in the sprite\nx : ");
  sky->hitbox->x = get_x_pos_sprite(ini, sky->sky_sprite_id);
  my_printf(1, "y : ");
  sky->hitbox->y = get_y_pos_sprite(ini, sky->sky_sprite_id);
  my_printf(1, "width in the sprite : ");
  sky->hitbox->width = get_x_pos_sprite(ini, sky->sky_sprite_id);
  my_printf(1, "height in the sprite : ");
  sky->hitbox->height = get_y_pos_sprite(ini, sky->sky_sprite_id);
}

void			create_sky(t_ini *ini, t_scene *scene)
{
  t_sky			*sky;
  t_sky			*tmp;

  if ((sky = xmalloc(sizeof(t_sky), &ini->ptr_list)) == NULL
      || (sky->hitbox = xmalloc(sizeof(t_hitbox), &ini->ptr_list)) == NULL)
    return;
  init_sprite_hitbox(ini, sky);
  sky->distance = get_major("distance", ini);
  sky->next = NULL;
  sky->prev = NULL;
  if (scene->sky == NULL)
    scene->sky = sky;
  else
    {
      tmp = scene->sky;
      while (tmp->next != NULL)
	tmp = tmp->next;
      sky->prev = tmp;
      tmp->next = sky;
    }
}

void			init_scene_null(t_scene *spr)
{
  spr->sky = NULL;
  spr->sprite = NULL;
  spr->npc = NULL;
  spr->object = NULL;
  spr->decors = NULL;
  spr->player = NULL;
}

void			init_scene_sol(t_ini *ini, t_scene *spr)
{
  my_printf(1, "Choose a sprite id for your ground : ");
  spr->sol_id = get_existing_sprite(ini);
  my_printf(1, "top left position in the sprite\nx : ");
  spr->sol_hitbox->x = get_x_pos_sprite(ini, spr->sol_id);
  my_printf(1, "y : ");
  spr->sol_hitbox->y = get_y_pos_sprite(ini, spr->sol_id);
  my_printf(1, "width in the sprite : ");
  spr->sol_hitbox->width = get_x_pos_sprite(ini, spr->sol_id);
  my_printf(1, "height in the sprite : ");
  spr->sol_hitbox->height = get_y_pos_sprite(ini, spr->sol_id);
}
