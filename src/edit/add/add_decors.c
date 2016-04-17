/*
** add_decors.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 03:00:51 2016 Gaëtan Léandre
** Last update Sun Apr 17 04:24:51 2016 Gaëtan Léandre
*/

#include		"main.h"

void			list_add_new_decors(t_scene *scene, t_decors *new)
{
  t_decors		*tmp;

  while (tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else
    scene->decors = new;
}

void			add_decors(t_ini *ini)
{
  char			*str;
  t_decors		*dec;

  if ((dec = xmalloc(sizeof(t_decors), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\nGive and id to your decors : ");
  if ((dec->decors_id = get_dec_id(ini)) == -1)
    return;
  my_printf(1, "Give a name to your decors : ");
  if ((dec->name = get_dec_name(ini)) == NULL)
    return;
  if ((dec->decors_breakable = xmalloc(sizeof(t_breakable), &ini->ptr_list)) == NULL)
    return;
  if ((dec->decors_breakable->is_breakable = get_decors_collect(ini)) == -1)
    return;
  if (dec->->decors_breakable->is_breakable == 0)
    {
      dec->decors_breakable->life = 0;
      dec->decors_breakable->breakable_by = 0;
      dec->decors_breakable->lootable = 0;
      dec->decors_breakable->loot[0] = 0;
      dec->decors_breakable->loot[1] = 0;
    }
  else
    {
      dec->decors_breakable->life = get_id_posi("Give life to your decors : ", ini);
      dec->decors_breakable->breakable_by = get_object("Give item to break your decors : ", ini);
      if ((dec->decors_breakable->lootable = get_decors_collect(ini)) == -1)
	return;
      if (dec->decors_breakable->lootable == 0)
	{
	  dec->decors_breakable->loot[0] = 0;
	  dec->decors_breakable->loot[1] = 0;
	}
      else
	{
	  dec->decors_breakable->loot[0] =  get_object("What is your decors loot : ", ini);
	  dec->decors_breakable->loot[1] =  get_object("How many : ", ini);
        }
      }
  my_printf(1, "\nChoose a sprite id for your decors : ");
  dec->sprite_id = get_existing_sprite(ini);
  if ((dec->texture_hitbox = xmalloc(sizeof(t_hitbox),
				     &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\ntop left position in the sprite\nx : ");
  dec->texture_hitbox->x = get_x_pos_sprite(ini, dec->sprite_id);
  my_printf(1, "y : ");
  dec->texture_hitbox->y = get_y_pos_sprite(ini, dec->sprite_id);
  my_printf(1, "\nwidth in the sprite : ");
  dec->texture_hitbox->width = get_x_pos_sprite(ini, dec->sprite_id);
  my_printf(1, "height in the sprite : ");
  dec->texture_hitbox->height = get_y_pos_sprite(ini, dec->sprite_id);

  /* recap */
  my_printf(1, "\n\nHere is your decors\nid: %d\n", dec->decors_id);
  my_printf(1, "name: %s\n", dec->name);
  my_printf(1, "is breakable: %d\n", dec->decors_breakable->is_breakable);
  my_printf(1, "breakable by: %d\n", dec->decors_breakable->breakable_by);
  my_printf(1, "life: %d\n", dec->decors_breakable->life);
  my_printf(1, "is lootable: %d\n", dec->decors_breakable->lootable);
  my_printf(1, "loot %d of %d\n", dec->decors_breakable->loot[0], dec->decors_breakable->loot[1]);
  my_printf(1, "sprite id: %d\n", dec->sprite_id);
  my_printf(1, "sprite pos x: %d\n", dec->texture_hitbox->x);
  my_printf(1, "sprite pos y: %d\n", dec->texture_hitbox->y);
  my_printf(1, "sprite width: %d\n", dec->texture_hitbox->width);
  my_printf(1, "sprite height: %d\n", dec->texture_hitbox->height);

  my_printf(1, "So do you want to add it in ini?  (yes or no)\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  if (my_strcmp(str, "yes") == 0)
    {
      list_add_new_decors(ini->scene, dec);
      my_printf(1, "Decors added in your ini file :D\nYou can write it using");
      my_printf(1, " 'write ini path_to_file.ini'\n\n");
    }
}
