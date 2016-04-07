/*
** scene.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Thu Apr  7 06:27:49 2016 Philippe Lefevre
*/

#ifndef			SCENE_H_
# define		SCENE_H_
# include		"pnj.h"
# include		"objet.h"
# include		"decors.h"

typedef struct		s_scene
{
  t_texture		*ground;
  unsigned int		height;
  t_bunny_position	size;
  t_back		*back;
  t_pnj			*pnj;
  t_objet		*objet;
  t_decors		*decors;
  struct t_scene	*prev;
  struct t_scene	*next;
}			t_scene;

#endif			/* !SCENE_H_ */
