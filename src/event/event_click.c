/*
** event_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:10:29 2016 Victor Sousa
** Last update Sat Apr 16 09:13:45 2016 Ethan Kerdelhue
*/

#include		"main.h"

void	state_npc_chose(t_prog *prog, int npc_choose,
			t_bunny_position *npc_choose_pos)
{

  npc_choose_pos->x = WIN_WIDTH / 2 - prog->npc_choose->width / 2 +
      prog->npc_choose->width / 3 / 2;
  npc_choose_pos->y = WIN_HEIGHT / 2 - prog->npc_choose->height / 2 +
      prog->npc_choose->height / 3  / 2;
  if ((npc_choose = get_highlight(prog, npc_choose_pos)) == -2)
    prog->state = STATE_GAME;
  else if (npc_choose == 0 && prog->current_click.npc != NULL)
    prog->state = STATE_NPC;
  else if (npc_choose == 1 && prog->current_click.npc != NULL)
    prog->state = STATE_FIGHT;
  else if (npc_choose == 2 && prog->current_click.decors != NULL)
    prog->state = STATE_DECOR_CHOOSE;
}

void			check_prog_state(t_prog *prog,
					 t_bunny_position *mouse_pos)
{
if (prog->state == STATE_GAME )
  {
    if (prog->player->move.select_move == 1)
      test_move(prog, mouse_pos);
    else
      prog->current_click = click_map(prog, mouse_pos,
				      1 - (float)mouse_pos->x /
				      (float)WIN_WIDTH);
  }
if (prog->player->move.select_move != 1 && prog->state == STATE_GAME &&
    (prog->current_click.npc != NULL || prog->current_click.decors != NULL))
  {
    prog->state = STATE_NPC_CHOOSE;
    prog->player->inventory_open = 0;
  }
}

void			bmb_left_on(t_prog *prog, int npc_choose,
				    t_bunny_position npc_choose_pos,
				     t_bunny_event_state state)
{
  if (state == GO_UP && prog->state == STATE_FIGHT)
    catch_button(prog);
  if (prog->state == STATE_GAME)
    handle_inventory_click(prog);
  else if (prog->state == STATE_NPC)
    handle_inventory_click_npc(prog);
  else if (prog->state == STATE_DECOR_CHOOSE && state == GO_UP)
    {
      prog->player->item_selected =
      get_click_place_hotbar(prog,
			     (t_bunny_position *)bunny_get_mouse_position());
    }
  else if (prog->state == STATE_NPC_CHOOSE)
    state_npc_chose(prog, npc_choose, &npc_choose_pos);
}

t_bunny_response        event_click(t_bunny_event_state            state,
				    t_bunny_mousebutton            button,
				    void                           *data)
{
  t_prog		*prog;
  t_bunny_position	npc_choose_pos;
  int			npc_choose;
  t_bunny_position	*mouse_pos;

  (void)state;
  npc_choose = 0;
  mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  prog = (t_prog *)data;
  if (prog->state == STATE_GAME_OVER)
    return (check_game_over_button(prog, mouse_pos));
  if (prog->state == STATE_MENU)
    return (check_menu_button(prog, mouse_pos));
  check_prog_state(prog, mouse_pos);
  if (button == BMB_LEFT)
    bmb_left_on(prog, npc_choose, npc_choose_pos, state);
  return (GO_ON);
}
