/*
** add_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 19:48:52 2016 Victor Sousa
** Last update Sat Apr 16 21:27:13 2016 Victor Sousa
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

  /* recap */
  my_printf(1, "id: %d\n", obj->object_id);
  my_printf(1, "name: %f\n", obj->name);
  my_printf(1, "name: %d\n", obj->name);
}
