/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Fri Apr  8 04:27:37 2016 Ethan Kerdelhue
*/

#include		"parsing.h"
#include		"object.h"
#include		"decors.h"

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;

  ini = bunny_load_ini(file);
  (void) ini;
  return (0);
}
