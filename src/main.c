/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Thu Apr  7 05:25:40 2016 victor sousa
*/

#include		"main.h"

int			init_prog(t_prog *prog)
{
  prog->blit_pos.x = 0;
  prog->blit_pos.y = 0;
  prog->ptr_list = NULL;

  prog->inv[0][0] = 0;
  prog->inv[0][1] = 0;
  prog->inv[0][2] = 0;
  prog->inv[0][3] = 0;
  prog->inv[0][4] = 0;
  prog->inv[0][5] = 0;
  prog->inv[0][6] = 0;
  prog->inv[0][7] = 0;
  prog->inv[0][8] = 0;

  prog->inv[1][0] = 0;
  prog->inv[1][1] = 0;
  prog->inv[1][2] = 0;
  prog->inv[1][3] = 0;
  prog->inv[1][4] = 0;
  prog->inv[1][5] = 0;
  prog->inv[1][6] = 0;
  prog->inv[1][7] = 0;
  prog->inv[1][8] = 0;

  prog->inv[2][0] = 0;
  prog->inv[2][1] = 0;
  prog->inv[2][2] = 0;
  prog->inv[2][3] = 0;
  prog->inv[2][4] = 0;
  prog->inv[2][5] = 0;
  prog->inv[2][6] = 0;
  prog->inv[2][7] = 0;
  prog->inv[2][8] = 0;

  prog->inv[3][0] = 0;
  prog->inv[3][1] = 0;
  prog->inv[3][2] = 0;
  prog->inv[3][3] = 0;
  prog->inv[3][4] = 0;
  prog->inv[3][5] = 0;
  prog->inv[3][6] = 0;
  prog->inv[3][7] = 0;
  prog->inv[3][8] = 0;
  prog->player.inventory_open = 0;
  if ((prog->player.inv_open_sprite =
       load_image("ressources/sprites/inventory_full.png", &prog->ptr_list)) == NULL)
    return (ERROR);
  return (SUCCESS);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  (void)ac;
  (void)av;
  set_max_heap_size(500);
  if (env == NULL)
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
  if (init_prog(&prog) == ERROR)
    return (clean(&prog, ERROR));
  if ((prog.lion_img = load_image("ressources/sprites/lion.jpg", &prog.ptr_list)) == NULL)
    return (ERROR);
  bunny_set_key_response(event_key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 60, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
