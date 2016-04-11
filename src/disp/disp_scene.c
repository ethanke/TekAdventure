/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Mon Apr 11 19:27:21 2016 Gaëtan Léandre
*/

#include		"main.h"

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
  int			i;
  int			j;
  t_hitbox		item;
  t_hitbox		*tmp;
  t_ground		*ground;

  ground = scene->ground;
  i = 0;
  while (i < grille->y)
    {
      j = 0;
      while (j < grille->x)
	{
	  if (ground[j + i * grille->x].npc != NULL && ground[j + i * grille->x].hitbox_npc != NULL)
	    {
	      tmp = ground[j + i * grille->x].hitbox_npc;
	      item = create_hitbox(10 + (int)(((float)(scene->coef * (float)(grille->y - i))) * percent) + tmp->x,
				   tmp->y, tmp->width, tmp->height);
	      place_image(&item, ground[j + i * grille->x].npc->texture_hitbox,
			  ground[j + i * grille->x].npc->texture, pix);
	    }
	  if (ground[j + i * grille->x].decors != NULL && ground[j + i * grille->x].hitbox_decors != NULL)
	    {
	      tmp = ground[j + i * grille->x].hitbox_decors;
	      item = create_hitbox(10 + (int)(((float)(scene->coef * (float)(grille->y - i))) * percent) + tmp->x,
				   tmp->y, tmp->width, tmp->height);
	      place_image(&item, ground[j + i * grille->x].decors->texture_hitbox,
			  ground[j + i * grille->x].decors->texture, pix);
	    }
	  j++;
	}
      i++;
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
  t_hitbox		place;
  t_grille		grille;
  t_bunny_position	pos;
  t_bunny_position	palier;
  int			y;
  float			case_x;
  float			coef;
  t_color		color;
  float			y_pos;
  int			x;

  y = 0;
  place = create_hitbox(0, WIN_HEIGHT - scene->height,
			WIN_WIDTH, scene->height - 206 / 4);
  grille = get_grille_param(&place, scene);
  pos.y = grille.start_y + 10;
  palier.x = pos.y;
  palier.y =  grille.start_y + 10 + get_pos_y(y, &grille);
  while (pos.y < grille.start_y + place.height + 2)
    {
      if (pos.y > palier.y)
	{
	  palier.x = palier.y;
	  palier.y =  grille.start_y + 10 + get_pos_y(++y, &grille);
	}
      y_pos = (float)((float)(pos.y - palier.x) / (float)(palier.y - palier.x)) + (float)y;
      coef = (float)((float)grille.size_x - (float)(grille.coef
    		 * (float)(grille.grille_y - y_pos + 1)))
      / (float)(grille.size_x);
      case_x = ((float)grille.case_x * coef);
      pos.x = ((float)((float)WIN_WIDTH - 20 - (float)case_x * ((float)grille.grille_x)) * percent + 10);
      x = 0;
      while (y >= 1 && x < case_x * (float)((grille.grille_x)))
	{
	  color.full = chose_color(x / case_x, y - 1, grille.grille_x, scene->ground);
	  tektranspa(pix, &pos, &color);
	  x++;
	  pos.x++;
	}
      pos.y++;
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
