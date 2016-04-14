/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Thu Apr 14 06:41:31 2016 Gaëtan Léandre
*/

#ifndef			SCENE_H_
# define		SCENE_H_

# define		EQUART		100

typedef struct		s_grille
{
  int			start_y;
  int			case_x;
  int			case_y;
  int			size_x;
  int			height;
  int			grille_x;
  int			grille_y;
  int			coef;
}			t_grille;

typedef struct		s_gate
{
  int			id;
  char			*name;
  int			sprite_id;
  struct s_scene	*scene;
  t_texture		*texture;
  t_hitbox		*texture_hitbox;
  struct s_gate		*prev;
  struct s_gate		*next;
}			t_gate;

typedef struct 		s_ground
{
  t_hitbox		*hitbox_npc;
  t_npc			*npc;
  t_hitbox		*hitbox_decors;
  t_decors		*decors;
  t_hitbox		*hitbox_gate;
  t_gate		*gate;
}			t_ground;

typedef struct		s_sky
{
  int			sky_sprite_id;
  t_texture		*texture;
  t_hitbox		*hitbox;
  int			distance;
  struct s_sky		*prev;
  struct s_sky		*next;
}			t_sky;

typedef struct		s_scene
{
  t_bunny_position	*start_pos;
  unsigned int		height;
  int			sol_id;
  t_texture		*sol;
  t_hitbox		*sol_hitbox;
  t_bunny_position	size;
  float			coef;
  t_sprite		*sprite; /* Ne pas utilser temporaire */
  t_npc			*npc;	/* Ne pas utilser temporaire */
  t_object		*object; /* Ne pas utilser temporaire */
  t_decors		*decors; /* Ne pas utilser temporaire */
  t_player		*player; /* Ne pas utilser temporaire */
  t_ground		*ground;
  t_sky			*sky;
  struct s_scene	*prev;
  struct s_scene	*next;
}			t_scene;

#endif			/* !SCENE_H_ */
