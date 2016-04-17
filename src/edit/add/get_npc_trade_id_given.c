/*
** get_npc_trade_id_given.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 05:17:43 2016 Victor Sousa
** Last update Sun Apr 17 05:32:03 2016 Victor Sousa
*/

#include		"main.h"

int			get_npc_trade_amount_given(t_ini *ini)
{
  char			*str;
  int			id;

  (void)ini;
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str) - 1) <= -1)
    {
      my_printf(1, "amount must be superior to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  return (id);
}


int			get_npc_trade_id_given(t_ini *ini)
{
  char			*str;
  int			id;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str) - 1) <= -1)
    {
      my_printf(1, "Id must be superior to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (object_id_is_taken(ini, id) == 0)
    {
      my_printf(1, "No object found with this id\n");
      return (get_npc_trade_id_given(ini));
    }
  return (id);
}
