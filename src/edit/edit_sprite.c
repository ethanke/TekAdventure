/*
** edit_sprite.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 07:19:26 2016 Victor Sousa
** Last update Sun Apr 17 07:43:19 2016 Victor Sousa
*/

#include		"main.h"

static void		edit_cur_sprite(t_ini *ini, t_sprite *spr)
{
  char			*str;

  my_printf(1, "What do you want to edit?\n1: id\n2: path\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "1") && my_strcmp(str, "2"))
    {
      free(str);
      my_printf(1, "\nWrong input, choose between 1, 2\n");
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  if (my_strcmp(str, "1") == 0)
    {
      my_printf(1, "\nGive me a new id for your sprite : ");
      spr->id = get_sprite_id(ini);
    }
  if (my_strcmp(str, "2") == 0)
    {
      my_printf(1, "\nGive me a new path for your sprite : ");
      spr->path = get_sprite_path(ini);
    }
}

void			edit_sprite(t_ini *ini)
{
  int			id;
  char			*str;

  my_printf(1, "\nWich one do you want to edit?\n");
  my_printf(1, "Select from and id : \n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while ((id = my_getnbr(str)) - 1 <= -1 || sprite_id_is_taken(ini, id) == 0)
    {
      my_printf(1, "No sprite found with this Id\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  edit_cur_sprite(ini, look_for_sprite(ini, id));
}
