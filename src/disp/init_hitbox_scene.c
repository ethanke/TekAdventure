/*
** init_hitbox_scene.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 11 00:14:36 2016 Gaëtan Léandre
** Last update Fri Apr 15 23:32:04 2016 Victor Sousa
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
		 * (float)(grille->grille_y - pos->y - 1)))
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

t_hitbox		*set_gate_hitbox(t_grille *grille, t_gate *npc,
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
		 * (float)(grille->grille_y - pos->y - 1)))
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
		 * (float)(grille->grille_y - pos->y - 1)))
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

static int		mega_condition_turfu(t_scene *scene,
					     t_bunny_position pos,
					     t_ptr_list *ptr_list,
					     t_grille grille)
{
  if ((scene->ground[pos.x + pos.y * scene->size.x].npc != NULL &&
       (scene->ground[pos.x + pos.y * scene->size.x].hitbox_npc
	= set_npc_hitbox(&grille, scene->ground[pos.x + pos.y *
			 scene->size.x].npc, &pos, ptr_list)) == NULL) ||
      (scene->ground[pos.x + pos.y * scene->size.x].decors != NULL &&
       (scene->ground[pos.x + pos.y * scene->size.x].hitbox_decors
	= set_decors_hitbox(&grille, scene->ground[pos.x + pos.y *
			    scene->size.x].decors, &pos,
			    ptr_list)) == NULL) ||
      (scene->ground[pos.x + pos.y * scene->size.x].gate != NULL &&
       (scene->ground[pos.x + pos.y * scene->size.x].hitbox_gate
	= set_gate_hitbox(&grille, scene->ground[pos.x + pos.y *
			  scene->size.x].gate, &pos,
			  ptr_list)) == NULL))
    return (-1);
  return (0);
}

int			set_hitbox_ground(t_scene *scene, t_ptr_list *ptr_list)
{
  t_grille		grille;
  t_bunny_position	pos;

  grille = get_grille_with_place(scene);
  pos.y = -1;
  while (++pos.y < scene->size.y)
    {
      pos.x = -1;
      while (++pos.x < scene->size.x)
	{
	  /* INITIALISATION A VIRER */
	  scene->ground[pos.x + pos.y * scene->size.x].gate = NULL;
	  if (mega_condition_turfu(scene, pos, ptr_list, grille) == -1)
	    return (-1);
	}
    }
  return (0);
}
