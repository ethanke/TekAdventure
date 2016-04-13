/*
** loop.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:58:37 2016 Philippe Lefevre
** Last update Wed Apr 13 19:30:09 2016 Gaëtan Léandre
*/

#include		"main.h"

void                    swap_pix(t_prog *prog)
{
  if (prog->pix_id == 0)
    {
      prog->pix_id = 1;
      prog->pix = prog->pix1;
    }
  else if (prog->pix_id == 1)
    {
      prog->pix_id = 2;
      prog->pix = prog->pix2;
    }
  else
    {
      prog->pix_id = 0;
      prog->pix = prog->pix0;
    }
}

t_bunny_response	mainloop(void *p)
{
  t_prog		*prog;
  t_bunny_position	*mouse_pos;

  prog = p;
  mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  place_image(create_hitbox(0, 0, WIN_WIDTH, WIN_HEIGHT),
	      create_hitbox(0, 0, prog->lion_img->width,
			    prog->lion_img->height),
	      prog->lion_img, prog->pix);
  prog->percent = 1 - (float)mouse_pos->x / (float)WIN_WIDTH;
  disp_ground(prog, prog->player->move.select_move);
  if (prog->state == STATE_FIGHT)
    start_fight(prog, prog->scene->npc);
  else if (prog->state == STATE_NPC_CHOOSE)
    disp_choose_npc_action(prog);
  else if (prog->state == STATE_GAME)
    {
      /* GAMEPLAY ELEMENT */
    }
  else if (prog->state == STATE_NPC)
    interact_npc(prog, prog->scene->npc->next->next);

  disp_inventory(prog);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->blit_pos);
  swap_pix(prog);
  bunny_display(prog->win);
  return (GO_ON);
}
