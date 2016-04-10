/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Mon Apr 11 00:38:46 2016 Gaëtan Léandre
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

void			disp_ground(t_scene *scene, t_bunny_pixelarray *pix,
				    float percent)
{
/*  t_hitbox		pos;*/

/*  pos = create_hitbox(0, pix->clipable.clip_height - scene->height,
		      pix->clipable.clip_width, scene->height);
  redim_image(&pos, scene->sol, pix);*/
  put_grille(scene, &scene->size, percent, pix);
}
