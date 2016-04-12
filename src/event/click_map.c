/*
** click_map.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 12 03:55:39 2016 Gaëtan Léandre
** Last update Wed Apr 13 00:03:32 2016 Gaëtan Léandre
*/

#include		"main.h"

int			in_hitbox(t_hitbox *hitbox, t_bunny_position *pos)
{
  if (pos->x > hitbox->x && pos->x < hitbox->x + hitbox->width
      && pos->y > hitbox->y && pos->y < hitbox->height + pos->y)
    return (1);
  return (0);
}

void			get_npc_clicked(t_ground *ground, t_grille *grille,
					t_map_click *click, float percent)
{
  int			x;
  int			y;
  t_hitbox		item;
  t_hitbox		*tmp;

  y = grille->grille_y - 2;
  while (y >= 0)
    {
      x = 0;
      while (x < grille->grille_x)
	{
	  if (ground[x + y * grille->grille_x].npc != NULL)
	    {
	      tmp = ground[x + y * grille->grille_x].hitbox_npc;
	      item = create_hitbox((int)(((float)(grille->coef *
					  (float)(grille->grille_y - y - 1))) * percent)
				   + tmp->x, tmp->y, tmp->width, tmp->height);
	      if (in_hitbox(&item, click->mouse_pos) == 1)
		{
		  click->x = x;
		  click->y = y;
		  click->pos.x = item.x;
		  click->pos.y = item.y;
		  click->npc = ground[x + y * grille->grille_x].npc;
		  return;
		}
	    }
	  x++;
	}
      y--;
    }
    click->x = -1;
    click->y = -1;
}

void			get_decors_clicked(t_ground *ground, t_grille *grille,
					   t_map_click *click, float percent)
{
  int			x;
  int			y;
  t_hitbox		item;
  t_hitbox		*tmp;

  y = grille->grille_y - 2;
  while (y >= 0)
    {
      x = 0;
      while (x < grille->grille_x)
	{
	  if (ground[x + y * grille->grille_x].decors != NULL)
	    {
	      tmp = ground[x + y * grille->grille_x].hitbox_decors;
	      item = create_hitbox((int)(((float)(grille->coef *
					  (float)(grille->grille_y - y - 1))) * percent)
				   + tmp->x, tmp->y, tmp->width, tmp->height);
	      if (in_hitbox(&item, click->mouse_pos) == 1)
		{
		  click->x = x;
		  click->y = y;
                  click->pos.x = item.x;
                  click->pos.y = item.y;
		  click->decors = ground[x + y * grille->grille_x].decors;
		  return;
		}
	    }
	  x++;
	}
      y--;
    }
  click->x = -1;
  click->y = -1;
}

void			get_decors_wnpc(t_ground *ground, t_grille *grille,
					t_map_click *click, float percent)
{
  int			x;
  int			y;
  t_hitbox		item;
  t_hitbox		*tmp;

  x = click->x;
  y = click->y;
  if (ground[x + y * grille->grille_x].decors != NULL)
    {
      tmp = ground[x + y * grille->grille_x].hitbox_decors;
      item = create_hitbox((int)(((float)(grille->coef *
				  (float)(grille->grille_y - y - 1))) * percent)
			   + tmp->x, tmp->y, tmp->width, tmp->height);
      if (in_hitbox(&item, click->mouse_pos) == 1)
	click->decors = ground[x + y * grille->grille_x].decors;
        click->pos.x = item.x < click->pos.x ? click->pos.x : item.x;
        click->pos.y = item.y;
    }
}


t_map_click		click_map(t_scene *scene, t_bunny_position *mouse_pos,
				  float percent)
{
  t_hitbox		place;
  t_grille		grille;
  t_map_click		click;

  click.mouse_pos = mouse_pos;
  click.npc = NULL;
  click.decors = NULL;
  place = create_hitbox(0, WIN_HEIGHT - scene->height,
			WIN_WIDTH, scene->height - 206 / 4);
  grille = get_grille_param(&place, scene);
  get_npc_clicked(scene->ground, &grille, &click, percent);
  if (click.x == -1)
    get_decors_clicked(scene->ground, &grille, &click, percent);
  else
    get_decors_wnpc(scene->ground, &grille, &click, percent);
  return (click);
}
