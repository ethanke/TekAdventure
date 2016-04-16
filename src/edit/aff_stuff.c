/*
** aff_stuff.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 09:07:37 2016 Victor Sousa
** Last update Sat Apr 16 19:12:51 2016 Victor Sousa
*/

#include		"main.h"

void			aff_all(int fd, t_ini *ini)
{
  write_sprite(ini->scene->sprite, fd);
  write_player(ini->player, fd);
  write_object(ini->scene->object, fd);
  write_decors(ini->scene->decors, fd);
}

void			aff_stuff(int ac, char **av, t_ini *ini)
{
  /* try aff player */
  if (ini->has_been_loaded == 0)
    {
      my_printf(1, "No ini file load. Use \"load ini path_to_file.ini\"\n");
      return;
    }
  if (ac == 1)
    aff_all(1, ini);
  if (ac == 2 && my_strcmp(av[1], "player") == 0)
    write_player(ini->player, 1);
  if (ac == 2 && my_strcmp(av[1], "sprite") == 0)
    write_sprite(ini->scene->sprite, 1);
  if (ac == 2 && my_strcmp(av[1], "object") == 0)
    write_object(ini->scene->object, 1);
  if (ac == 2 && my_strcmp(av[1], "decors") == 0)
    write_decors(ini->scene->decors, 1);
}
