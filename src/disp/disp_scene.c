/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Wed Apr 13 02:58:18 2016 Gaëtan Léandre
*/

#include	 	"main.h"

/*void			disp_background(t_back *first, t_bunny_pixelarray *pix,
					float percent)
{
  t_back		*tmp;
  t_hitbox		pos;
  int			dist_max;
  int			size;

  tmp = first;
  fill_image(pix, BLACK);
  while (tmp->next != NULL)
    tmp = tmp->next;
  dist_max = tmp->dist;
  while (tmp != NULL)
    {
      size = dist_max - tmp->dist;
      pos.width = tmp->sprite->width + size;
      pos.height = tmp->sprite->height;
      pos.x = (int)((float)size * percent) - size;
      pos.y = 0;
      redim_image(&pos, tmp->sprite, pix);
      tmp = tmp->prev;
    }
}*/

void			put_grille(t_scene *scene, t_bunny_position *grille,
				   float percent, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_hitbox		*tmp;
  t_ground		*ground;

  ground = scene->ground;
  pos.y = -1;
  while (++pos.y < grille->y)
    {
      pos.x = -1;
      while (++pos.x < grille->x)
	{
	  if (ground[pos.x + pos.y * grille->x].npc != NULL && ground[pos.x + pos.y * grille->x].hitbox_npc != NULL)
	    {
	      tmp = ground[pos.x + pos.y * grille->x].hitbox_npc;
	      place_image(create_hitbox((int)(((float)(scene->coef * (float)(grille->y - pos.y))) * percent) + tmp->x,
					tmp->y, tmp->width, tmp->height), *ground[pos.x + pos.y * grille->x].npc->texture_hitbox,
			  ground[pos.x + pos.y * grille->x].npc->texture, pix);
	    }
	  if (ground[pos.x + pos.y * grille->x].decors != NULL && ground[pos.x + pos.y * grille->x].hitbox_decors != NULL)
	    {
	      tmp = ground[pos.x + pos.y * grille->x].hitbox_decors;
	      place_image(create_hitbox((int)(((float)(scene->coef * (float)(grille->y - pos.y))) * percent) + tmp->x,
	                          tmp->y, tmp->width, tmp->height), *ground[pos.x + pos.y * grille->x].decors->texture_hitbox,
	                    ground[pos.x + pos.y * grille->x].decors->texture, pix);
	    }
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

void			disp_ground(t_scene *scene, t_bunny_pixelarray *pix,
				    float percent)
{
/*  t_hitbox		pos;*/

/*  pos = create_hitbox(0, pix->clipable.clip_height - scene->height,
		      pix->clipable.clip_width, scene->height);
  redim_image(&pos, scene->sol, pix);*/
  put_grille(scene, &scene->size, percent, pix);
  disp_cases(scene, pix, percent);
}
