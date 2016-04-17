/*
** get_decors_break.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 03:36:50 2016 Gaëtan Léandre
** Last update Sun Apr 17 06:47:02 2016 Victor Sousa
*/

#include		"main.h"

void			get_dec_break_info(t_ini *ini, t_decors *dec)
{
  dec->decors_breakable->life =
  get_id_posi("Life", "Give life to your decors : ", ini);
  dec->decors_breakable->breakable_by =
  get_object("Give item to break your decors : ", ini);
  if ((dec->decors_breakable->lootable =
       get_dec_collect("Is your decors lootable?  (yes or no) : ", ini))
      == -1)
    return;
  if (dec->decors_breakable->lootable == 0)
    {
      dec->decors_breakable->loot[0] = 0;
      dec->decors_breakable->loot[1] = 0;
    }
  else
    {
      dec->decors_breakable->loot[0] =
      get_object("What is your decors loot : ", ini);
      dec->decors_breakable->loot[1] =
      get_id_posi("Number", "How many : ", ini);
    }
}

void			fill_dec_break(t_ini *ini, t_decors *dec)
{
  if ((dec->decors_breakable->is_breakable =
       get_dec_collect("Is your decors breakable? (yes or no) : ", ini)) == -1)
    return;
  if (dec->decors_breakable->is_breakable == 0)
    {
      dec->decors_breakable->life = 0;
      dec->decors_breakable->breakable_by = 0;
      dec->decors_breakable->lootable = 0;
      dec->decors_breakable->loot[0] = 0;
      dec->decors_breakable->loot[1] = 0;
    }
  else
    get_dec_break_info(ini, dec);
}

int			get_dec_collect(char *msg, t_ini *ini)
{
  char			*str;

  (void)ini;
  my_printf(1, msg);
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n : ");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (my_strcmp(str, "yes") == 0)
    return (1);
  return (0);
}

int			get_object(char *msg, t_ini *ini)
{
  t_object		*tmp;
  char			*str;
  int			id;

  my_printf(1, msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr_free(str);
      tmp = ini->scene->object;
      while (tmp != NULL)
	{
	  if (tmp->object_id == id)
	    return (id);
	  tmp = tmp->next;
	}
      my_printf(1, "no item with that id\nTry again : ");
    }
  return (0);
}

int			get_id_posi(char *what, char *msg, t_ini *ini)
{
  char			*str;
  int			id;

  (void)ini;
  my_printf(1, msg);
  while ((str = get_next_line(0)) != NULL)
    {
      id = my_getnbr_free(str);
      if (id > 0)
	return (id);
      my_printf(1, "%s must be superior to 0\nTry again : ", what);
    }
  return (0);
}
