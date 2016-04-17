/*
** add_scene_utils.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 10:37:50 2016 Gaëtan Léandre
** Last update Sun Apr 17 10:38:46 2016 Gaëtan Léandre
*/

#include		"main.h"

int			get_major_2(char *msg, t_ini *ini, int max)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, "Enter %s : ", msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr(str);
      free(str);
      if (id >= 0 && id < max)
	return (id);
      my_printf(1, "%s must be between 0 and %d\nTry again : ", msg, max - 1);
    }
  return (8);
}

int			get_major(char *msg, t_ini *ini)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, "Enter %s : ", msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr(str);
      free(str);
      if (id > 0)
	return (id);
      my_printf(1, "%s must be superior to 0\nTry again : ", msg);
    }
  return (8);
}

void			init_gound(t_scene *scene)
{
  int			i;
  int			max;

  max = scene->size.x * scene->size.y;
  i = 0;
  while (i < max)
    {
      scene->ground[i].npc = NULL;
      scene->ground[i].decors = NULL;
      scene->ground[i].gate = NULL;
      i++;
    }
}

int			scene_name_is_taken(t_ini *ini, char *str)
{
  t_scene		*tmp;

  tmp = ini->scene;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*get_sce_name(t_ini *ini)
{
  char			*str;

  my_printf(1, "Enter scene name : ");
  while ((str = get_next_line(0)) != NULL)
    {
      if (scene_name_is_taken(ini, str) == 0)
	return (str);
      my_printf(1, "Name already taken by another scene\nTry again : ");
      free(str);
    }
  return (str);
}
