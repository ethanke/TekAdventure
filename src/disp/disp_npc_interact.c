/*
** disp_npc_interact.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 00:01:51 2016 Victor Sousa
** Last update Wed Apr 13 00:34:01 2016 Victor Sousa
*/

#include		"main.h"

void			disp_npc(t_prog *prog, t_npc *npc)
{
  t_bunny_position	pos;

  pos.x = WIN_WIDTH - npc->texture->width;
  pos.y = WIN_HEIGHT / 2 - npc->texture->height / 5;
  place_image(create_hitbox(pos.x, pos.y, (float)npc->texture->width *
			    (float)((float)WIN_HEIGHT / (float)WIN_WIDTH),
			    WIN_HEIGHT / 3),
	      create_hitbox(0, 0, npc->texture->width,
			    npc->texture->height),
	      npc->texture, prog->pix);
}

void			disp_player(t_prog *prog, t_player *player)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = WIN_HEIGHT / 2 - player->sprite->height / 5;
  place_image(create_hitbox(pos.x, pos.y, (float)player->sprite->width *
			    (float)((float)WIN_HEIGHT / (float)WIN_WIDTH),
			    WIN_HEIGHT / 3),
	      create_hitbox(0, 0, player->sprite->width,
			    player->sprite->height),
	      player->sprite, prog->pix);
}

void			disp_npc_name(t_prog *prog, t_npc *npc)
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

void			disp_npc_message(t_prog *prog, t_npc *npc)
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
