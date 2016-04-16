/*
** get_obj_equip_slot.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 21:38:21 2016 Victor Sousa
** Last update Sat Apr 16 21:42:39 2016 Victor Sousa
*/

#include		"main.h"

int			get_obj_equip_slot()
{
  char			*str;

  my_printf(1, "In which slot?\n1: head\n2: body\n3: legs\n4:foot\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while (my_strcmp(str, "1") && my_strcmp(str, "2") && my_strcmp(str, "3") &&
	 my_strcmp(str, "4"))
    {
      my_printf(1, "\n1: head\n2: body\n3: legs\n4:foot\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  return (my_getnbr(str));
}
