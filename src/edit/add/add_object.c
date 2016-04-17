/*
** add_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 19:48:52 2016 Victor Sousa
** Last update Sun Apr 17 05:37:14 2016 Gaëtan Léandre
*/

#include		"main.h"

void			list_add_new_object(t_scene *scene, t_object *new)
{
  t_object		*tmp;

  tmp = scene->object;
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else
    scene->object = new;
}

void			add_object(t_ini *ini)
{
  char			*str;
  t_object		*obj;

  if ((obj = xmalloc(sizeof(t_object), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\nGive and id to your object : ");
  if ((obj->object_id = get_obj_id(ini)) == -1)
    return;
  my_printf(1, "Give a name to your object : ");
  if ((obj->name = get_obj_name(ini)) == NULL)
    return;
  my_printf(1, "Give damage to your object : ");
  obj->damage = my_getnbr_free(get_next_line(0));
  if ((obj->is_equipable = get_obj_equipable(ini)) == -1)
    return;
  if (obj->is_equipable == 0)
    {
      obj->slot = (obj->caract->stamina = (obj->caract->strength = 0));
      obj->caract->critical = (obj->caract->intellect = 0);
      obj->caract->armor = (obj->caract->agility = 0);
    }
  else
    {
      obj->slot = get_obj_equip_slot();
      if ((obj->caract = xmalloc(sizeof(t_caract), &ini->ptr_list)) == NULL)
	return;
      my_printf(1, "Give caract to your item\n");
      my_printf(1, "Sugested range is -5 --> 15\n");
      my_printf(1, "Give stamina to your object : ");
      obj->caract->stamina = my_getnbr_free(get_next_line(0));
      my_printf(1, "Give strength to your object : ");
      obj->caract->strength = my_getnbr_free(get_next_line(0));
      my_printf(1, "Give critical to your object : ");
      obj->caract->critical = my_getnbr_free(get_next_line(0));
      my_printf(1, "Give intellect to your object : ");
      obj->caract->intellect = my_getnbr_free(get_next_line(0));
      my_printf(1, "Give armor to your object : ");
      obj->caract->armor = my_getnbr_free(get_next_line(0));
      my_printf(1, "Give agility to your object : ");
      obj->caract->agility = my_getnbr_free(get_next_line(0));
    }
  my_printf(1, "\nChoose a sprite id for your object : ");
  obj->sprite_id = get_existing_sprite(ini);
  if ((obj->texture_hitbox = xmalloc(sizeof(t_hitbox),
				     &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\ntop left position in the sprite\nx : ");
  obj->texture_hitbox->x = get_x_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "y : ");
  obj->texture_hitbox->y = get_y_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "\nwidth in the sprite : ");
  obj->texture_hitbox->width = get_x_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "height in the sprite : ");
  obj->texture_hitbox->height = get_y_pos_sprite(ini, obj->sprite_id);

  /* recap */
  my_printf(1, "\n\nHere is your item\nid: %d\n", obj->object_id);
  my_printf(1, "name: %s\n", obj->name);
  my_printf(1, "damage: %d\n", obj->damage);
  my_printf(1, "is equipable: %d\n", obj->is_equipable);
  my_printf(1, "equipable slot: %d\n", obj->slot);
  my_printf(1, "equipable stamina: %d\n", obj->caract->stamina);
  my_printf(1, "equipable strength: %d\n", obj->caract->strength);
  my_printf(1, "equipable critical: %d\n", obj->caract->critical);
  my_printf(1, "equipable intellect: %d\n", obj->caract->intellect);
  my_printf(1, "equipable armor: %d\n", obj->caract->armor);
  my_printf(1, "equipable agility: %d\n", obj->caract->agility);
  my_printf(1, "sprite id: %d\n", obj->sprite_id);
  my_printf(1, "sprite pos x: %d\n", obj->texture_hitbox->x);
  my_printf(1, "sprite pos y: %d\n", obj->texture_hitbox->y);
  my_printf(1, "sprite width: %d\n", obj->texture_hitbox->width);
  my_printf(1, "sprite height: %d\n", obj->texture_hitbox->height);

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
      list_add_new_object(ini->scene, obj);
      my_printf(1, "Object added in your ini file :D\nYou can write it using");
      my_printf(1, " 'write ini path_to_file.ini'\n\n");
    }
}
