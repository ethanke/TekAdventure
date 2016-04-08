/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Fri Apr  8 07:33:09 2016 Philippe Lefevre
*/

#ifndef			SCENE_H_
# define		SCENE_H_
# include		"main.h"

typedef struct		s_scene
{
  t_texture		*ground;
  unsigned int		height;
  t_bunny_position	size;
  t_sprite		*sprite;
  t_back		*back;
  t_npc			*npc;
  t_object		*object;
  t_decors		*decors;
  struct t_scene	*prev;
  struct t_scene	*next;
}			t_scene;

#endif			/* !SCENE_H_ */
