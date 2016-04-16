/*
** add_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 19:48:52 2016 Victor Sousa
** Last update Sat Apr 16 20:34:26 2016 Victor Sousa
*/

#include		"main.h"

void			add_object(t_ini *ini)
{
  t_object		*obj;

  if ((obj = xmalloc(sizeof(t_object), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "Give and id to your object : ");
  if ((obj->object_id = get_id(ini)) == -1)
    return;

  /* recap */
  my_printf(1, "id: %d\n", obj->object_id);
}
