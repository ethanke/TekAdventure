/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Fri Apr 15 05:40:28 2016 Gaëtan Léandre
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

void			put_grille(t_prog *prog, t_bunny_position *gri,
				   float percent, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_hitbox		*tmp;
  t_ground		*gro;
  float			coef;

  gro = prog->scene->ground;
  coef = prog->scene->coef;
  pos.y = -1;
  while (++pos.y < gri->y)
    {
      if ((int)prog->player->y == pos.y)
	deplacement(prog->player, prog->scene, prog->pix, prog->percent);
      pos.x = -1;
      while (++pos.x < gri->x)
	{
	  if (gro[pos.x + pos.y * gri->x].gate != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->x].hitbox_gate) != NULL)
	    place_image(create_hitbox((int)(((float)(coef * (float)(gri->y - pos.y))) * percent) + tmp->x,
				      tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->x].gate->texture_hitbox,
			gro[pos.x + pos.y * gri->x].gate->texture, pix);
	  if (gro[pos.x + pos.y * gri->x].npc != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->x].hitbox_npc) != NULL)
	      place_image(create_hitbox((int)(((float)(coef * (float)(gri->y - pos.y))) * percent) + tmp->x,
					tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->x].npc->texture_hitbox,
			  gro[pos.x + pos.y * gri->x].npc->texture, pix);
	  if (gro[pos.x + pos.y * gri->x].decors != NULL &&
	      (tmp = gro[pos.x + pos.y * gri->x].hitbox_decors) != NULL)
		place_image(create_hitbox((int)(((float)(coef * (float)(gri->y - pos.y))) * percent) + tmp->x,
					  tmp->y, tmp->width, tmp->height), *gro[pos.x + pos.y * gri->x].decors->texture_hitbox,
			    gro[pos.x + pos.y * gri->x].decors->texture, pix);
	}
    }
}

unsigned int		chose_color(int x, int y, int size_x, t_ground *ground)
{
  t_color		color;
  if (ground[x + y * size_x].npc == NULL && ground[x + y * size_x].decors == NULL)
    color.full = WHITE;
  else
    color.full = RED;
  color.argb[3] = 100;
  return (color.full);
}

void			disp_cases(t_scene *scene, t_bunny_pixelarray *pix,
				   float percent)
{
  t_grille		grille;
  t_bunny_position	pos;
  t_bunny_position	palier;
  t_bunny_position	tmp;
  float			case_x;
  t_color		color;

  tmp.y = 0;
  grille = get_grille_with_place(scene);
  pos.y = grille.start_y + 10 - 1;
  palier.x = pos.y;
  palier.y =  grille.start_y + 10 + get_pos_y(tmp.y, &grille);
  while (++pos.y < grille.start_y + grille.height + 2)
    {
      if (pos.y > palier.y)
	{
	  palier.x = palier.y;
	  palier.y =  grille.start_y + 10 + get_pos_y(++(tmp.y), &grille);
	}
      case_x = calc_case_x(&grille, pos.y, &palier, tmp.y);
      pos.x = ((float)((float)WIN_WIDTH - 30 - (float)case_x
		* ((float)grille.grille_x)) * percent + 10);
      tmp.x = -1;
      while (tmp.y >= 1 && ++(tmp.x) < case_x * (float)((grille.grille_x)))
	{
	  color.full = chose_color(tmp.x / case_x, tmp.y - 1,
				   grille.grille_x, scene->ground);
	  tektranspa(pix, &pos, &color);
	  pos.x++;
	}
    }
}

void			disp_ground(t_prog *prog, int disp)
{
  t_hitbox		place;

  place = create_hitbox(0, WIN_HEIGHT - prog->scene->height,
			WIN_WIDTH, prog->scene->height);
  make_deplacement(prog->player);
  disp_background(prog->scene->sky, prog->pix, prog->percent, prog->scene->height);
  place_image(place, *prog->scene->sol_hitbox, prog->scene->sol, prog->pix);
  deplacement(prog->player, prog->scene, prog->pix, prog->percent);
  put_grille(prog, &prog->scene->size, prog->percent, prog->pix);
  if (disp == 1)
    disp_cases(prog->scene, prog->pix, prog->percent);
  on_gate(prog);
}
