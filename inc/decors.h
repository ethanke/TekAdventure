/*
** decors.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Mon Apr 11 19:27:29 2016 Gaëtan Léandre
*/

#ifndef			DECORS_H_
# define		DECORS_H_

typedef struct		s_breakable
{
  unsigned int		is_breakable;
  unsigned int		life;
  unsigned int		breakable_by;
  unsigned int		lootable;
  unsigned int		loot[2];
}			t_breakable;

typedef struct		s_decors
{
  char			*name;
  int			decors_id;
  int			sprite_id;
  t_texture		*texture;
  t_hitbox		*texture_hitbox;
  t_breakable		*decors_breakable;
  struct s_decors	*prev;
  struct s_decors	*next;
}			t_decors;

t_decors		*load_decors(t_bunny_ini *ini, t_ptr_list **ptr_list);

#endif			/* !DECORS_H_ */
