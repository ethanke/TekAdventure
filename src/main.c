/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Thu Apr  7 23:43:59 2016 Philippe Lefevre
*/

#include		"main.h"

int			init_prog(t_prog *prog)
{
  prog->blit_pos.x = 0;
  prog->blit_pos.y = 0;
  prog->ptr_list = NULL;
  prog->player->inventory_open = 0;
  if ((prog->player->inv_open_sprite =
       load_image("ressources/sprites/inventory_full.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  if ((prog->player->hotbar_sprite =
       load_image("ressources/sprites/hotbar.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  return (SUCCESS);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  if (ac != 2)
    return (my_puterror("Error: Use ")
	    + my_puterror(av[0]) + my_puterror(" file.ini\n"));
  set_max_heap_size(500);
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
  
  prog.player = load_player(bunny_load_ini(av[1]), &prog.ptr_list);
  
  if (init_prog(&prog) == ERROR)
    return (clean(&prog, ERROR));
  if (parsing(av[1], &prog.ptr_list))
    return (ERROR);
  if ((prog.lion_img = load_image("ressources/sprites/lion.jpg", &prog.ptr_list)) == NULL)
    return (ERROR);
  bunny_set_key_response(event_key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 60, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
