/*
** write_player.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 08:11:18 2016 Gaëtan Léandre
** Last update Sat Apr 16 22:57:52 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			write_player_amount(t_player *player, int fd, int size)
{
  int			i;
  int			pos;

  i = 0;
  pos = 0;
  my_printf(fd, "player_inventory_amount=");
  i = 0;
  pos = 0;
  while (i < SIZE_INVENTORY + 4)
    {
      if (player->inventory[i].id != -1)
	{
	  if (pos != size - 1)
	    my_printf(fd, "\"%d\", ", player->inventory[i].amount);
	  else
	    my_printf(fd, "\"%d\"\n", player->inventory[i].amount);
	  pos++;
	}
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_player_item(t_player *player, int fd, int size)
{
  int			i;
  int			pos;

  i = 0;
  pos = 0;
  my_printf(fd, "player_inventory_item=");
  i = 0;
  pos = 0;
  while (i < SIZE_INVENTORY + 4)
    {
      if (player->inventory[i].id != -1)
	{
	  if (pos != size - 1)
	    my_printf(fd, "\"%d\", ", player->inventory[i].id);
	  else
	    my_printf(fd, "\"%d\"\n", player->inventory[i].id);
	  pos++;
	}
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_player_slot(t_player *player, int fd, int size)
{
  int			i;
  int			pos;

  i = 0;
  pos = 0;
  my_printf(fd, "player_inventory_slot=");
  i = 0;
  pos = 0;
  while (i < SIZE_INVENTORY + 4)
    {
      if (player->inventory[i].id != -1)
	{
	  if (pos != size - 1)
	    my_printf(fd, "\"%d\", ", i);
	  else
	    my_printf(fd, "\"%d\"\n", i);
	  pos++;
	}
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_player(t_player *player, int fd)
{
  int			i;
  int			size;
  my_printf(fd, "[player]\nplayer_name=\"%s\"\n", player->name);
  my_printf(fd, "player_life=\"%d\"\n", player->life);
  i = 0;
  size = 0;
  while (i < SIZE_INVENTORY + 4)
    {
      if (player->inventory[i].id != -1)
	size++;
      i++;
    }
  my_printf(fd, "player_inventory_count=\"%d\"\n", size);
  write_player_slot(player, fd, size);
  write_player_item(player, fd, size);
  write_player_amount(player, fd, size);
  my_printf(fd, "player_sprite_id=\"%d\"\n", player->sprite_id);
  my_printf(fd, "\n\n");
}
