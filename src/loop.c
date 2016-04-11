/*
** loop.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:58:37 2016 Philippe Lefevre
** Last update Mon Apr 11 03:32:32 2016 Victor Sousa
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
  if (prog->fight_state == 1)
    start_fight(prog, prog->scene->npc);
  else{
      place_image(create_hitbox_ptr(prog->blit_pos, WIN_WIDTH,
				    WIN_HEIGHT, prog->ptr_list),
		  create_hitbox_ptr(prog->blit_pos, prog->lion_img->width,
				    prog->lion_img->height, prog->ptr_list),
		  prog->lion_img, prog->pix);
      disp_ground(prog->scene, prog->pix, 1 - (float)mouse_pos->x / (float)WIN_WIDTH);

      tektext("gros fdp\nde merde", &prog->blit_pos, prog->pix, prog->font);
  }

  disp_inventory(prog);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->blit_pos);
  swap_pix(prog);
  bunny_display(prog->win);
  return (GO_ON);
}
