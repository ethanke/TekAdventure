/*
** load_sprite.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 00:39:08 2016 Ethan Kerdelhue
** Last update Thu Apr  7 01:19:12 2016 Ethan Kerdelhue
*/

#include 	"main.h"

char		*my_strdup(char *str, t_ptr_list *ptr_list)
{
  int		i;
  char		*new;

  i = 0;
  new = xmalloc(my_strlen(str), ptr_list);
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}

t_sprite	*create_sprite_node(char *path, int id, t_ptr_list *ptr_list)
{
  t_sprite	*sprite;

  sprite = xmalloc(sizeof(t_sprite), ptr_list);
  sprite->path = my_strdup(path);
  sprite->id = id;
}

t_sprite	*load_sprite(t_bunny_ini *ini, t_ptr_list *ptr_list)
{
  t_list	*list;
  int		nb_sprite;
  int		i;

  i = 0;
  nb_sprite = my_getnbr(bunny_ini_get_field(ini, "count", "nb_sprite", 0));
  if (nb_sprite == 0)
    {
      my_puterror("Error : nb_sprite is null");
      return (NULL);
    }
  while (i != nb_sprite)
    {
      list = list_add_node(list,
			   (void *)create_sprite_node
			   (bunny_ini_get_field(ini, "sprite", "path", i), i));
      i++;
    }
}
