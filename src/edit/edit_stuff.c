/*
** edit_stuff.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 07:17:21 2016 Victor Sousa
** Last update Sun Apr 17 09:56:01 2016 Victor Sousa
*/

#include		"main.h"

void			pick_what_to_edit(char *str, t_ini *ini)
{
  (void)ini;
  if (my_strcmp(str, "1") == 0)
    edit_sprite(ini);
  if (my_strcmp(str, "2") == 0)
    edit_object(ini, 0, NULL);
  if (my_strcmp(str, "3") == 0)
    edit_decors(ini);
  if (my_strcmp(str, "4") == 0)
    edit_npc(ini, 0, NULL);
  if (my_strcmp(str, "5") == 0)
    my_printf(1, "edit scene\n");
}

void			edit_stuff(t_ini *ini)
{
  char			*str;

  if (ini->has_been_loaded == 0)
    {
      my_printf(1, "No ini file load. Use \"load ini path_to_file.ini\"\n");
      return;
    }
  my_printf(1, "What do you want to edit?\n1: sprite\n2: object\n3: decors\n");
  my_printf(1, "4: npc\n5: scene\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "1") && my_strcmp(str, "2") && my_strcmp(str, "3") &&
	 my_strcmp(str, "4") && my_strcmp(str, "5"))
    {
      free(str);
      my_printf(1, "\nWrong input, choose between 1, 2, 3, 4, 5\n");
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  pick_what_to_edit(str, ini);
}
