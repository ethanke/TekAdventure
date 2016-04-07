/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Thu Apr  7 03:42:43 2016 Gaëtan Léandre
*/

#include		"main.h"

void			disp_background(t_back *first, t_bunny_pixelarray *pix)
{
  t_back		*tmp;

  tmp = first;
  fill_image(pix, BLACK);
  while (tmp->next != NULL)
    tmp = tmp->next;
}
