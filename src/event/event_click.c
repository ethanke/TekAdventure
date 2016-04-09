/*
** event_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:10:29 2016 Victor Sousa
** Last update Sat Apr  9 11:20:11 2016 Victor Sousa
*/

#include		"main.h"

t_bunny_response        event_click(t_bunny_event_state            state,
				    t_bunny_mousebutton            button,
				    void                           *data)
{
  t_prog		*prog;

  (void)button;
  prog = (t_prog *)data;
  if (state == GO_UP)
    handle_inventory_click(prog);
  return (GO_ON);
}
