/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Fri Apr  8 02:36:39 2016 Philippe Lefevre
*/

#include		"parsing.h"
#include		"object.h"
#include		"decors.h"

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_decors		*objet;
  t_decors		*tmp;

  ini = bunny_load_ini(file);
  if ((objet = load_decors(ini, ptr_list)) == NULL)
    return (-1);
  printf("(Je suis la)\n");
  tmp = objet;
  while (tmp != NULL)
    {
      printf("breakable (%d) - breakable_by (%d)\n", tmp->decors_breakable->is_breakable, tmp->decors_breakable->breakable_by);
      tmp = tmp->next;
    }
  return (0);
}
