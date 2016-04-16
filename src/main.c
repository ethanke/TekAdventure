/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Sat Apr 16 23:42:41 2016 Gaëtan Léandre
*/

#include		"main.h"

int			init_prog(t_prog *prog, char *str)
{
  prog->blit_pos.x = 0;
  prog->blit_pos.y = 0;
  prog->ptr_list = NULL;
  if ((prog->scene = parsing(str, &prog->player, &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->disp_delay = 0;
  prog->state = STATE_MENU;
  prog->need_init_fight = 1;
  if ((prog->font = xmalloc(sizeof(t_font), &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->font->font_img =
       load_image("ressources/sprites/font1.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->font->font_size = 50;
  prog->font->font_color.full = 0xFF000000;
  if ((prog->fight_img = load_image("ressources/sprites/fight.jpg",
				    &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->npc_choose =
       load_image("ressources/sprites/npc_choose.png",
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
  prog->menu_bg_pos.x = 50;
  prog->menu_bg_pos.y = 0;
  prog->menu_dir = 0;
  if ((prog->menu_bg =
       load_image("ressources/sprites/menubg.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->menu_text =
       load_image("ressources/sprites/textmenu.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->game_over_img =
       load_image("ressources/sprites/gameover.png", &prog->ptr_list)) == NULL)
  return (ERROR);
  if ((prog->game_over_img =
       load_image("ressources/sprites/gameover.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->over_quit =
       load_image("ressources/sprites/over_quit.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->over_continue =
       load_image("ressources/sprites/over_continue.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->fight_img =
       load_image("ressources/sprites/fight.jpg", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->attack_button =
       load_image("ressources/sprites/ATTACK.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->attack_button_hover =
       load_image("ressources/sprites/ATTACK_HOVER.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->defend_button =
       load_image("ressources/sprites/DEFEND.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->defend_button_hover =
       load_image("ressources/sprites/DEFEND_HOVER.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->magic_button =
       load_image("ressources/sprites/MAGIC.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->magic_button_hover =
       load_image("ressources/sprites/MAGIC_HOVER.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->skip_button =
       load_image("ressources/sprites/SKIP.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->skip_button_hover =
       load_image("ressources/sprites/SKIP_HOVER.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  prog->text = NULL;
  return (SUCCESS);
}

int			pars_arg(int ac, char **av)
{
  int			len;

  if (ac > 2)
    return (my_puterror(av[0]) + my_puterror(": too many argument\n"));
  else if (ac == 2)
    {
      len = my_strlen(av[1]);
      if (!(my_strcmp("--shell", av[1])))
	{
	  start_shell(ac, av);
          return (0);
	}
      else if (!(my_strcmp("--credit", av[1])))
	return (write(1, "	TekAdventure\n", 14)
		+ write(1, "Leadre Gaetan - Sousa Victor - ", 31)
		+ write (1, "Philippe Lefvre - Ethan Kerdelhue\n", 34));
      else if ((len > 4) && av[1][len - 4] == '.' && av[1][len - 3] == 'i'
	       && av[1][len - 2] == 'n' && av[1][len - 1] == 'i')
	return (0);
      return (my_puterror(av[0]) + my_puterror(": [ARG]\n")
	      + my_puterror("	--shell		launch editor\n")
	      + my_puterror("	exemple.ini	ini file game\n")
	      + my_puterror("	--credit	display (c) credit\n") - 1);
    }
  return (-1);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  set_max_heap_size(50);
  if (pars_arg(ac, av))
    return (ERROR);
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
      prog.player->move.depla = NULL;
      prog.player->x_vec = 0;
      prog.player->x_vec = 0;
  bunny_set_click_response(event_click);
  bunny_set_key_response(event_key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 30, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
