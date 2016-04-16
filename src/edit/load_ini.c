/*
** load_ini.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 07:13:00 2016 Victor Sousa
** Last update Sat Apr 16 07:51:38 2016 Victor Sousa
*/

#include		"main.h"

int			load_ini(char *path, t_ini *ini)
{
  if (open(path, O_RDONLY) == -1)
    return (-1);
  ini->ptr_list = NULL;
  if ((ini->scene = parsing(path, &ini->player, &ini->ptr_list)) == NULL)
    return (-1);
  return (0);
}
