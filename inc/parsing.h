/*
** parsing.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Fri Apr 15 00:20:12 2016 Philippe Lefevre
*/

#ifndef			PARSING_H_
# define		PARSING_H_

t_scene			*my_puterror_scene(char *beg, char *scene, char *mid,
					   int id, char *end);
t_ground		*my_puterror_ground(char *beg, char *scene, char *mid,
					    int id, char *end);
t_sky			*my_puterror_sky(char *beg, char *scene, char *mid,
					 int id, char *end);
t_player		*my_puterror_player(char *beg, int id, char *end);
t_npc			*my_puterror_npc(char *beg, int id, char *end);
t_object		*my_puterror_object(char *beg, int id, char *end);
t_sprite		*my_puterror_sprite(char *beg, int id, char *end);
t_npc			*my_puterror_playerpc(char *beg, int id, char *end);
t_breakable		*my_puterror_breakable(char *beg, int id, char *end);
t_decors		*my_puterror_decors(char *beg, int id, char *end);
t_hitbox		*my_puterror_hitbox(char *beg, int id, char *end);
t_trade			*my_puterror_trade(char *beg, int id, char *end);
t_item			*my_puterror_item(char *beg, int id, char *end);

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list);
t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list, int pos);
t_sky			*load_sky(char *name, t_bunny_ini *ini,
				  t_ptr_list **ptr_list);
t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_player		*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_npc			*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_object		*link_object(t_object *object, t_sprite *sprite);
t_decors		*link_decors(t_decors *decors, t_sprite *sprite);
t_npc			*link_npc(t_npc *npc, t_sprite *sprite,
				  t_object *object);
t_scene			*link_ground(t_bunny_ini *ini, t_scene *scene,
				     t_ptr_list **ptr_list, char *name);
t_item			*link_inventory_item(t_item *inventory, t_object *object);
t_player		*link_player(t_player *player, t_sprite *sprite);
t_sky			*link_sky(t_sky *sky, t_sprite *sprite);
t_ground		*ground_fill(t_bunny_ini *ini, t_scene *scene,
				      t_ptr_list **ptr_list, char *name);
t_hitbox		*create_sol_hitbox(int id, t_bunny_ini *ini,
					   t_ptr_list **ptr_list,
					   char *name);

#endif			/* !PARSING_H_ */
