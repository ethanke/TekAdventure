/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Sat Apr 16 19:19:48 2016 Ethan Kerdelhue
*/

#include	 	"main.h"

void			disp_background(t_sky *sky, t_bunny_pixelarray *pix,
					float percent, int height)
{
  t_sky		*tmp;
  t_hitbox		pos;
  int			dist_max;
  int			size;

  tmp = sky;
  fill_pix(pix, BLACK);
  while (tmp->next != NULL)
    tmp = tmp->next;
  dist_max = DIST_MAX;
  while (tmp != NULL)
    {
      size = dist_max - tmp->distance;
      pos.width = pix->clipable.clip_width + size;
      pos.height = pix->clipable.clip_height - height;
      pos.x = (int)((float)size * percent) - size;
      pos.y = 0;
      redim_image(&pos, tmp->texture, pix);
      tmp = tmp->prev;
    }
}

void			put_grille(t_prog *prog, t_grille *gri,
				   float percent, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_hitbox		*tmp;
  t_ground		*gro;

  gro = prog->scene->ground;
  pos.y = -1;
  while (++pos.y < gri->grille_y - 1)
    {
      if ((int)prog->player->y == pos.y)
	deplacement(prog->player, prog->scene, prog->pix, prog->percent);
      pos.x = -1;
      while (++pos.x < gri->grille_x)
	{
	  if (gro[pos.x + pos.y * gri->grille_x].gate != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->grille_x].hitbox_gate) != NULL)
	    place_image(create_hitbox(calc_x_h(gri, &pos, percent, tmp->x),
				      tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->grille_x].gate->texture_hitbox,
			gro[pos.x + pos.y * gri->grille_x].gate->texture, pix);
	  if (gro[pos.x + pos.y * gri->grille_x].npc != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->grille_x].hitbox_npc) != NULL)
	      place_image(create_hitbox(calc_x_h(gri, &pos, percent, tmp->x),
					tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->grille_x].npc->texture_hitbox,
			  gro[pos.x + pos.y * gri->grille_x].npc->texture, pix);
	  if (gro[pos.x + pos.y * gri->grille_x].decors != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->grille_x].hitbox_decors) != NULL)
		place_image(create_hitbox(calc_x_h(gri, &pos, percent, tmp->x),
					  tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->grille_x].decors->texture_hitbox,
			    gro[pos.x + pos.y * gri->grille_x].decors->texture, pix);
	}
    }
}

void			disp_ground(t_prog *prog, int disp)
{
  t_hitbox		place;
  t_grille		grille;

  grille = get_grille_with_place(prog->scene);
  place = create_hitbox(0, WIN_HEIGHT - prog->scene->height,
			WIN_WIDTH, prog->scene->height);
  make_deplacement(prog->player);
  disp_background(prog->scene->sky, prog->pix, prog->percent, prog->scene->height);
  place_image(place, *prog->scene->sol_hitbox, prog->scene->sol, prog->pix);
  deplacement(prog->player, prog->scene, prog->pix, prog->percent);
  prog->scene->coef = (float)(EQUART *  2) / (float)prog->scene->size.y;
  put_grille(prog, &grille, prog->percent, prog->pix);
  if (disp == 1)
    disp_cases(prog->scene, prog->pix, prog->percent);
  on_gate(prog);
}
