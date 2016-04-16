/*
** add_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 19:48:52 2016 Victor Sousa
** Last update Sat Apr 16 21:44:46 2016 Victor Sousa
*/

#include		"main.h"

void			add_object(t_ini *ini)
{
  t_object		*obj;

  if ((obj = xmalloc(sizeof(t_object), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "Give and id to your object : ");
  if ((obj->object_id = get_obj_id(ini)) == -1)
    return;
  my_printf(1, "Give a name to your object : ");
  if ((obj->name = get_obj_name(ini)) == NULL)
    return;
  my_printf(1, "Give damage to your object : ");
  obj->damage = my_getnbr(get_next_line(0));
  if ((obj->is_equipable = get_obj_equipable(ini)) == -1)
    return;
  if (obj->is_equipable == 0)
    obj->slot = 0;
  else
    obj->slot = get_obj_equip_slot();

  /* recap */
  my_printf(1, "\n\nid: %d\n", obj->object_id);
  my_printf(1, "name: %s\n", obj->name);
  my_printf(1, "name: %d\n", obj->damage);
  my_printf(1, "equipable: %d\n", obj->is_equipable);
  my_printf(1, "equipable slot: %d\n", obj->slot);
}
