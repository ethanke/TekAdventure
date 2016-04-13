/*
** disp_npc_exchange.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Tue Apr 12 20:17:50 2016 Victor Sousa
** Last update Wed Apr 13 23:32:06 2016 Victor Sousa
*/

#include		"main.h"

static void		disp_npc_name(t_prog *prog, t_npc *npc)
{
  t_font		font;
  t_bunny_position	pos;

  font.font_img = prog->font->font_img;
  font.font_size = 13;
  font.font_color.full = 0xFF040404;
  pos.x = WIN_WIDTH / 2 - prog->exchange_sprite->width / 2 + 25;
  pos.y = WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 + 25;
  tektext(npc->name, &pos, prog->pix, &font);
}

static void		disp_npc_message(t_prog *prog, t_npc *npc)
{
  t_font		font;
  t_bunny_position	pos;
  int			i;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  font.font_color.full = 0xFF070707;
  pos.x = WIN_WIDTH / 2 - prog->exchange_sprite->width / 2 + 25;
  pos.y = WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 + 75;
  i = 0;
  while (npc->text[i])
    {
      if (npc->text[i] == ';')
	npc->text[i] = '\n';
      i++;
    }
  tektext(npc->text, &pos, prog->pix, &font);
}

static void 		disp_needed_item(t_prog *prog, t_npc *npc)
{
  t_bunny_position	pos;
  t_font		font;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  pos.x = WIN_WIDTH / 2 - npc->trade->needed->object->texture->width / 2 - 15;
  pos.y = WIN_HEIGHT / 2 - npc->trade->needed->object->texture->height / 2 + 90;
  if (npc != NULL && npc->trade->in_stock->amount > 0)
    {
      font.font_color.full = 0xFF050505;
      place_image(create_hitbox(pos.x, pos.y, 32, 32),
		  *npc->trade->needed->object->texture_hitbox,
		  npc->trade->needed->object->texture, prog->pix);
      pos.y += 3;
      tektext(my_itoa(npc->trade->in_stock->amount), &pos, prog->pix, &font);
      pos.y -= 3;
    }
    else
    {
      font.font_color.full = 0x55050505;
      place_image_transpa(create_hitbox(pos.x, pos.y, 32, 32),
			  *prog->scene->object->texture_hitbox,
			  prog->scene->object->texture, prog->pix);
      pos.y += 3;
      tektext(my_itoa(npc->trade->needed->amount), &pos, prog->pix, &font);
      pos.y -= 3;
    }
  pos.x += 115;
  if (npc != NULL && npc->trade->in_stock->amount >= npc->trade->needed->amount)
    {
      place_image(create_hitbox(pos.x, pos.y, 32, 32),
		  *npc->trade->given->object->texture_hitbox,
		  npc->trade->given->object->texture, prog->pix);

    }
  else
    {
      place_image_transpa(create_hitbox(pos.x, pos.y, 32, 32),
			  *npc->trade->given->object->texture_hitbox,
			  npc->trade->given->object->texture, prog->pix);
    }
}

void			disp_npc_exchange(t_prog *prog, t_npc *npc)
{
  t_bunny_position	pos;

  disp_npc(prog, npc);
  disp_player(prog, prog->player);
  pos.x = WIN_WIDTH / 2 - prog->exchange_sprite->width / 2;
  pos.y = WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2;
  place_image(create_hitbox(pos.x, pos.y, prog->exchange_sprite->width,
			    prog->exchange_sprite->height),
	      create_hitbox(0, 0, prog->exchange_sprite->width,
			    prog->exchange_sprite->height),
	      prog->exchange_sprite, prog->pix);
  disp_npc_name(prog, npc);
  disp_npc_message(prog, npc);
  disp_needed_item(prog, npc);
}
