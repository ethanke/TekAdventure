/*
** update_bar.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 19:38:24 2016 Ethan Kerdelhue
** Last update Thu Apr 14 03:11:27 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			update_bar_action(t_bar *bar, t_prog *prog)
{
  t_hitbox		rect;
  t_bunny_position	pos;
  t_font		font;

  rect.x = WIN_WIDTH - 20 - prog->npc_bar->bar_sprite->width;
  rect.y = 100;
  rect.width =  ((float)bar->bar_sprite->width / 100.0 * (float) *bar->value_cur);
  rect.height = bar->bar_sprite->height;
  fill_image(rect, prog->pix, BLUE);
  pos.y = 100 + bar->bar_sprite->height / 2 - 5;
  pos.x = (bar->bar_sprite->width / 2) + 675;
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = WHITE;
  tektext(my_itoa(*bar->value_cur), &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  tektext(my_itoa(bar->value_default), &pos, prog->pix, &font);
}

void			update_bar_npc(t_bar *bar, t_prog *prog)
{
  t_hitbox		rect;
  t_bunny_position	pos;
  t_font		font;

  rect.x = WIN_WIDTH - 20 - prog->npc_bar->bar_sprite->width;
  rect.y = 100;
  rect.width =  ((float)bar->bar_sprite->width / 100.0 * (float) *bar->value_cur);
  rect.height = bar->bar_sprite->height;
  fill_image(rect, prog->pix, BLUE);
  pos.y = 100 + bar->bar_sprite->height / 2 - 5;
  pos.x = (bar->bar_sprite->width / 2) + 675;
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = WHITE;
  tektext(my_itoa(*bar->value_cur), &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  tektext(my_itoa(bar->value_default), &pos, prog->pix, &font);
}

void			percent_bar(t_hitbox size, t_bar *bar, t_prog *prog,
				    unsigned int color)
{
  t_hitbox		rect;
  t_font		font;
  char			*str;
  t_bunny_position	pos;

  redim_image(&size, bar->bar_sprite, prog->pix);
  rect.x = size.x;
  rect.y = size.y;
  rect.width = (float)((float)size.width / (float)bar->value_default)
      * (float)*bar->value_cur;
  rect.height = size.height;
  fill_image(rect, prog->pix, color);
  pos.y = size.y + size.height / 2 - 6;
  pos.x = size.x + 5;
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = BLACK;
  if ((str = my_itoa(*bar->value_cur)) == NULL)
    return;
  tektext(str, &pos, prog->pix, &font);
  pos.x += 60;
  free(str);
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  if ((str = my_itoa(bar->value_default)) == NULL)
    return;
  tektext(str, &pos, prog->pix, &font);
  free(str);
}

void			update_bar_player(t_bar *bar, t_prog *prog)
{
  t_hitbox		rect;
  t_bunny_position	pos;
  t_font		font;

  rect.x = 20;
  rect.y = 100;
  rect.width =  ((float)bar->bar_sprite->width / 100.0 * (float) *bar->value_cur);
  rect.height = bar->bar_sprite->height;
  fill_image(rect, prog->pix, RED);
  pos.y = 100 + bar->bar_sprite->height / 2 - 5;
  pos.x = (bar->bar_sprite->width / 2);
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = WHITE;
  tektext(my_itoa(*bar->value_cur), &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  tektext(my_itoa(bar->value_default), &pos, prog->pix, &font);
}
