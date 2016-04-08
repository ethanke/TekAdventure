/*
** load_sprite.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 00:39:08 2016 Ethan Kerdelhue
** Last update Fri Apr  8 00:47:58 2016 Ethan Kerdelhue
*/

#include 	"main.h"

t_sprite		*create_sprite_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_sprite		*sprite;
  char			*str;

  if ((sprite = xmalloc(sizeof(t_sprite), ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "path", id)) == NULL)
    return (NULL);
  if ((sprite->path = my_strdup(str, ptr_list)) == NULL)
    return (NULL);
  sprite->id = id;
  sprite->next = NULL;
  sprite->prev = NULL;
  return (sprite);
}

t_sprite		*list_add_sprite(t_sprite *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_sprite		*new;
  t_sprite		*tmp;

  if ((new = create_sprite_node(id, ini, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_sprite	*list;
  int		nb_sprite;
  int		i;

  i = 0;
  list = NULL;
  nb_sprite =
      my_getnbr((char *)bunny_ini_get_field(ini, "count", "sprite_count", 0));
  if (nb_sprite == 0)
    {
      my_puterror("Error : nb_sprite is null");
      return (NULL);
    }
  while (i != nb_sprite)
    {
      list = list_add_sprite(list, i, ini, ptr_list);
      i++;
    }
  return (list);
}
