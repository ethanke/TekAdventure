/*
** loop.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:58:37 2016 Philippe Lefevre
** Last update Mon Mar 28 20:01:13 2016 Philippe Lefevre
*/

#include		"tekadventure.h"

t_bunny_response	mainloop(void *p)
{
  t_prog			*prog;

  prog = p;
  bunny_blit(&prog->win->buffer, &prog->array->clipable, &prog->position);
  bunny_display(prog->win);
  return (GO_ON);
}
