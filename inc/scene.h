/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Sat Apr  9 09:49:08 2016 Philippe Lefevre
*/

#ifndef			SCENE_H_
# define		SCENE_H_
# include		"main.h"

typedef struct 		s_ground
{
  t_npc			*npc;
  t_decors		*decors;
}			t_ground;

typedef struct		s_scene
{
  unsigned int		height;
  t_texture		*sol;
  t_bunny_position	size;
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
