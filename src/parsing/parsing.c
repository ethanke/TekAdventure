/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Thu Apr  7 23:41:37 2016 Philippe Lefevre
*/

#include		"parsing.h"
#include		"object.h"

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_object		*objet;
  t_object		*tmp;
  int			i;

  ini = bunny_load_ini(file);
  if ((objet = load_object(ini, ptr_list)) == NULL)
    return (-1);
  tmp = objet;
  i = 0;
  while (tmp != NULL)
    {
      printf("name (%s) - damage (%d) - id (%d)\n", tmp->name, tmp->damage, i++);
      tmp = tmp->next;
    }
  return (0);
}
