/*
** parsing.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Wed Apr 13 06:16:13 2016 Victor Sousa
*/

#ifndef			PARSING_H_
# define		PARSING_H_

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list);
t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list);
t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_player		*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_npc			*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list);

#endif			/* !PARSING_H_ */
