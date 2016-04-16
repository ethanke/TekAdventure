/*
** write_player.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 08:11:18 2016 Gaëtan Léandre
** Last update Sat Apr 16 08:22:58 2016 Gaëtan Léandre
*/

#include 		"main.h"

int			write_player(t_player *player, int fd)
{
  int			i;
  int			size;
  my_printf(fd, "[player]\nplayer_name=\"%s\"\n", player->name);
  my_printf(fd, "player_life=\"%d\"\n", player->life);
  my_printf(fd, "player_inventory_count=\"%d\"\n", player->name);
  i = 0;
  while (i < SIZE_INVENTORY + 4)
    {
      
      i++;
    }

  my_printf(fd, "\n\n");
}
