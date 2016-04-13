/*
** move.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 04:57:09 2016 Gaëtan Léandre
** Last update Wed Apr 13 07:05:57 2016 Gaëtan Léandre
*/

#include		"main.h"

void			disp_deplacement(t_player *player, t_grille *grille,
					 t_bunny_pixelarray *pix, int percent)
{
  float			case_x;
  float			coef;
  int			hauteur;
  int			pos_x;
    int			pos_y;
  int			pal_prev;
  int			pal_next;

  coef = (float)((float)grille->size_x - (float)(grille->coef
               * (float)((float)grille->grille_y - (float)player->y - 1)))
  / (float)(grille->size_x);
  case_x = ((float)grille->case_x * coef);
  hauteur = case_x * player->sprite->height
      / player->sprite->width;
  pos_x = (int)(((float)(grille->coef *
		 (float)((float)grille->grille_y - 1 - player->y))) * percent) +
  ((float)player->x * case_x);
  pal_prev = grille->start_y + 10 + get_pos_y((int)player->y, grille);
  pal_next = grille->start_y + 10 + get_pos_y((int)player->y + 1, grille);
  pos_y = player->y * (float)(pal_next - pal_prev) + pal_prev - hauteur;
  place_image(create_hitbox(pos_x, pos_y, (int)case_x, hauteur),
	      *player->sprite_hitbox, player->sprite, pix);
}

void			make_deplacement(t_player *player)
{
  t_depla		*depla;

  depla = player->move.depla;
  if (depla != NULL && depla->x == player->x && depla->y == player->y)
    {
      player->move.depla = depla->next;
      free(depla);
      depla = player->move.depla;
    }
  if (depla == NULL)
    return;
  if (player->x < depla->x)
    player->x += 0.05;
  else if (player->x > depla->x)
    player->x -= 0.05;
  if (player->y < depla->y)
    player->y += 0.05;
  else if (player->y > depla->y)
    player->y -= 0.05;
}

void			deplacement(t_player *player, t_scene *scene,
				    t_bunny_pixelarray *pix, int percent)
{
  t_grille		grille;

  grille = get_grille_with_place(scene);
  make_deplacement(player);
  disp_deplacement(player, &grille, pix, percent);
}
