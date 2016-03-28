/*
** end.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:59:10 2016 Philippe Lefevre
** Last update Mon Mar 28 20:01:39 2016 Philippe Lefevre
*/

#include		"tekadventure.h"

int			clean(t_prog *prog, int out)
{
  bunny_delete_clipable(&prog->array->clipable);
  bunny_stop(prog->win);
  return (out);
}
