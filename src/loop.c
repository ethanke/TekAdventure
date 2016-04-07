/*
** loop.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:58:37 2016 Philippe Lefevre
** Last update Thu Apr  7 02:17:08 2016 victor sousa
*/

#include		"main.h"

t_bunny_response	mainloop(void *p)
{
  t_prog			*prog;

  prog = p;
  put_image(prog->lion_img, prog->pix, &prog->blit_pos);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->blit_pos);
  bunny_display(prog->win);
  return (GO_ON);
}
