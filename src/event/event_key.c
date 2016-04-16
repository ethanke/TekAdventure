/*
** event_key.c for tekadventure in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Apr  6 21:04:44 2016 victor sousa
** Last update Sat Apr 16 09:31:59 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			manage_inventory(t_prog *prog)
{
  if (prog->player->inventory_open == 0)
    prog->player->inventory_open = 1;
  else
    {
      prog->player->inventory_open = 0;
      prog->player->inv_selected = -1;
    }
}

t_bunny_response	event_key(t_bunny_event_state state,
				  t_bunny_keysym      key,
				  void                *data)
{
  t_prog		*prog;

  prog = data;
  if (key == BKS_ESCAPE && state == GO_UP)
    {
      if (prog->state == STATE_NPC || prog->state == STATE_NPC_CHOOSE || prog->
	  state == STATE_DECOR_CHOOSE || prog->player->inventory_open == 1)
	{
	  prog->state = STATE_GAME;
	  prog->player->inventory_open = 0;
	  return (GO_ON);
	}
      else
	return (EXIT_ON_SUCCESS);
    }
  if (prog->state == STATE_GAME && key == BKS_E && state == GO_DOWN)
    {
      manage_inventory(prog);
    }
  else if (key == BKS_SPACE && state == GO_UP)
    prog->player->move.select_move =
      prog->player->move.select_move == 1 ? 0 : 1;
  return (GO_ON);
}
