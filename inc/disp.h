/*
** disp.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Apr  7 03:01:13 2016 victor sousa
** Last update Sat Apr  9 12:02:18 2016 Gaëtan Léandre
*/

#ifndef 		DISP_H_
# define 		DISP_H_

# include		"main.h"

void			disp_hotbar(t_prog *prog);
void			disp_inventory(t_prog *prog);
void			disp_ground(t_scene *scene, t_bunny_pixelarray *pix,
				    float percent);
void			set_hitbox_ground(t_scene *scene, t_ptr_list *ptr_list);
void			put_grille(t_ground *ground, t_bunny_position *grille,
				   float percent, t_bunny_pixelarray *pix);
t_grille		get_grille_param(t_hitbox *place,
					 t_bunny_position *size);
t_hitbox		*set_decors_hitbox(t_grille *grille, t_decors *decors,
					   t_bunny_position *pos,
					   t_ptr_list *ptr_list);
t_hitbox		*set_npc_hitbox(t_grille *grille, t_npc *npc,
					t_bunny_position *pos,
					t_ptr_list *ptr_list);

#endif			/* !DISP_H_ */
