/*
** parsing.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:08:59 2016 Philippe Lefevre
** Last update Fri Apr  8 02:00:21 2016 Ethan Kerdelhue
*/

#include		"parsing.h"
#include		"object.h"

int			parsing(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_ini		*ini;
  t_object		*objet;
  t_object		*tmp;
  t_sprite		*sprite;
  t_sprite		*tmp2;
  t_player		*player;
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
  if ((sprite = load_sprite(ini, ptr_list)) == NULL)
    return (-1);
  tmp2 = sprite;
  i = 0;
  while (tmp2 != NULL)
    {
      printf("path (%s) - id (%d) - id (%d)\n", tmp2->path, tmp2->id, i++);
      tmp2 = tmp2->next;
    }
  player = load_player(ini, ptr_list);
  printf("name (%s) - life (%d) - token (%d)", player->name, player->life, player->token);
  i = 0;
  while (i != SIZE_INVENTORY)
    {
      printf("object id (%d) - amound (%d)", player->inventory[i].id, player->inventory[i].amount);
      i++;
    }
  return (0);
}
