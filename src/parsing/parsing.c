/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
<<<<<<< HEAD
** Last update Fri Apr  8 02:36:39 2016 Philippe Lefevre
=======
** Last update Fri Apr  8 02:00:21 2016 Ethan Kerdelhue
>>>>>>> 89e0bab1d782284a1af42477a1499fb336f21ee5
*/

#include		"parsing.h"
#include		"object.h"
#include		"decors.h"

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;

  ini = bunny_load_ini(file);
  (void)ini;
  return (0);
}
