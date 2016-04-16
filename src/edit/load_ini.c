/*
** load_ini.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 07:13:00 2016 Victor Sousa
** Last update Sat Apr 16 09:05:46 2016 Victor Sousa
*/

#include		"main.h"

void			close_ini(t_ini *ini)
{
  if (ini->has_been_loaded == 0)
    my_printf(1, "No ini file loaded\n");
  else
    {
      my_printf(1, "unloading... please wait\n");
      free_ptr(ini->ptr_list);
      my_printf(1, "done\n\n");
      ini->has_been_loaded = 0;
    }
}

int			load_ini(char *path, t_ini *ini)
{
  char			*str;

  if (ini->has_been_loaded == 1)
    {
      my_printf(1, "An ini file is already loaded.  ");
      my_printf(1, "Do you want to unload it first?  (yes or no)\n");
      str = get_next_line(0);
      while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
	{
	  my_printf(1, "yes or no\n");
	  free(str);
	  str = get_next_line(0);
	}
      if (my_strcmp(str, "yes") == 0)
	close_ini(ini);
    }
  my_printf(1, "loading... please wait\n");
  if (open(path, O_RDONLY) == -1)
    return (-1);
  ini->ptr_list = NULL;
  if ((ini->scene = parsing(path, &ini->player, &ini->ptr_list)) == NULL)
    return (-1);
  ini->has_been_loaded = 1;
  my_printf(1, "done\n\n");
  return (0);
}
