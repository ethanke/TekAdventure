/*
** disp_menu.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 06:31:23 2016 Victor Sousa
** Last update Sat Apr 16 06:57:36 2016 Victor Sousa
*/

#include		"main.h"

void			disp_menu(t_prog *prog)
{
  place_image(create_hitbox(prog->blit_pos.x, prog->blit_pos.y,
      			    prog->menu_bg->width, prog->menu_bg->height),
      	      create_hitbox(prog->menu_bg_pos.x, prog->menu_bg_pos.y,
      			    prog->menu_bg->width - 150,
      			    prog->menu_bg->height - 100),
      	      prog->menu_bg, prog->pix);
  place_image(create_hitbox(0, 0, prog->menu_text->width,
			    prog->menu_text->height),
	      create_hitbox(0, 0, prog->menu_text->width,
			    prog->menu_text->height),
	      prog->menu_text, prog->pix);
  if (prog->menu_dir == 0)
    {
      prog->menu_bg_pos.x++;
      if (prog->menu_bg_pos.x >= 150)
	prog->menu_dir = 1;
    }
  else
    {
      prog->menu_bg_pos.x--;
      if (prog->menu_bg_pos.x <= 0)
	prog->menu_dir = 0;
    }
}
