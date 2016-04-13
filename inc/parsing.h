/*
** parsing.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Wed Apr 13 17:31:53 2016 Philippe Lefevre
*/

#ifndef			PARSING_H_
# define		PARSING_H_

t_scene			*my_puterror_scene(char *str);
t_ground		*my_puterror_ground(char *str);
t_sky			*my_puterror_sky(char *str);
t_player		*my_puterror_player(char *str);
t_npc			*my_puterror_npc(char *str);
t_object		*my_puterror_object(char *str);
t_sprite		*my_puterror_sprite(char *str);
t_npc			*my_puterror_playerpc(char *str);
t_breakable		*my_puterror_breakable(char *str);
t_decors		*my_puterror_decors(char *str);
t_hitbox		*my_puterror_hitbox(char *str);
t_trade			*my_puterror_trade(char *str);
t_item			*my_puterror_item(char *item);

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list);
t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list);
t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_player		*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_npc			*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list);

#endif			/* !PARSING_H_ */
