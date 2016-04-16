/*
** loop.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:58:37 2016 Philippe Lefevre
** Last update Sat Apr 16 04:16:01 2016 Ethan Kerdelhue
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
  t_font		font;
  t_bunny_position	f_pos;

  prog = p;
  font.font_img = prog->font->font_img;
  font.font_size = 20;
  font.font_color.full = 0xFF050505;
  f_pos.x = WIN_WIDTH / 2;
  f_pos.y = WIN_HEIGHT - 100;
  prog->percent = 1 - prog->player->x / (float)prog->scene->size.x;
  disp_ground(prog, prog->player->move.select_move);
  if (prog->state == STATE_FIGHT)
    start_fight(prog, prog->current_click.npc);
  else if (prog->state == STATE_NPC_CHOOSE)
    disp_choose_npc_action(prog);
  else if (prog->state == STATE_DECOR_CHOOSE)
    interact_decors(prog);
  else if (prog->state == STATE_GAME)
    {
      /* GAMEPLAY ELEMENT */
    }
  else if (prog->state == STATE_NPC)
    interact_npc(prog, prog->current_click.npc);
  if (prog->state != STATE_FIGHT)
    disp_inventory(prog);
  if (prog->disp_delay > 0 && prog->disp_str != NULL)
    {
      tektextcenter(prog->disp_str,
		    &f_pos, prog->pix, &font);
      prog->disp_delay--;
      if (prog->disp_delay == 0)
	free(prog->disp_str);
    }
  if (prog->state == STATE_GAME_OVER)
    disp_game_over(prog);
  disp_font(prog, prog->text, prog->pix);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->blit_pos);
  swap_pix(prog);
  bunny_display(prog->win);
  return (GO_ON);
}
