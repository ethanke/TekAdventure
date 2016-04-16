/*
** set_click.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/npc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 07:48:03 2016 Ethan Kerdelhue
** Last update Sat Apr 16 07:49:50 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			set_click_npc(t_map_click *click,
				  t_ground *ground,
				  t_bunny_position pos,
				  t_grille *grille)
{
  click->x = pos.x;
  click->y = pos.y;
  click->npc = ground[pos.x + pos.y * grille->grille_x].npc;
}

void			set_click_decors(t_map_click *click,
				  t_ground *ground,
				  t_bunny_position pos,
				  t_grille *gril)
{
  click->x = pos.x;
  click->y = pos.y;
  click->decors = ground[pos.x + pos.y * gril->grille_x].decors;
}
