/*
** write_ini.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/write/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 09:39:48 2016 Victor Sousa
** Last update Sat Apr 16 09:44:46 2016 Victor Sousa
*/

#include		"main.h"

int			write_ini(char *path, t_ini *ini)
{
  int   fd;

  if ((fd = open(path, O_WRONLY | O_CREAT, 0666)) == -1)
    {
      my_printf(1, "Could not open specified path.");
      return (-1);
    }
  aff_all(fd, ini);
  close(fd);
  return (0);
}
