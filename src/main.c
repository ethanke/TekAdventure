/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Sat Apr 16 06:36:05 2016 Victor Sousa
*/

#include		"main.h"

int			init_prog(t_prog *prog, char *str)
{
  prog->blit_pos.x = 0;
  prog->blit_pos.y = 0;
  prog->ptr_list = NULL;
  if ((prog->scene = parsing(str, &prog->player, &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->player->inventory_open = 0;
  prog->player->inv_selected = -1;
  prog->player->move.select_move = 0;
  prog->player->move.depla = NULL;
  prog->player->x = 8;
  prog->player->y = 0;
  if ((prog->player->caract = xmalloc(sizeof(t_caract), &prog->ptr_list)) == NULL)
    return (0);
  prog->player->caract->stamina = 50;
  prog->player->caract->strength = 50;
  prog->player->caract->critical = 50;
  prog->player->caract->agility = 50;
  prog->player->caract->armor = 50;
  prog->player->caract->intellect = 50;
  prog->player->life = prog->player->caract->stamina * 2 + prog->player->life;
  prog->disp_delay = 0;
  prog->player->item_selected = -1;
  prog->state = STATE_MENU;
  prog->need_init_fight = 1;
  if ((prog->font =
       xmalloc(sizeof(t_font), &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->font->font_img =
       load_image("ressources/sprites/font1.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->font->font_size = 50;
  prog->font->font_color.full = 0xFF000000;
  if ((prog->fight_img = load_image("ressources/sprites/fight.jpg",
				    &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->player->inv_open_sprite =
       load_image("ressources/sprites/inventory_full.png",
		  &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->npc_choose =
       load_image("ressources/sprites/npc_choose.png",
		  &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->player->hotbar_sprite =
       load_image("ressources/sprites/hotbar.png",
		  &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->exchange_sprite =
       load_image("ressources/sprites/exchange.png",
		  &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->equip_sprite =
       load_image("ressources/sprites/equip.png",
		  &prog->ptr_list)) == NULL)
    return (ERROR);
  /* penser vérifié le retour */
  prog->menu_bg_pos.x = 50;
  prog->menu_bg_pos.y = 0;
  prog->menu_dir = 0;
  prog->menu_bg =
  load_image("ressources/sprites/menubg.png", &prog->ptr_list);
  prog->menu_text =
  load_image("ressources/sprites/textmenu.png", &prog->ptr_list);
  prog->game_over_img =
  load_image("ressources/sprites/gameover.png", &prog->ptr_list);
  prog->game_over_img =
  load_image("ressources/sprites/gameover.png", &prog->ptr_list);
  prog->over_quit =
  load_image("ressources/sprites/over_quit.png", &prog->ptr_list);
  prog->over_continue =
  load_image("ressources/sprites/over_continue.png", &prog->ptr_list);
  prog->fight_img =
  load_image("ressources/sprites/fight.jpg", &prog->ptr_list);
  prog->attack_button =
  load_image("ressources/sprites/ATTACK.png", &prog->ptr_list);
  prog->attack_button_hover =
  load_image("ressources/sprites/ATTACK_HOVER.png", &prog->ptr_list);
  prog->defend_button =
  load_image("ressources/sprites/DEFEND.png", &prog->ptr_list);
  prog->defend_button_hover =
  load_image("ressources/sprites/DEFEND_HOVER.png", &prog->ptr_list);
  prog->magic_button =
  load_image("ressources/sprites/MAGIC.png", &prog->ptr_list);
  prog->magic_button_hover =
  load_image("ressources/sprites/MAGIC_HOVER.png", &prog->ptr_list);
  prog->skip_button =
  load_image("ressources/sprites/SKIP.png", &prog->ptr_list);
  prog->skip_button_hover =
  load_image("ressources/sprites/SKIP_HOVER.png", &prog->ptr_list);
  prog->text = NULL;
  return (SUCCESS);
}

int			need_shell(int ac, char **av)
{
  int			i;

  i = -1;
  while (++i < ac)
    {
      if (my_strcmp("--shell", av[i]) == 0)
	return (1);
    }
  return (0);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  if (ac != 2)
    {
      return (my_puterror("Error: Use ")
	      + my_puterror(av[0]) + my_puterror(" file.ini\n"));
    }
  if (need_shell(ac, av) == 1)
    {
      start_shell(ac, av);
      return (EXIT_ON_SUCCESS);
    }
  set_max_heap_size(50);
  if (env[0] == 0)
    return (ERROR);
  if ((prog.win = bunny_start(WIN_WIDTH, WIN_HEIGHT, false, WIN_NAME)) == NULL)
    return (ERROR);
  if ((prog.pix0 = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) == NULL)
    return (ERROR);
  if ((prog.pix1 = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) == NULL)
    return (ERROR);
  if ((prog.pix2 = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) == NULL)
    return (ERROR);
  prog.pix = prog.pix0;
  prog.pix_id = 0;
  if (init_prog(&prog, av[1]) == ERROR)
    return (clean(&prog, ERROR));
  bunny_set_click_response(event_click);
  bunny_set_key_response(event_key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 30, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
