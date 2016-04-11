/*
** init_hitbox_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 11 00:14:36 2016 Gaëtan Léandre
** Last update Mon Apr 11 19:28:48 2016 Gaëtan Léandre
*/
#include		"main.h"

t_hitbox		*set_npc_hitbox(t_grille *grille, t_npc *npc,
					t_bunny_position *pos,
					t_ptr_list *ptr_list)
{
  t_hitbox		*result;
  int			hauteur;
  float			coef;
  float			case_x;

  if (npc == NULL)
    return (NULL);
  if ((result = xmalloc(sizeof(t_hitbox), &ptr_list)) == NULL)
    return (NULL);
  coef = (float)((float)grille->size_x - (float)(grille->coef
		 * (float)(grille->grille_y - pos->y/* - 1*/+ 1)))
  / (float)(grille->size_x);
  case_x = ((float)grille->case_x * coef);
  hauteur = case_x * npc->texture_hitbox->height
      / npc->texture_hitbox->width;
  result->x = 10 + (case_x * (float)pos->x);
  result->y = grille->start_y + 10 + get_pos_y(pos->y + 1, grille) - hauteur;
  result->width = case_x;
  result->height = hauteur;
  return (result);
}

t_hitbox		*set_decors_hitbox(t_grille *grille, t_decors *npc,
					   t_bunny_position *pos,
					   t_ptr_list *ptr_list)
{
  t_hitbox		*result;
  int			hauteur;
  float			coef;
  float			case_x;

  if (npc == NULL)
    return (NULL);
  if ((result = xmalloc(sizeof(t_hitbox), &ptr_list)) == NULL)
    return (NULL);
  coef = ((float)grille->size_x - (float)(grille->coef
		 * (float)(grille->grille_y - pos->y + 1)))
  / (float)(grille->size_x);
  case_x = (int)((float)grille->case_x * coef);
  hauteur = case_x * npc->texture_hitbox->height
      / npc->texture_hitbox->width;
  result->x = 10 + (case_x * (float)pos->x);
  result->y = grille->start_y + 10 + get_pos_y(pos->y + 1, grille) - hauteur;
  result->width = case_x;
  result->height = hauteur;
  return (result);
}

void			set_hitbox_ground(t_scene *scene, t_ptr_list *ptr_list)
{
  t_grille		grille;
  t_hitbox		place;
  t_bunny_position	pos;

  place = create_hitbox(0, WIN_HEIGHT - scene->height,
			WIN_WIDTH, scene->height - 206 / 4);
  grille = get_grille_param(&place, scene);
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
