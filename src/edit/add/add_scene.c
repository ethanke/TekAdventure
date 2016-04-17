/*
** add_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 07:10:26 2016 Gaëtan Léandre
** Last update Sun Apr 17 09:13:13 2016 Gaëtan Léandre
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

int			get_major_2(char *msg, t_ini *ini, int max)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, "Enter %s : ", msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr(str);
      free(str);
      if (id >= 0 && id < max)
	return (id);
      my_printf(1, "%s must be between 0 and %d\nTry again : ", msg, max - 1);
    }
  return (8);
}

int			get_major(char *msg, t_ini *ini)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, "Enter %s : ", msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr(str);
      free(str);
      if (id > 0)
	return (id);
      my_printf(1, "%s must be superior to 0\nTry again : ", msg);
    }
  return (8);
}

void			init_gound(t_scene *scene)
{
  int			i;
  int			max;

  max = scene->size.x * scene->size.y;
  i = 0;
  while (i < max)
    {
      scene->ground[i].npc = NULL;
      scene->ground[i].decors = NULL;
      scene->ground[i].gate = NULL;
      i++;
    }
}

int			scene_name_is_taken(t_ini *ini, char *str)
{
  t_scene		*tmp;

  tmp = ini->scene;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*get_sce_name(t_ini *ini)
{
  char			*str;

  my_printf(1, "Enter scene name : ");
  while ((str = get_next_line(0)) != NULL)
    {
      if (scene_name_is_taken(ini, str) == 0)
	return (str);
      my_printf(1, "Name already taken by another scene\nTry again : ");
      free(str);
    }
  return (str);
}

void			create_sky(t_ini *ini, t_scene *scene)
{
  t_sky			*sky;
  t_sky			*tmp;

  if ((sky = malloc(sizeof(t_sky))) == NULL
      || (sky->hitbox = malloc(sizeof(t_hitbox))) == NULL)
    return;
  sky->sky_sprite_id = get_sprite_id(ini);
  sky->hitbox->y = get_x_pos_sprite(ini, sky->sky_sprite_id);
  sky->hitbox->y = get_y_pos_sprite(ini, sky->sky_sprite_id);
  sky->hitbox->width = get_x_pos_sprite(ini, sky->sky_sprite_id);
  sky->hitbox->height = get_y_pos_sprite(ini, sky->sky_sprite_id);
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

void			add_scene(t_ini *ini)
{
  t_scene		*spr;

  if ((spr = xmalloc(sizeof(t_scene), &ini->ptr_list)) == NULL
      || (spr->start_pos = xmalloc(sizeof(t_bunny_position), &ini->ptr_list)) == NULL
      || (spr->sol_hitbox = xmalloc(sizeof(t_hitbox), &ini->ptr_list)) == NULL)
    return;
  spr->name = get_sce_name(ini);
  spr->size.x = get_major("size x", ini);
  spr->size.y = get_major("size y", ini);
  if ((spr->ground = malloc(spr->size.x * spr->size.x * sizeof(t_ground)))
      == NULL)
    return;
  init_gound(spr);
  spr->start_pos->x = get_major_2("start x", ini, spr->size.x);
  spr->start_pos->y = get_major_2("start y", ini, spr->size.y);
  spr->height = get_major("ground height", ini);
  puts("a");
  spr->sol_id = get_sprite_id(ini);
  puts("b");
  spr->sol_hitbox->x = get_x_pos_sprite(ini, spr->sol_id);
  spr->sol_hitbox->y = get_y_pos_sprite(ini, spr->sol_id);
  spr->sol_hitbox->width = get_x_pos_sprite(ini, spr->sol_id);
  spr->sol_hitbox->height = get_y_pos_sprite(ini, spr->sol_id);
  create_sky(ini, spr);
  while (get_dec_collect("Add more sky?  (yes or no) : ", ini) == 1)
    create_sky(ini, spr);
  if (get_dec_collect("Do you want to add it in ini?  (yes or no) :", ini) == 1)
    list_add_new_scene(ini, spr);
  my_printf(1, "Decors added in your ini file :D\n\n");
}
