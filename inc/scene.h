/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Sun Apr 10 21:40:26 2016 Gaëtan Léandre
*/

#ifndef			SCENE_H_
# define		SCENE_H_
# include		"main.h"

# define		EQUART		200

typedef struct		s_grille
{
  int			start_y;
  int			case_y;
  int			size_x;
  int			grille_x;
  int			grille_y;
  int			coef;
}			t_grille;

typedef struct 		s_ground
{
  t_hitbox		*hitbox_npc;
  t_npc			*npc;
  t_hitbox		*hitbox_decors;
  t_decors		*decors;
}			t_ground;

typedef struct		s_scene
{
  unsigned int		height;
  t_texture		*sol;
  t_bunny_position	size;
  float			coef;
  t_sprite		*sprite; /* Ne pas utilser temporaire */
  t_npc			*npc;	/* Ne pas utilser temporaire */
  t_object		*object; /* Ne pas utilser temporaire */
  t_decors		*decors; /* Ne pas utilser temporaire */
  t_player		*player; /* Ne pas utilser temporaire */
  t_ground		*ground;
  struct t_scene	*prev;
  struct t_scene	*next;
}			t_scene;

#endif			/* !SCENE_H_ */
