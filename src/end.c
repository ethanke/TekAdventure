/*
** end.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:59:10 2016 Philippe Lefevre
** Last update Thu Apr  7 00:21:10 2016 Gaëtan Léandre
*/

#include		"main.h"

int			clean(t_prog *prog, int out)
{
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_stop(prog->win);
  free_ptr(prog->ptr_list);
  return (out);
}
