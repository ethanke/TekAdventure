/*
** disp_selected_inv_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 14:34:08 2016 Victor Sousa
** Last update Sat Apr 16 03:49:02 2016 Victor Sousa
*/

#include		"main.h"

static void		draw_selected(t_prog *prog, t_hitbox *box)
{
  t_bunny_position	pos;
  t_color		col;

  col.full = 0x3F0000FF;
  pos.x = box->x - 1;
  while (++pos.x <= box->x + box->width)
    {
      pos.y = box->y - 1;
      while (++pos.y <= box->y + box->height)
	tektranspa(prog->pix, &pos, &col);
    }
}

void			disp_selected_hotbar_inv_item(t_prog *prog)
{
  t_bunny_position	pos;

  if (prog->player->inv_selected < 0 || prog->player->inv_selected > 11)
    return;
  pos.x = WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2) / 4 + 10;
  pos.y = WIN_HEIGHT - prog->player->hotbar_sprite->height / 4 + 10;
  pos.x += 40.45 * prog->player->inv_selected;
  draw_selected(prog, create_hitbox_ptr(pos, 36, 30, prog->ptr_list));
}

void			disp_selected_full_inv_item(t_prog *prog)
{
  t_bunny_position	pos;

  if (prog->player->inv_selected == -1)
    return;
  if (prog->player->inv_selected > 11 && prog->player->inv_selected < 48)
    {
      pos.x = WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2) / 4
	  + 10;
      pos.y = WIN_HEIGHT / 2 - (prog->player->inv_open_sprite->height / 2) / 4
	  + 10;
      pos.x += 40.45 * (prog->player->inv_selected % 12);
      pos.y += 36 * (prog->player->inv_selected / 12 - 1);
      draw_selected(prog, create_hitbox_ptr(pos, 36, 30, prog->ptr_list));
    }
  else if (prog->player->inv_selected >= 48)
    {
      pos.x = WIN_WIDTH / 2 - ((prog->player->inv_open_sprite->width / 4) / 2)
	  - prog->equip_sprite->width + 1;
      pos.y = WIN_HEIGHT / 2 - prog->equip_sprite->height / 2 + 2;
      pos.y += 36 * (prog->player->inv_selected - 48);
      draw_selected(prog, create_hitbox_ptr(pos, 36, 30, prog->ptr_list));
    }
}
