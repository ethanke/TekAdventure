/*
** get_obj_equipable.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 21:30:52 2016 Victor Sousa
** Last update Sat Apr 16 21:37:12 2016 Victor Sousa
*/

#include		"main.h"

int			get_obj_equipable(t_ini *ini)
{
  char			*str;

  (void)ini;
  my_printf(1, "Is your object wearable?  (yes or no)\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (my_strcmp(str, "yes") == 0)
    return (1);
  return (0);
}
