/*
** main.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:53:19 2016 Philippe Lefevre
** Last update Mon Mar 28 19:53:44 2016 Philippe Lefevre
*/

#include		<lapin.h>
#include		"main.h"

static t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*data)
{
  t_prog		*prog;

  (void)state;
  (void)data;
  prog = (t_prog *)data;
  (void)prog;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response	mainloop(void *p)
{
  t_prog			*prog;

  prog = p;
  bunny_blit(&prog->win->buffer, &prog->array->clipable, &prog->position);
  bunny_display(prog->win);
  return (GO_ON);
}

static int		clean(t_prog *prog,
			      int out)
{
  bunny_delete_clipable(&prog->array->clipable);
  bunny_stop(prog->win);
  return (out);
}

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
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  if (bunny_loop(prog.win, 60, &prog) == EXIT_ON_ERROR)
    return (clean(&prog, ERROR));
  return (clean(&prog, SUCCESS));
}
