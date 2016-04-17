/*
** music->c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 17 05:23:04 2016 Ethan Kerdelhue
** Last update Sun Apr 17 07:02:02 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			update_volume(t_prog *prog)
{
  if (prog->state == STATE_MENU)
    {
      printf(" 2 - %d\n", prog->music->volume);
      bunny_sound_volume(&prog->music->fight->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->menu->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->game->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->fight_sword->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->fight_critic->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->fight_resist->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->fight_magic->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->fight_dodge->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->brouek->sound, prog->music->volume);
      bunny_sound_volume(&prog->music->player_win->sound, prog->music->volume);
    }
  return (0);
}

int			update_music(t_prog *prog)
{
  if (prog->state == STATE_GAME)
    {
      bunny_sound_stop(&prog->music->menu->sound);
      bunny_sound_loop(&prog->music->menu->sound, false);
      bunny_sound_play(&prog->music->game->sound);
      bunny_sound_loop(&prog->music->game->sound, true);
    }
  if (prog->state == STATE_FIGHT)
    {
      bunny_sound_stop(&prog->music->game->sound);
      bunny_sound_loop(&prog->music->game->sound, false);
      bunny_sound_play(&prog->music->fight->sound);
      bunny_sound_loop(&prog->music->fight->sound, true);
    }
  return (0);
}

int			fight_to_game(t_prog *prog)
{
  bunny_sound_stop(&prog->music->fight->sound);
  bunny_sound_loop(&prog->music->fight->sound, false);
  bunny_sound_play(&prog->music->game->sound);
  bunny_sound_loop(&prog->music->game->sound, true);
}

int			start_music(t_prog *prog)
{
  update_volume(prog);
  bunny_sound_play(&prog->music->menu->sound);
  bunny_sound_loop(&prog->music->menu->sound, true);
  return (0);
}
