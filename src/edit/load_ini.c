/*
** load_ini.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 07:13:00 2016 Victor Sousa
** Last update Sat Apr 16 07:18:20 2016 Victor Sousa
*/

#include		"main.h"

t_ini			*load_ini(char *path)
{
  t_ini			*ini;

  if (open(path, O_RDONLY))
    return (NULL);
  if ((ini = xmalloc(sizeof(t_ini), &prog->ptr_list)) == NULL)
    return (NULL);
  return (parsing(path, &prog->player, &prog->ptr_list)) == NULL))
}
