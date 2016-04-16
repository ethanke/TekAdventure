/*
** norm_triste.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 19:12:33 2016 Ethan Kerdelhue
** Last update Sat Apr 16 19:12:45 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			norm_triste(t_bunny_position *palier,
				    t_bunny_position *tmp,
				    t_grille *grille)
{
  palier->x = palier->y;
  palier->y =  grille->start_y + 10 + get_pos_y(++(tmp->y), grille);
}
