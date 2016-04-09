/*
** parsing_player.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 00:59:55 2016 Ethan Kerdelhue
** Last update Sat Apr  9 09:43:55 2016 Philippe Lefevre
*/

#include	"main.h"

static t_player	*my_puterror_n(char *str)
{
  t_player 	*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

int		get_item_id(char *str, int *id, int *amount)
{
  int            i;

  (*id) = -1;
  (*amount) = -1;
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
  t_player	*player;
  char		*tmp;
  int		inventory_count;
  int		slot;
  int		i;
  int		j;

  player = NULL;
  if ((player = xmalloc(sizeof(t_player), ptr_list)) == NULL)
    return (my_puterror_n("Malloc fail"));
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "life", 0)) == NULL)
      return (my_puterror_n("No field life in player scope"));
  player->life = my_getnbr(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "token", 0)) == NULL)
      return (my_puterror_n("No field token in player scope"));
  player->token = my_getnbr(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "name", 0)) == NULL)
      return (my_puterror_n("No field name in player scope"));
  player->name = tmp;
  player->inventory = NULL;
  if ((player->inventory = xmalloc(sizeof(t_item) * (SIZE_INVENTORY + 1), ptr_list)) == NULL)
    return (NULL);
  i = -1;
  while (++i != SIZE_INVENTORY)
    {
      player->inventory[i].id = 0;
      player->inventory[i].amount = 0;
    }
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "inventory_count", 0)) == NULL)
    return (my_puterror_n("Error: player or player:inventory_count not set"));
  inventory_count = my_getnbr(tmp);
  i = -1;
  while (++i < inventory_count)
    {
      if ((tmp = (char *)bunny_ini_get_field(ini, "player", "inventory", i)) == NULL)
	return (my_puterror_n("Error: player or player:inventory not set"));
      j = -1;
      slot = my_getnbr(tmp);
      while (tmp[++j] && tmp[j] != ';');
      player->inventory[slot].id = my_getnbr(tmp + j + 1);
      while (tmp[++j] && tmp[j] != ';');
      player->inventory[slot].amount = my_getnbr(tmp + j + 1);
    }
  return (player);
}
