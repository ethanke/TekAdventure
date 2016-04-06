/*
** decors.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Wed Apr  6 23:47:44 2016 Philippe Lefevre
*/

#ifndef			DECORS_H_
# define		DECORS_H_

typedef struct		s_breakable
{
  unsigned int		is_breakable;
  unsigned int		vie;
  unsigned int		*break_by;
  unsigned int		lootable;
  unsigned int		**loot;
}			t_breakable;

typedef struct		s_decors
{
  unsigned int		decors_id;
  t_texture		*sprite;
  t_hitbox		*sprite_hitbox;
  t_breakable		breakable;
}			t_decors;

int			parsing(const char *file);

#endif			/* !DECORS_H_ */
