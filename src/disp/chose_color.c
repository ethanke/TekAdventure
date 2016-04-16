/*
** chose_color.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 19:18:23 2016 Ethan Kerdelhue
** Last update Sat Apr 16 19:18:32 2016 Ethan Kerdelhue
*/

#include		"main.h"

unsigned int		chose_color(int x, int y, int size_x, t_ground *ground)
{
  t_color		color;
  if (ground[x + y * size_x].npc == NULL
      && ground[x + y * size_x].decors == NULL
      && ground[x + y * size_x].gate == NULL)
    color.full = WHITE;
  else if (ground[x + y * size_x].gate != NULL)
    color.full = GREEN;
  else
    color.full = RED;
  color.argb[3] = 100;
  return (color.full);
}
