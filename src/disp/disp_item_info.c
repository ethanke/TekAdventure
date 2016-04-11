/*
** disp_item_info.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 11 07:08:46 2016 Victor Sousa
** Last update Mon Apr 11 08:04:49 2016 Victor Sousa
*/

#include		"main.h"

void			disp_item_info(t_prog *prog, t_item *item,
				       t_bunny_position *pos)
{
  t_bunny_position	rect_pos;
  t_bunny_position	rect_size;
  t_font		font;
  char			*str;

  rect_pos.x = pos->x - IIS_WIDTH;
  rect_pos.y = pos->y - IIS_HEIGHT;
  rect_size.x = IIS_WIDTH;
  rect_size.y = IIS_HEIGHT;
  font.font_img = prog->font->font_img;
  font.font_size = 10;
  my_draw_square(prog->pix, &rect_pos, &rect_size, 0xCFFFFFFF);
  rect_pos.x += 10;
  rect_pos.y += 10;
  tektext(item->object->name, &rect_pos, prog->pix, &font);
  rect_pos.y += 15;
  str = malloc(20);
  str = my_strcpy(str, "quantity : ");
  str = my_strcat(str, my_itoa(item->amount));
  tektext(str, &rect_pos, prog->pix, &font);
  rect_pos.y += 15;
  str = my_strcpy(str, "damage : ");
  str = my_strcat(str, my_itoa(item->object->damage));
  tektext(str, &rect_pos, prog->pix, &font);
  free(str);
}
