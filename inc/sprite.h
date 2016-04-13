/*
** sprite.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Wed Apr 13 06:16:42 2016 Victor Sousa
*/

#ifndef			SPRITE_H_
# define		SPRITE_H_

typedef struct		s_sprite
{
  int			id;
  char			*path;
  t_texture		*sprite;
  struct s_sprite	*next;
  struct s_sprite	*prev;
}			t_sprite;

#endif			/* !SPRITE_H_ */
