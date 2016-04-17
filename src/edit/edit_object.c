/*
** edit_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 07:21:11 2016 Victor Sousa
** Last update Sun Apr 17 08:43:43 2016 Victor Sousa
*/

#include		"main.h"

static void		pick_what_to_edit_(t_ini *ini, t_object *obj, int act)
{
  if (act == 5)
    {
      if ((obj->is_equipable = get_obj_equipable(ini)) == -1)
	return;
    }
  if (act == 6)
    get_object_caract(ini, obj);
  if (act == 7)
    {
      my_printf(1, "\nGive me a new sprite id for your object : ");
      obj->sprite_id = get_existing_sprite(ini);
      if ((obj->texture_hitbox = xmalloc(sizeof(t_hitbox),
					 &ini->ptr_list)) == NULL)
	return;
    }
  if (act == 8)
    get_object_sprite_info(ini, obj);
}

static void		pick_what_to_edit(t_ini *ini, t_object *obj, int act)
{
  if (act == 1)
    {
      my_printf(1, "\nGive me a new id for your object : ");
      obj->object_id = get_obj_id(ini);
    }
  if (act == 2)
    {
      my_printf(1, "\nGive me a new name for your object : ");
      obj->name = get_obj_name(ini);
    }
  if (act == 3)
    {
      my_printf(1, "\nGive me a new damage value for your object : ");
      obj->damage = my_getnbr_free(get_next_line(0));
    }
  if (act == 4)
    {
      my_printf(1, "\nDo you want to make the object equipable : ");
      if ((obj->is_equipable = get_obj_equipable(ini)) == -1)
        return;
    }
  pick_what_to_edit_(ini, obj, act);
}

static void		edit_cur_object(t_ini *ini, t_object *obj)
{
  char			*str;

  my_printf(1, "What do you want to edit?\n1: id\n2: name\n3: damage\n");
  my_printf(1, "4: is_equipable\n5: slot\n6: caract\n7: sprite_id\n");
  my_printf(1, "8: texture_hitbox\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "1") && my_strcmp(str, "2") && my_strcmp(str, "3") &&
	 my_strcmp(str, "4") && my_strcmp(str, "5") && my_strcmp(str, "6") &&
	 my_strcmp(str, "7") && my_strcmp(str, "8"))
    {
      free(str);
      my_printf(1, "\nWrong input, choose between 1, 2, 3, 4, 5, 6, 7, 8\n");
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  pick_what_to_edit(ini, obj, my_getnbr_free(str));
}

void			edit_object(t_ini *ini, int id, char *str)
{
  my_printf(1, "\nWich one do you want to edit?\n");
  my_printf(1, "Select from and id : \n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while ((id = my_getnbr(str)) - 1 <= -1 || object_id_is_taken(ini, id) == 0)
    {
      my_printf(1, "No sprite found with this Id\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  my_printf(1, "Selected object is %s, are you sure\n",
	    look_for_obj_name(ini, id));
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
    edit_cur_object(ini, look_for_obj(ini, id));
}
