/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Thu Apr  7 00:03:22 2016 Philippe Lefevre
*/

#ifndef			SCENE_H_
# define		SCENE_H_
# include		"pnj.h"
# include		"objet.h"
# include		"decors.h"

typedef struct		s_scene
{
  t_texture		*sprite;
  t_hitbox		*sprite_hitbox;
  t_pnj			*pnj;
  t_objet		*objet;
  t_decors		*decors;
}			t_scene;

#endif			/* !SCENE_H_ */
