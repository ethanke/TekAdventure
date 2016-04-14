/*
** disp.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Apr  7 03:01:13 2016 victor sousa
** Last update Thu Apr 14 03:48:11 2016 Gaëtan Léandre
*/

#ifndef 		DISP_H_
# define 		DISP_H_

#ifndef 		ITEM_INFO_SIZE_
# define 		ITEM_INFO_SIZE_
# define		IIS_WIDTH	165
# define		IIS_HEIGHT	60
#endif			/* !ITEM_INFO_SIZE_ */

void			disp_hotbar(t_prog *prog, t_bunny_position *m_pos);
void			disp_inventory(t_prog *prog);
void			disp_item_info(t_prog *prog, t_item *item,
				       t_bunny_position *pos);
void			disp_selected_hotbar_inv_item(t_prog *prog);
void			disp_selected_full_inv_item(t_prog *prog);
void			disp_ground(t_prog *prog, int disp);
void			disp_npc_exchange(t_prog *prog, t_npc *npc);
void			disp_npc(t_prog *prog, t_npc *npc);
void			disp_player(t_prog *prog, t_player *player);
void			disp_choose_npc_action(t_prog *prog);
int	 		get_highlight(t_prog *prog, t_bunny_position *pos);
void			put_grille(t_prog *prog, t_bunny_position *gri,
				   float percent, t_bunny_pixelarray *pix);
int			set_hitbox_ground(t_scene *scene, t_ptr_list *ptr_list);
t_grille		get_grille_param(t_hitbox *place,
					 t_scene *scene);
t_hitbox		*set_decors_hitbox(t_grille *grille, t_decors *decors,
					   t_bunny_position *pos,
					   t_ptr_list *ptr_list);
t_hitbox		*set_npc_hitbox(t_grille *grille, t_npc *npc,
					t_bunny_position *pos,
					t_ptr_list *ptr_list);
int			get_pos_y(int y, t_grille *grille);
t_grille		get_grille_param(t_hitbox *place,
					 t_scene *scene);
int			calc_x_h(t_grille *grille, t_bunny_position *pos,
				 float percent, int x);
void			interact_npc(t_prog *prog, t_npc *npc);
float			calc_case_x(t_grille *grille, int pos_y,
				    t_bunny_position *palier, int y);
t_grille		get_grille_with_place(t_scene *scene);
void			disp_background(t_sky *sky, t_bunny_pixelarray *pix,
					float percent);

#endif			/* !DISP_H_ */
