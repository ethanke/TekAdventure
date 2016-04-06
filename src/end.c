/*
** end.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:59:10 2016 Philippe Lefevre
** Last update Wed Apr  6 23:21:19 2016 victor sousa
*/

#include		"main.h"

int			clean(t_prog *prog, int out)
{
  bunny_delete_clipable(&prog->array->clipable);
  bunny_stop(prog->win);
  free_ptr(prog->ptr_list);
  return (out);
}
