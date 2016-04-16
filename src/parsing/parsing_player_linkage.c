/*
** parsing_player_linkage.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 03:00:55 2016 Philippe Lefevre
** Last update Sat Apr 16 08:13:59 2016 Philippe Lefevre
*/

#include		"main.h"

t_item			*link_inventory_item(t_item *inventory, t_object *object)
{
  t_object		*tmp_object;
 int			i;

  i = -1;
  /* verifie que les item id dans linventaire existe */
  while (++i != SIZE_INVENTORY)
    {
      tmp_object = object;
      while (tmp_object != NULL)
	{
	  if (tmp_object->object_id == inventory[i].id)
	    inventory[i].object = tmp_object;
	  tmp_object = tmp_object->next;
	}
    }
  return (inventory);
}

t_player		*link_player(t_player *player, t_sprite *sprite)
{
  t_player		*tmp_player;
  t_sprite		*tmp_sprite;
/* verifie que le player ne spawn pas sur une case' deja alloué */
  tmp_player = player;
  tmp_sprite = sprite;
  while (tmp_sprite != NULL)
    {
      if (tmp_sprite->id == tmp_player->sprite_id)
	tmp_player->sprite = tmp_sprite->sprite;
      tmp_sprite = tmp_sprite->next;
    }
  return (player);
}
