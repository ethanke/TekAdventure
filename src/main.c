/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Wed Apr  6 21:07:33 2016 victor sousa
*/

#include		"main.h"

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  (void)ac;
  (void)av;
  if (env == NULL)
    return (ERROR);
  if ((prog.win = bunny_start(WIN_WIDTH, WIN_HEIGHT, false, WIN_NAME)) == NULL)
    return (ERROR);
  if ((prog.array = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) == NULL)
    return (ERROR);
  bunny_set_key_response(event_key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 60, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
