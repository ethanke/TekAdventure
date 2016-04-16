/*
** disp.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Apr  7 03:01:13 2016 victor sousa
** Last update Sat Apr 16 07:19:01 2016 Victor Sousa
*/

#ifndef 		DISP_H_
# define 		DISP_H_

#ifndef 		ITEM_INFO_SIZE_
# define 		ITEM_INFO_SIZE_
# define		IIS_WIDTH	180
# define		IIS_HEIGHT	70
#endif			/* !ITEM_INFO_SIZE_ */

#ifndef 		EQUIP_INFO_SIZE_
# define 		EQUIP_INFO_SIZE_
# define		EIS_WIDTH	(IIS_WIDTH + 35)
# define		EIS_HEIGHT	(IIS_HEIGHT + 115)
#endif			/* !EQUIP_INFO_SIZE_ */

void			disp_game_over(t_prog *prog);
void			disp_menu(t_prog *prog);
t_bunny_response	check_menu_button(t_prog *prog,
					  t_bunny_position *m_pos);
void			disp_hotbar(t_prog *prog, t_bunny_position *m_pos);
void			disp_inventory(t_prog *prog);
void			disp_equip(t_prog *prog, t_bunny_position *m_pos);
void			disp_item_info(t_prog *prog, t_item *item,
				       t_bunny_position *pos);
void			disp_equip_info(t_prog *prog, t_item *item,
					t_bunny_position *pos);
void			disp_quatity(t_prog *prog, t_font font, t_item *item,
				     t_bunny_position rect_pos);
void			disp_damage(t_prog *prog, t_font font, t_item *item,
				    t_bunny_position rect_pos);
void			disp_floating_item(t_prog *prog,
					   t_bunny_position *click_pos);
void			disp_stamina(t_prog *prog, t_font *font, t_item *item,
				     t_bunny_position rect_pos);
void			disp_strength(t_prog *prog, t_font *font, t_item *item,
				      t_bunny_position rect_pos);
void			disp_critical(t_prog *prog, t_font *font, t_item *item,
				      t_bunny_position rect_pos);
void			disp_intel(t_prog *prog, t_font *font, t_item *item,
				   t_bunny_position rect_pos);
void			disp_armor(t_prog *prog, t_font *font, t_item *item,
				   t_bunny_position rect_pos);
void			disp_selected_hotbar_inv_item(t_prog *prog);
void			disp_selected_full_inv_item(t_prog *prog);
int			there_is_place_in_inv(t_item *inv);
void			disp_ground(t_prog *prog, int disp);
void			disp_npc_exchange(t_prog *prog, t_npc *npc);
void			disp_npc(t_prog *prog, t_npc *npc);
void 			disp_needed_item(t_prog *prog, t_npc *npc);
void			disp_player(t_prog *prog, t_player *player);
void			disp_choose_npc_action(t_prog *prog);
void			interact_decors(t_prog *prog);
void			disp_decord_life_text(t_prog *prog);
void			disp_need_tools(t_prog *prog);
void			disp_pick_item(t_prog *prog);
void			disp_cant_break(t_prog *prog);
void			disp_out_of_space(t_prog *prog);
int	 		get_highlight(t_prog *prog, t_bunny_position *pos);
void			put_grille(t_prog *prog, t_grille *gri,
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
					float percent, int height);
t_text			*create_text(t_bunny_position pos, char *text,
				     int nbr, unsigned int color);
void			add_text(t_prog *prog, t_text *text);
void			delete_from_text(t_prog *prog, t_text *save);
void			disp_font(t_prog *prog, t_text *first,
				  t_bunny_pixelarray *pix);
t_bunny_position	pos_alea(int x_min, int x_max, int y_min, int y_max);
t_object		*fint_obj_by_id(t_object *head, int id);

#endif			/* !DISP_H_ */
