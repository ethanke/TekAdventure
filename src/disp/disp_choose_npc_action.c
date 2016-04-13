/*
** disp_choose_npc_action.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 05:44:24 2016 Victor Sousa
** Last update Wed Apr 13 07:28:28 2016 Victor Sousa
*/

#include		"main.h"

void			disp_choose_npc_action(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = WIN_WIDTH / 2 - (prog->npc_choose->width / 1.5);
  pos.y = WIN_HEIGHT / 2 - (prog->npc_choose->height / 1.5);
  place_image(create_hitbox(pos.x, pos.y, (float)prog->npc_choose->width / 1.5,
			    (float)prog->npc_choose->height / 1.5),
	      create_hitbox(0, 0, prog->npc_choose->width,
			    prog->npc_choose->height),
	      prog->npc_choose, prog->pix);
  /*handle_click_on_choose()*/
}
