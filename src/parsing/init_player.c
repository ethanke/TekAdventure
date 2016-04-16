/*
** init_player.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/parsing/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 00:45:34 2016 Gaëtan Léandre
** Last update Sun Apr 17 01:02:35 2016 Gaëtan Léandre
*/

#include		"main.h"

void			init_player(t_prog *prog)
{
  t_player 		*player;

  player = prog->player;
  player->down.pos = 0;
  player->down.max = 2;
  player->down.texture = player->sprite;
  player->down.hitbox = create_hitbox(0, 0, 33, 31);
  player->up.pos = 0;
  player->up.max = 2;
  player->up.texture = player->sprite;
  player->up.hitbox = create_hitbox(0, 31, 33, 31);
  player = prog->player;
  player->right.pos = 0;
  player->right.max = 2;
  player->right.texture = player->sprite;
  player->right.hitbox = create_hitbox(0, 62, 33, 31);
  player = prog->player;
  player->left.pos = 0;
  player->left.max = 2;
  player->left.texture = player->sprite;
  player->left.hitbox = create_hitbox(0, 93, 33, 31);
}
