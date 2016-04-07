/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Thu Apr  7 22:48:51 2016 Philippe Lefevre
*/

#include		"parsing.h"
#include		"object.h"
#include		<stdio.h>

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_object		*objet;
  t_object		*tmp;
  int			i;
  /* #Le commentaire pour le moulinette et se souvenir de delete stdio.h apres avoir finir les test */

  ini = bunny_load_ini(file);
  objet = load_object(ini, ptr_list);
  tmp = objet;
  i = 0;
  while (tmp != NULL)
    {
      printf("name (%s) - damage (%d) - id (%d)\n", tmp->name, tmp->damage, i++);
      tmp = tmp->next;
    }
  return (0);
}
