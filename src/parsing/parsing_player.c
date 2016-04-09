/*
** parsing_player.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 00:59:55 2016 Ethan Kerdelhue
** Last update Sat Apr  9 07:15:33 2016 Philippe Lefevre
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
  int		i;
  t_player	*player;
  char		*tmp;

  i = -1;
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
  player->inventory = xmalloc(sizeof(t_item) * (SIZE_INVENTORY + 1), ptr_list);
  while (++i != SIZE_INVENTORY)
    {
      tmp = (char *)bunny_ini_get_field(ini, "player", "inventory", i);
      get_item_id(tmp, &player->inventory[i].id,
		  &player->inventory[i].amount);
      player->inventory[i].selected = 0;
    }
  player->inventory[i].id = 0;
  player->inventory[i].amount = 0;
  player->inventory[i].selected = 0;
  return (player);
}
