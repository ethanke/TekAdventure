/*
** parsing_player.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 00:59:55 2016 Ethan Kerdelhue
** Last update Fri Apr  8 02:21:40 2016 Ethan Kerdelhue
*/

#include	"main.h"

int		get_item_id(char *str, int *id, int *amount)
{
  int            i;

  (*id) = 0;
  (*amount) = 0;
  if (str != NULL)
    {
      (*id) = my_getnbr(str);
      i = -1;
      while (str[++i] && str[i] != ';');
      (*amount) = my_getnbr(str + i + 1);
    }
  return (0);
}

t_player	*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  int		i;
  t_player	*player;
  char		*tmp;

  i = -1;
  player = NULL;
  player = xmalloc(sizeof(t_player), ptr_list);
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "life", 0)) == NULL)
      return (NULL);
  player->life = my_getnbr(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "token", 0)) == NULL)
      return (NULL);
  player->token = my_getnbr(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "name", 0)) == NULL)
      return (NULL);
  player->name = tmp;
  player->inventory = xmalloc(sizeof(t_item) * SIZE_INVENTORY, ptr_list);
  while (++i != SIZE_INVENTORY)
    {
      tmp = (char *)bunny_ini_get_field(ini, "player", "inventory", i);
      get_item_id(tmp, &player->inventory[i].id,
		  &player->inventory[i].amount);
    }
  return (player);
}
