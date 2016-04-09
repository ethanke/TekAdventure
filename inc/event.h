/*
** event.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:49:08 2016 Victor Sousa
** Last update Sat Apr  9 11:54:30 2016 Victor Sousa
*/

#ifndef			EVENT_H_
# define		EVENT_H_

# include		"main.h"

t_bunny_response	event_key(t_bunny_event_state state,
				  t_bunny_keysym      key,
				  void                *data);
t_bunny_response        event_click(t_bunny_event_state state,
				    t_bunny_mousebutton button,
				    void                *p);

void			handle_inventory_click(t_prog *prog);
int			get_click_place_hotbar(t_prog *prog,
				       t_bunny_position *click_pos);
int			get_click_place_inventory(t_prog *prog,
					  t_bunny_position *click_pos);

#endif			/* !EVENT_H_ */
