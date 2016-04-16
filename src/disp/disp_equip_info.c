/*
** disp_equip_info.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 03:58:31 2016 Victor Sousa
** Last update Sat Apr 16 03:59:53 2016 Victor Sousa
*/

#include		"main.h"

void			disp_equip_info(t_prog *prog, t_item *item,
					t_bunny_position *pos)
{
  t_bunny_position	rect_pos;
  t_bunny_position	rect_size;
  t_font		font;

  rect_pos.x = pos->x - EIS_WIDTH;
  rect_pos.y = pos->y - EIS_HEIGHT;
  rect_size.x = EIS_WIDTH;
  rect_size.y = EIS_HEIGHT;
  font.font_img = prog->font->font_img;
  font.font_size = 10;
  font.font_color.full = 0xFFF0F0F0;
  my_draw_square(prog->pix, &rect_pos, &rect_size, 0xCF000000);
  rect_pos.x += 10;
  rect_pos.y += 10;
  tektext(item->object->name, &rect_pos, prog->pix, &font);
  rect_pos.y += 15;
  disp_quatity(prog, font, item, rect_pos);
  rect_pos.y += 15;
  disp_damage(prog, font, item, rect_pos);
}
