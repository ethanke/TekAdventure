/*
** init_player.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/parsing/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 00:45:34 2016 Gaëtan Léandre
** Last update Sun Apr 17 02:40:01 2016 Gaëtan Léandre
*/

#include		"main.h"

void			init_player(t_prog *prog)
{
  t_player 		*player;

  player = prog->player;
  player->down.pos = 0;
  player->down.max = 6;
  player->down.texture = player->sprite;
  player->down.hitbox = create_hitbox(0, 0, 35, 34);
  player->up.pos = 0;
  player->up.max = 6;
  player->up.texture = player->sprite;
  player->up.hitbox = create_hitbox(0, 34, 35, 34);
  player->right.pos = 0;
  player->right.max = 6;
  player->right.texture = player->sprite;
  player->right.hitbox = create_hitbox(0, 68, 35, 34);
  player->left.pos = 0;
  player->left.max = 6;
  player->left.texture = player->sprite;
  player->left.hitbox = create_hitbox(0, 102, 35, 34);
  player->stop.pos = 0;
  player->stop.max = 6;
  player->stop.texture = player->sprite;
  player->stop.hitbox = create_hitbox(0, 0, 35, 34);
}
