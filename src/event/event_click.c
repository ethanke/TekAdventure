/*
** event_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:10:29 2016 Victor Sousa
** Last update Wed Apr 13 01:30:45 2016 Victor Sousa
*/

#include		"main.h"

t_bunny_response        event_click(t_bunny_event_state            state,
				    t_bunny_mousebutton            button,
				    void                           *data)
{
  t_prog		*prog;

  (void)state;
  prog = (t_prog *)data;
  if (button == BMB_LEFT)
    {
      if (prog->state == STATE_GAME)
	handle_inventory_click(prog);
      else if (prog->state == STATE_NPC)
	handle_inventory_click_npc(prog);
    }
  return (GO_ON);
}
