/*
** load_sprite.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 00:39:08 2016 Ethan Kerdelhue
** Last update Thu Apr  7 03:05:05 2016 Ethan Kerdelhue
*/

#include 	"main.h"

t_sprite	*create_sprite_node(char *path, int id, t_ptr_list *ptr_list)
{
  t_sprite	*sprite;

  if ((sprite = xmalloc(sizeof(t_sprite), &ptr_list)) == NULL)
      return (NULL);
  sprite->path = my_strdup(path, ptr_list);
  sprite->id = id;
  return (sprite);
}

t_list		*load_sprite(t_bunny_ini *ini, t_ptr_list *ptr_list)
{
  t_list	*list;
  char		*tmp;
  int		nb_sprite;
  int		i;

  i = 0;
  tmp = (char *)bunny_ini_get_field(ini, "count", "nb_sprite", 0);
  nb_sprite = my_getnbr(tmp);
  if (nb_sprite == 0)
    {
      my_puterror("Error : nb_sprite is null");
      return (NULL);
    }
  while (i != nb_sprite)
    {
      list = list_add_node(list,
			   (void *)create_sprite_node
			   ((char *)
			    bunny_ini_get_field(ini, "sprite", "path", i)
			    , i, ptr_list));
      i++;
    }
  free(tmp);
  return (list);
}
