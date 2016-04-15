/*
** disp_npc_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 22:02:26 2016 Victor Sousa
** Last update Fri Apr 15 22:07:40 2016 Victor Sousa
*/

#include		"main.h"

static void 		disp_left_item(t_prog *prog, t_font font,
				       t_bunny_position pos,
				       t_npc *npc)
{
  if (npc != NULL && npc->trade->in_stock->amount > 0)
    {
      font.font_color.full = 0xFF050505;
      place_image(create_hitbox(pos.x, pos.y, 32, 32),
		  *npc->trade->needed->object->texture_hitbox,
		  npc->trade->needed->object->texture, prog->pix);
      pos.y += 3;
      teknbr(npc->trade->in_stock->amount, &pos, prog->pix, &font);
      pos.y -= 3;
    }
  else
    {
      font.font_color.full = 0x55050505;
      place_image_transpa(create_hitbox(pos.x, pos.y, 32, 32),
			  *npc->trade->needed->object->texture_hitbox,
			  npc->trade->needed->object->texture, prog->pix);
      pos.y += 3;
      teknbr(npc->trade->needed->amount, &pos, prog->pix, &font);
      pos.y -= 3;
    }
}

static void 		disp_right_item(t_prog *prog, t_font font,
				       t_bunny_position pos,
				       t_npc *npc)
{
  if (npc != NULL && npc->trade->in_stock->amount >=
      npc->trade->needed->amount)
    {
      font.font_color.full = 0xFF050505;
      place_image(create_hitbox(pos.x, pos.y, 32, 32),
		  *npc->trade->given->object->texture_hitbox,
		  npc->trade->given->object->texture, prog->pix);
      pos.y += 3;
      teknbr(npc->trade->given->amount, &pos, prog->pix, &font);
      pos.y -= 3;
    }
  else
    {
      font.font_color.full = 0x55050505;
      place_image_transpa(create_hitbox(pos.x, pos.y, 32, 32),
			  *npc->trade->given->object->texture_hitbox,
			  npc->trade->given->object->texture, prog->pix);
      pos.y += 3;
      teknbr(npc->trade->given->amount, &pos, prog->pix, &font);
      pos.y -= 3;
    }
}

void 			disp_needed_item(t_prog *prog, t_npc *npc)
{
  t_bunny_position	pos;
  t_font		font;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  pos.x = WIN_WIDTH / 2 - 115 / 2 - 16;
  pos.y = WIN_HEIGHT / 2 - 11 + 90;
  disp_left_item(prog, font, pos, npc);
  pos.x += 115;
  disp_right_item(prog, font, pos, npc);
}
