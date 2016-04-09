/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Sat Apr  9 07:30:57 2016 Philippe Lefevre
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
  t_texture		*texture;
  t_bunny_position	size;
  t_sprite		*sprite;
  t_npc			*npc;
  t_object		*object;
  t_decors		*decors;
  t_player		*player;
  t_ground		*ground;
  struct t_scene	*prev;
  struct t_scene	*next;
}			t_scene;

#endif			/* !SCENE_H_ */
