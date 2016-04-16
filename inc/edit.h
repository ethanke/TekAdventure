/*
** edit.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:51:56 2016 Victor Sousa
** Last update Sat Apr 16 19:52:43 2016 Victor Sousa
*/

#ifndef			EDIT_H_
# define		EDIT_H_

# include		"main.h"

typedef struct		s_ini
{
  t_player		*player;
  t_scene		*scene;
  t_ptr_list		*ptr_list;
  char			has_been_loaded;
}			t_ini;

int			load_ini(char *path, t_ini *ini);
void			close_ini(t_ini *ini);
void			aff_stuff(int ac, char **av, t_ini *ini);
void			aff_all(int fd, t_ini *ini);
void			add_stuff(int ac, char **av, t_ini *ini);

/* add */
void			add_object(t_ini *ini);

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

char			*get_next_line(const int fd);
void			start_shell();
void			free_tab(char **tab);
char			**str_to_wordtab(char *str, char *separate);

#endif			/* !EDIT_H_ */
