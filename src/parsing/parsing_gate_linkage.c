/*
** parsing_gate.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Fri Apr 15 22:44:02 2016 Philippe Lefevre
** Last update Sun Apr 17 10:35:17 2016 Philippe Lefevre
*/

#include		"main.h"

t_gate			*link_gate(t_gate *gate, t_sprite *sprite)
{
  t_gate		*tmp_gate;
  t_sprite		*tmp_sprite;

  tmp_gate = gate;
  while (tmp_gate != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_gate->sprite_id)
	    tmp_gate->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_gate = tmp_gate->next;
    }
  return (gate);
}
