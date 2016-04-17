/*
** add_sprite.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 02:54:03 2016 Victor Sousa
** Last update Sun Apr 17 07:43:04 2016 Victor Sousa
*/

#include		"main.h"

void			list_add_new_sprite(t_scene *scene, t_sprite *new)
{
  t_sprite		*tmp;

  tmp = scene->sprite;
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else
    scene->sprite = new;
}

static void		final_choice(t_sprite *spr, t_ini *ini)
{
  char			*str;

  my_printf(1, "\n\nHere is your item\nid: %d\n", spr->id);
  my_printf(1, "path: %s\n", spr->path);
  my_printf(1, "So do you want to add it in ini?  (yes or no)\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  if (my_strcmp(str, "yes") == 0)
    {
      list_add_new_sprite(ini->scene, spr);
      my_printf(1, "Sprite added in your ini file :D\nYou can write it using");
      my_printf(1, " 'write ini path_to_file.ini'\n\n");
    }
}

void			add_sprite(t_ini *ini)
{
  t_sprite		*spr;

  if ((spr = xmalloc(sizeof(t_sprite), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\nGive an id to your sprite : ");
  if ((spr->id = get_sprite_id(ini)) == -1)
    return;
  my_printf(1, "Give me the path to your sprite : ");
  if ((spr->path = get_sprite_path(ini)) == NULL)
    return;
 final_choice(spr, ini);
}
