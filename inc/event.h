/*
** event.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:49:08 2016 Victor Sousa
** Last update Wed Apr 13 07:19:49 2016 Gaëtan Léandre
*/

#ifndef			EVENT_H_
# define		EVENT_H_

# include		"main.h"

typedef struct		s_fight
{
  int			nb_round;
  char			round_state;
  t_player		*player;
  t_npc			*npc;
}			t_fight;

int			start_fight(t_prog *prog, t_npc *npc);
t_bunny_response	event_key(t_bunny_event_state state,
				  t_bunny_keysym      key,
				  void                *data);
t_bunny_response        event_click(t_bunny_event_state state,
				    t_bunny_mousebutton button,
				    void                *p);

t_map_click		click_map(t_scene *scene, t_bunny_position *mouse_pos,
				  float percent);

void			handle_inventory_click(t_prog *prog);
void			handle_inventory_click_npc(t_prog *prog);
int			get_click_place_hotbar(t_prog *prog,
				       t_bunny_position *click_pos);
int			get_click_place_inventory(t_prog *prog,
					  t_bunny_position *click_pos);
int			get_click_place_npc_trade(t_prog *prog,
						  t_bunny_position *click_pos);
float			get_y(t_scene *scene, t_grille *grille, int pos);
int			get_x(float percent, t_grille *grille, int pos,
			      float y_pos);
t_bunny_position	get_pos(t_scene *scene, float percent,
				t_bunny_position *mouse_pos);
void			deplacement(t_player *player, t_scene *scene,
				    t_bunny_pixelarray *pix, float percent);

#endif			/* !EVENT_H_ */
