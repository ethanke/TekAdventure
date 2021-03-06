/*
** update_bar.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 19:38:24 2016 Ethan Kerdelhue
** Last update Thu Apr 14 23:58:16 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			percent_bar(t_hitbox size, t_bar *bar, t_prog *prog,
				    unsigned int color)
{
  t_hitbox		rect;
  t_font		font;
  t_bunny_position	pos;

  redim_image(&size, bar->bar_sprite, prog->pix);
  rect.x = size.x;
  rect.y = size.y;
  rect.width = (float)((float)size.width / (float)bar->value_default)
      * (float)bar->value_cur;
  rect.height = size.height;
  fill_image(rect, prog->pix, color);
  pos.y = size.y + size.height / 2 - 6;
  pos.x = size.x + 5;
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = BLACK;
  teknbr(bar->value_cur, &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  teknbr(bar->value_default, &pos, prog->pix, &font);
}
