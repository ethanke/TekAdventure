/*
** click_map.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 12 03:55:39 2016 Gaëtan Léandre
** Last update Wed Apr 13 22:22:46 2016 Gaëtan Léandre
*/

#include		"main.h"

int			in_hitbox(t_hitbox *hitbox, t_bunny_position *pos)
{
  if (pos->x > hitbox->x && pos->x < hitbox->x + hitbox->width
      && pos->y > hitbox->y && pos->y < hitbox->y + hitbox->height)
    return (1);
  return (0);
}

void			get_npc_clicked(t_ground *ground, t_grille *grille,
					t_map_click *click, float percent)
{
  t_bunny_position	pos;
  t_hitbox		item;
  t_hitbox		*tmp;

  pos.y = grille->grille_y - 1;
  while (--pos.y >= 0)
    {
      pos.x = -1;
      while (++pos.x < grille->grille_x)
	{
	  if (ground[pos.x + pos.y * grille->grille_x].npc != NULL)
	    {
	      tmp = ground[pos.x + pos.y * grille->grille_x].hitbox_npc;
	      item = create_hitbox(calc_x_h(grille, &pos, percent, tmp->x),
				   tmp->y, tmp->width, tmp->height);
	      if (in_hitbox(&item, click->mouse_pos) == 1)
		{
		  click->x = pos.x;
		  click->y = pos.y;
		  click->pos.x = item.x;
		  click->pos.y = item.y;
		  click->npc = ground[pos.x + pos.y * grille->grille_x].npc;
		  return;
		}
	    }
	}
    }
}

void			get_decors_clicked(t_ground *ground, t_grille *gril,
					   t_map_click *click, float percent)
{
  t_bunny_position	pos;
  t_hitbox		item;
  t_hitbox		*tmp;

  pos.y = gril->grille_y - 1;
  while (--pos.y >= 0)
    {
      pos.x = -1;
      while (++pos.x < gril->grille_x)
	{
	  if (ground[pos.x + pos.y * gril->grille_x].decors != NULL)
	    {
	      tmp = ground[pos.x + pos.y * gril->grille_x].hitbox_decors;
              item = create_hitbox(calc_x_h(gril, &pos, percent, tmp->x),
				   tmp->y, tmp->width, tmp->height);
	      if (in_hitbox(&item, click->mouse_pos) == 1)
		{
		  click->x = pos.x;
		  click->y = pos.y;
                  click->pos.x = item.x;
                  click->pos.y = item.y;
		  click->decors = ground[pos.x + pos.y * gril->grille_x].decors;
		  return;
		}
	    }
	}
    }
}

void			get_decors_wnpc(t_ground *ground, t_grille *grille,
					t_map_click *click, float percent)
{
  t_bunny_position	pos;
  t_hitbox		item;
  t_hitbox		*tmp;

  pos.x = click->x;
  pos.y = click->y;
  if (ground[pos.x + pos.y * grille->grille_x].decors != NULL)
    {
      tmp = ground[pos.x + pos.y * grille->grille_x].hitbox_decors;
      item = create_hitbox(calc_x_h(grille, &pos, percent, tmp->x),
                           tmp->y, tmp->width, tmp->height);
      if (in_hitbox(&item, click->mouse_pos) == 1)
	click->decors = ground[pos.x + pos.y * grille->grille_x].decors;
        click->pos.x = item.x < click->pos.x ? click->pos.x : item.x;
        click->pos.y = item.y;
    }
}


t_map_click		click_map(t_prog *prog, t_bunny_position *mouse_pos,
				  float percent)
{
  t_grille		grille;
  t_map_click		click;
  t_scene		*scene;

  scene = prog->scene;
  click.x = -1;
  click.y = -1;
  click.mouse_pos = mouse_pos;
  click.npc = NULL;
  click.decors = NULL;
  grille = get_grille_with_place(scene);
  get_npc_clicked(scene->ground, &grille, &click, percent);
  if (click.x == -1)
    get_decors_clicked(scene->ground, &grille, &click, percent);
  else
    get_decors_wnpc(scene->ground, &grille, &click, percent);
  if (is_near((int)prog->player->x, (int)prog->player->y,
	      click.x, click.y) != 1)
    {
      click.x = -1;
      click.y = -1;
      click.npc = NULL;
      click.decors = NULL;
    }
  return (click);
}
