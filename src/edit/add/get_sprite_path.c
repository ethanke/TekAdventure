/*
** get_sprite_path.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 03:08:37 2016 Victor Sousa
** Last update Sun Apr 17 07:45:23 2016 Victor Sousa
*/

#include		"main.h"

int			sprite_path_is_taken(t_ini *ini, char *path)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->path, path) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*get_sprite_path(t_ini *ini)
{
  char			*str;
  int			fd;

  (void)ini;
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  while ((fd = open(str, O_RDONLY)) == -1)
    {
      my_printf(1, "Could not open requested path, there is nothing there\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (NULL);
    }
  close(fd);
  if (sprite_path_is_taken(ini, str) == 1)
    {
      my_printf(1, "A sprite with this path is already loaded\n");
      return (NULL);
    }
  return (str);
}
