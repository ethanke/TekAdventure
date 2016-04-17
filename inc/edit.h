/*
** edit.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:51:56 2016 Victor Sousa
** Last update Sun Apr 17 05:29:21 2016 Victor Sousa
*/

#ifndef			EDIT_H_
# define		EDIT_H_

# include		"main.h"

typedef struct		s_ini
{
  t_player		*player;
  t_scene		*scene;
  t_ptr_list		*ptr_list;
  int			cmd_found;
  char			has_been_loaded;
}			t_ini;

void    		clear_scr(void);
int			load_ini(char *path, t_ini *ini);
void			close_ini(t_ini *ini);
void			aff_stuff(int ac, char **av, t_ini *ini);
void			aff_all(int fd, t_ini *ini);
void			add_stuff(int ac, char **av, t_ini *ini);

/* add */
void			add_object(t_ini *ini);
void			add_sprite(t_ini *ini);
void			add_decors(t_ini *ini);
void			add_npc(t_ini *ini);
int			get_obj_id(t_ini *ini);
int			get_npc_id(t_ini *ini);
int			get_sprite_id(t_ini *ini);
char			*get_obj_name(t_ini *ini);
char			*get_sprite_path(t_ini *ini);
int			get_obj_equipable(t_ini *ini);
int			get_obj_equip_slot();
int			get_existing_sprite(t_ini *ini);
int			get_x_pos_sprite(t_ini *ini, int id);
int			get_y_pos_sprite(t_ini *ini, int id);
int			get_dec_collect(char *str, t_ini *ini);
int			get_npc_trade_amount_given(t_ini *ini);
int			get_dec_lootable(char *msg, t_ini *ini);
int			get_object(char *msg, t_ini *ini);
int			get_id_posi(char *msg, t_ini *ini);
char			*look_for_decors_name(t_ini *ini, int id);
int			decors_id_is_taken(t_ini *ini, int id);
int			get_dec_id(t_ini *ini);
int			object_id_is_taken(t_ini *ini, int id);
int			get_npc_trade_id_given(t_ini *ini);
char			*look_for_obj_name(t_ini *ini, int id);
int			decors_name_is_taken(t_ini *ini, char *str);
char			*get_dec_name(t_ini *ini);


/* write */
int			write_ini(char *path, t_ini *ini);
void			write_player(t_player *player, int fd);
void			write_sprite(t_sprite *sprite, int fd);
void			write_object(t_object *object, int fd);
void			write_decors(t_decors *decors, int fd);
void			write_object_sprite_hit_w(t_object *object, int fd,
						  int size);
void			write_object_sprite_hit_h(t_object *object, int fd,
						  int size);
void			write_object_sprite_hit_y(t_object *object, int fd,
						  int size);
void			write_object_sprite_hit_x(t_object *object, int fd,
						  int size);
void			write_object_sprite_id(t_object *object, int fd,
					       int size);
void			write_object_critical(t_object *object, int fd,
					      int size);
void			write_object_strength(t_object *object, int fd,
					      int size);
void			write_object_stamina(t_object *object, int fd,
					     int size);
void			write_object_agility(t_object *object, int fd,
					     int size);
void			write_object_armor(t_object *object, int fd,
					   int size);
void			write_object_intellect(t_object *object, int fd,
					       int size);
void			write_object_equip_slot(t_object *object, int fd,
						int size);
void			write_object_equip(t_object *object, int fd,
					   int size);
void			write_sky_dist(t_sky *sky, int fd,
				       int size);
void			write_npc_trade_needed_id(t_npc *npc, int fd, int size);
void			write_npc_text(t_npc *npc, int fd, int size);
void			write_npc_name(t_npc *npc, int fd, int size);
void			write_npc_id(t_npc *npc, int fd, int size);
void			write_npc(t_npc *npc, int fd);
void			write_npc_sprite_hitbox_x(t_npc *npc, int fd,
						  int size);
void			write_npc_sprite_id(t_npc *npc, int fd,
					    int size);
void			write_npc_trade_given_amount(t_npc *npc, int fd,
						     int size);
void			write_npc_trade_given_id(t_npc *npc, int fd,
						 int size);
void			write_npc_trade_needed_ammout(t_npc *npc, int fd,
						      int size);
void			write_npc_sprite_hitbox_h(t_npc *npc, int fd,
						  int size);
void			write_npc_sprite_hitbox_w(t_npc *npc, int fd,
						  int size);
void			write_npc_sprite_hitbox_y(t_npc *npc, int fd,
						  int size);
void			write_sky_hitbox_h(t_sky *sky, int fd,
					   int size);
void			disp_scene_ground(t_scene *tmp, int fd);
void			write_particular_scene(t_scene *scene, int fd);
void			write_scene_name(t_scene *scene, int fd, int size);
void			write_scene(t_scene *scene, int fd);
void			write_scene_npc_pos_x(t_scene *scene, int fd, int size);
void			write_scene_npc_pos_y(t_scene *scene, int fd, int size);
void			write_scene_npc_id(t_scene *scene, int fd, int size);
void			write_scene_npc_count(t_scene *scene, int fd);
void			write_scene_decors_pos_x(t_scene *scene, int fd,
						 int size);
void			write_scene_decors_pos_y(t_scene *scene, int fd,
						 int size);
void			write_scene_decors_id(t_scene *scene, int fd,
					      int size);
void			write_scene_decors_count(t_scene *scene, int fd);
void			write_scene_gate_sprite_id(t_scene *scene, int fd,
						   int size);
void			write_scene_gate_pos_x(t_scene *scene, int fd,
						 int size);
void			write_scene_gate_pos_y(t_scene *scene, int fd,
					       int size);
void			write_scene_gate_name(t_scene *scene, int fd,
					      int size);
void			write_scene_gate_count(t_scene *scene, int fd);
void			write_scene_gate_sprite_hit_h(t_scene *scene, int fd,
						      int size);
void			write_scene_gate_sprite_hit_w(t_scene *scene, int fd,
						      int size);
void			write_scene_gate_sprite_hit_y(t_scene *scene, int fd,
						      int size);
void			write_scene_gate_sprite_hit_x(t_scene *scene, int fd,
						      int size);
void			write_sky_hitbox_w(t_sky *sky, int fd,
					   int size);
void			write_sky_hitbox_y(t_sky *sky, int fd,
					   int size);
void			write_sky_hitbox_x(t_sky *sky, int fd,
					   int size);
void			write_sky_id(t_sky *sky, int fd,
				     int size);
void			write_sprite_sky(t_sky *sky, int fd);

char			*get_next_line(const int fd);
void			start_shell();
void			free_tab(char **tab);
char			**str_to_wordtab(char *str, char *separate);

#endif			/* !EDIT_H_ */
