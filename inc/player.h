/*
** player.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Wed Apr  6 23:53:24 2016 Philippe Lefevre
*/

#ifndef			PLAYER_H_
# define		PLAYER_H_

typedef struct		s_player
{
  unsigned int		life;
  unsigned int		token;
  char			*name;
  t_texture		*sprite;
  t_hitbox		*sprite_hitbox;
  unsigned int		**inventory;
}			t_player;

#endif			/* !PLAYER_H_ */
