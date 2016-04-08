/*
** parsing.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Fri Apr  8 05:35:19 2016 Philippe Lefevre
*/

#ifndef			PARSING_H_
# define		PARSING_H_

# include		"main.h"
# include		"scene.h"

t_scene			*parsing(const char *file, t_player **player,
				 t_ptr_list **ptr_list);
t_scene			*load_scene(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_player		*load_player(t_bunny_ini *ini, t_ptr_list **ptr_list);
t_npc			*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list);

#endif			/* !PARSING_H_ */
