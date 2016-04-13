/*
** parsing_player.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 00:59:55 2016 Ethan Kerdelhue
** Last update Wed Apr 13 17:08:59 2016 Philippe Lefevre
*/

#include	"main.h"

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

t_hitbox		*create_player_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: object:xmalloc failed in create_object_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "player", "player_sprite_hitbox", id)) == NULL)
    return (my_puterror_hitbox("Error: player:player_sprite_hitbox field not found\n"));
  i = -1;
  hitbox->x = my_getnbr(str);
  while (str[++i] && str[i] != ';');
  hitbox->y = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->width = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->height = my_getnbr(str + i + 1);
  return (hitbox);
}

t_item			*load_player_inventory(t_item *inventory, t_bunny_ini *ini,
					       t_ptr_list **ptr_list, char *tmp)
{
  int			inventory_count;
  int			slot;
  int			i;
  int			j;

  inventory = NULL;
  if ((inventory = xmalloc(sizeof(*inventory)
				   * (SIZE_INVENTORY + 1), ptr_list)) == NULL)
    return (NULL);
  i = -1;
  while (++i != (SIZE_INVENTORY + 1))
    {
      inventory[i].id = -1;
      inventory[i].amount = -1;
    }
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "player_inventory_count", 0)) == NULL)
    return (my_puterror_item("Error: player:player_inventory_count field not found\n"));
  if ((inventory_count = my_getnbr(tmp)) < 0)
    return (my_puterror_item("Error: player:player_inventory_count should not be negative\n"));
  else
    {
      i = -1;
      while (++i < inventory_count)
	{
	  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "player_inventory", i)) == NULL)
	    return (my_puterror_item("Error: player:player_inventory field not found\n"));
	  j = -1;
	  if (((slot = my_getnbr(tmp)) < 0) || (slot > SIZE_INVENTORY))
	    return (my_puterror_item("Error: player:player_inventory slot should not be negative or greater than the size of the inventory\n"));
	  while (tmp[++j] && tmp[j] != ';');
	  if ((inventory[slot].id = my_getnbr(tmp + j + 1)) < 0)
	    return (my_puterror_item("Error: player:player_inventory_count object id should not be negative\n"));
	  while (tmp[++j] && tmp[j] != ';');
	  if ((inventory[slot].amount = my_getnbr(tmp + j + 1)) < 0)
	    return (my_puterror_item("Error: player:player_inventory_count object amount should not be negative\n"));
	}
    }
  return (inventory);
}

t_player		*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_player		*player;
  char			*tmp;

  player = NULL;
  if ((player = xmalloc(sizeof(t_player), ptr_list)) == NULL)
    return (my_puterror_player("Error: player:xmalloc failed in load_player\n"));
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "player_life", 0)) == NULL)
      return (my_puterror_player("Error: balise player \
				 or player:life field not found\n"));
  if ((player->life = my_getnbr(tmp)) < 0)
      return (my_puterror_player("Error: player:player_life should not be negative\n"));
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "player_token", 0)) == NULL)
      return (my_puterror_player("Error: player:player_token field not found\n"));
  if ((player->token = my_getnbr(tmp)) < 0)
      return (my_puterror_player("Error: player:player_token should not be negative\n"));
  if ((tmp = (char *)bunny_ini_get_field(ini, "player", "player_name", 0)) == NULL)
      return (my_puterror_player("Error: player:player_name field not found\n"));
  if ((player->name = my_strdup(tmp, ptr_list)) == NULL)
      return (my_puterror_player("Error: player->name:my_strdup failed in load_player\n"));
  if ((player->inventory = load_player_inventory(player->inventory, ini, ptr_list, tmp)) == NULL)
      return (NULL);
  player->inv_selected = -1;
  if ((tmp = (char *)bunny_ini_get_field(ini, "player",
	      "player_sprite_id", 0)) == NULL)
      return (my_puterror_player("Error: player:player_sprite_id field not found\n"));
  if ((player->sprite_id = my_getnbr(tmp)) < 0)
    return (my_puterror_player("Error: player:player_sprite_id should not be negative\n"));
  if ((player->sprite_hitbox = create_player_hitbox(0, ini, ptr_list)) == NULL)
    return (NULL);
  return (player);
}
