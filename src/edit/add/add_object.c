/*
** add_object.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 19:48:52 2016 Victor Sousa
** Last update Sat Apr 16 23:23:35 2016 Victor Sousa
*/

#include		"main.h"

void			add_object(t_ini *ini)
{
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
    obj->slot = 0;
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

  /* recap */
  my_printf(1, "\n\nid: %d\n", obj->object_id);
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
}
