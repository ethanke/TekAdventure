/*
** move.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 04:57:09 2016 Gaëtan Léandre
** Last update Sun Apr 17 07:24:02 2016 Gaëtan Léandre
*/

#include		"main.h"

void			make_astar(t_player *player,
				   t_bunny_position *size,
				   t_bunny_position *to_go,
				   t_ground *ground)
{
  t_posi		siz;
  t_posi		pos;
  t_posi		end;
  t_depla		*depla;

  siz.x = size->x;
  siz.y = size->y;
  pos.x = (int)player->x;
  pos.y = (int)player->y;
  end.x = to_go->x;
  end.y = to_go->y;
  while (player->move.depla != NULL)
    {
      depla = player->move.depla;
      player->move.depla = player->move.depla->next;
      free(depla);
    }
  player->move.depla = a_star(ground, &siz, &pos, &end);
  if (player->move.depla != NULL)
    {
      player->x_vec = ((float)player->move.depla->x - player->x) / 2;
      player->y_vec = ((float)player->move.depla->y - player->y) / 2;
    }
}

void			disp_deplacement(t_player *player,
					 t_grille *grille,
					 t_bunny_pixelarray *pix,
					 float percent)
{
  float			case_x;
  float			coef;
  int			hauteur;
  t_bunny_position	pos;
  int			pal_prev;
  int			pal_next;
  t_anim		*anim;

  coef = (float)((float)grille->size_x - (float)(grille->coef
               * (float)((float)grille->grille_y - (float)player->y - 1)))
  / (float)(grille->size_x);
  case_x = ((float)grille->case_x * coef);
  hauteur = case_x * player->sprite->height
      / player->sprite->width;
  pos.x = 10 + (int)(((float)(grille->coef *
		 (float)((float)grille->grille_y - 1 - player->y))) * percent)
  + ((float)player->x * case_x);
  pal_prev = grille->start_y + 10 + get_pos_y((int)player->y, grille);
  pal_next = grille->start_y + 10 + get_pos_y((int)player->y + 1, grille);
  pos.y = 20 + (float)((player->y - (int)player->y)
		* (float)(pal_next - pal_prev)) + pal_prev - hauteur;
  anim = chose_deplacement(player);
  animated_image(anim, create_hitbox(pos.x, pos.y, (int)case_x, hauteur),
		 pix);
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
      if (depla != NULL)
	{
	  player->x_vec = ((float)depla->x - player->x) / 4;
	  player->y_vec = ((float)depla->y - player->y) / 4;
	}
      else
	player->x_vec = (player->y_vec = 0) * 0;
    }
  if (depla != NULL)
    {
      player->x += player->x_vec;
      player->y += player->y_vec;
    }
  else
    player->x_vec = (player->y_vec = 0) * 0;
}

void			deplacement(t_player *player, t_scene *scene,
				    t_bunny_pixelarray *pix, float percent)
{
  t_grille		grille;

  grille = get_grille_with_place(scene);
  disp_deplacement(player, &grille, pix, percent);
}

void			test_move(t_prog *prog, t_bunny_position *mouse_pos)
{
  t_bunny_position	pos;

  pos = get_pos(prog->scene, prog->percent, mouse_pos);
  make_astar(prog->player, &prog->scene->size, &pos, prog->scene->ground);
}
