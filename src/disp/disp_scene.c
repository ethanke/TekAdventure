/*
** disp_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 02:56:24 2016 Gaëtan Léandre
** Last update Sat Apr  9 11:44:16 2016 Gaëtan Léandre
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

t_hitbox		*set_npc_hitbox(t_grille *grille, t_npc *npc,
					t_bunny_position *pos,
					t_ptr_list *ptr_list)
{
  t_hitbox		*result;
  int			hauteur;

  if (npc == NULL)
    return (NULL);
  if ((result = xmalloc(sizeof(t_hitbox), &ptr_list)) == NULL)
    return (NULL);
  hauteur = grille->case_x * npc->texture->height / npc->texture->width;
  result->x = 10 + grille->case_x * pos->x;
  result->y = grille->start_y + 10 + grille->case_y * (pos->y + 1) - hauteur;
  result->width = grille->case_x;
  result->height = hauteur;
  return (result);
}

t_hitbox		*set_decors_hitbox(t_grille *grille, t_decors *decors,
					   t_bunny_position *pos,
					   t_ptr_list *ptr_list)
{
  t_hitbox		*result;
  int			hauteur;

  if (decors == NULL)
    return (NULL);
  if ((result = xmalloc(sizeof(t_hitbox), &ptr_list)) == NULL)
    return (NULL);
  hauteur = grille->case_x * decors->texture->height / decors->texture->width;
  result->x = 10 + grille->case_x * pos->x;
  result->y = grille->start_y + 10 + grille->case_y * (pos->y + 1) - hauteur;
  result->width = grille->case_x;
  result->height = hauteur;
  return (result);
}

t_grille		get_grille_param(t_hitbox *place,
					 t_bunny_position *size)
{
  t_grille		grille;

  grille.case_x = (place->width - 20) / size->x;
  grille.case_y = (place->height - 20) / (size->y + 1);
  grille.start_y = place->y;
  return (grille);
}

void			put_grille(t_ground *ground, t_bunny_position *grille,
				   float percent, t_bunny_pixelarray *pix)
{
  int			i;
  int			j;
  t_hitbox		item;
  t_hitbox		*tmp;

  i = 0;
  while (i < grille->y)
    {
      j = 0;
      while (j < grille->x)
	{
	  if (ground[j + i * grille->x].npc != NULL)
	    {
	      tmp = ground[j + i * grille->x].hitbox_npc;
	      item = create_hitbox((int)((float)(EQUART * ((float)(grille->y - i - 1) / (float)grille->y)) * percent) + tmp->x,
				   tmp->y, tmp->width, tmp->height);
	      place_image(&item, ground[j + i * grille->x].npc->texture_hitbox,
			  ground[j + i * grille->x].npc->texture, pix);
	    }
	  if (ground[j + i * grille->x].decors != NULL)
	    {
	      tmp = ground[j + i * grille->x].hitbox_decors;
	      item = create_hitbox((int)((float)(EQUART * ((float)(grille->y - i - 1) / (float)grille->y)) * percent) + tmp->x,
				   tmp->y, tmp->width, tmp->height);
	      place_image(&item, ground[j + i * grille->x].decors->texture_hitbox,
			  ground[j + i * grille->x].decors->texture, pix);
	    }
	  j++;
	}
      i++;
    }
}

void			set_hitbox_ground(t_scene *scene, t_ptr_list *ptr_list,
					  t_bunny_pixelarray *pix)
{
  t_grille		grille;
  t_hitbox		place;
  t_bunny_position	pos;

  place = create_hitbox(0, pix->clipable.clip_height - scene->height,
			pix->clipable.clip_width, scene->height);
  grille = get_grille_param(&place, &scene->size);
  pos.y = 0;
  while (pos.y < scene->size.y)
    {
      pos.x = -1;
      while (++pos.x < scene->size.x)
	{
	  scene->ground[pos.x + pos.y * scene->size.x].hitbox_npc
	  = set_npc_hitbox(&grille,
			   scene->ground[pos.x + pos.y * scene->size.x].npc,
			   &pos, ptr_list);
	  scene->ground[pos.x + pos.y * scene->size.x].hitbox_decors
	  = set_decors_hitbox(&grille,
			      scene->ground[pos.x + pos.y
			      * scene->size.x].decors,
			      &pos, ptr_list);
	}
      pos.y++;
    }
}

void			disp_ground(t_scene *scene, t_bunny_pixelarray *pix,
				    float percent)
{
  t_hitbox		pos;

  pos = create_hitbox(0, pix->clipable.clip_height - scene->height,
		      pix->clipable.clip_width, scene->height);
  redim_image(&pos, scene->sol, pix);
  put_grille(scene->ground, &scene->size, percent, pix);
}
