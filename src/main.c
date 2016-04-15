/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Fri Apr 15 04:28:00 2016 Philippe Lefevre
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
  prog->player->move.select_move = 0;
  prog->player->move.depla = NULL;
  prog->player->x = 8;
  prog->player->y = 0;
  prog->disp_delay = 0;
  prog->player->item_selected = -1;
  prog->state = STATE_GAME;
  prog->need_init_fight = 1;
  if ((prog->font =
       xmalloc(sizeof(t_font), &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->font->font_img =
       load_image("ressources/sprites/font1.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->font->font_size = 50;
  prog->font->font_color.full = 0xFF000000;
  if ((prog->fight_img = load_image("ressources/sprites/fight.jpg", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->player->inv_open_sprite =
       load_image("ressources/sprites/inventory_full.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->npc_choose =
       load_image("ressources/sprites/npc_choose.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->player->hotbar_sprite =
       load_image("ressources/sprites/hotbar.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->exchange_sprite =
       load_image("ressources/sprites/exchange.png", &prog->ptr_list)) == NULL)
    return (ERROR);
    /* penser vérifié le retour */
    prog->fight_img = load_image("ressources/sprites/fight.jpg", &prog->ptr_list);
    prog->attack_button = load_image("ressources/sprites/ATTACK.png", &prog->ptr_list);
    prog->attack_button_hover = load_image("ressources/sprites/ATTACK_HOVER.png", &prog->ptr_list);
    prog->defend_button = load_image("ressources/sprites/DEFEND.png", &prog->ptr_list);
    prog->defend_button_hover = load_image("ressources/sprites/DEFEND_HOVER.png", &prog->ptr_list);
    prog->magic_button = load_image("ressources/sprites/MAGIC.png", &prog->ptr_list);
    prog->magic_button_hover = load_image("ressources/sprites/MAGIC_HOVER.png", &prog->ptr_list);
    prog->skip_button = load_image("ressources/sprites/SKIP.png", &prog->ptr_list);
    prog->skip_button_hover = load_image("ressources/sprites/SKIP_HOVER.png", &prog->ptr_list);
  return (SUCCESS);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  if (ac != 2)
    return (my_puterror("Error: Use ")
	    + my_puterror(av[0]) + my_puterror(" file.ini\n"));
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
