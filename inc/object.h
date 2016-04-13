/*
** object.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:35:23 2016 Ethan Kerdelhue
** Last update Wed Apr 13 01:28:56 2016 Ethan Kerdelhue
*/

#ifndef 		OBJECT_H_
# define 		OBJECT_H_

# include		"main.h"
# include		"image.h"

typedef struct 		s_object
{
  int			object_id;
  char			*name;
  unsigned int		damage;
  struct s_caract	*caract;
  int			sprite_id;
  t_texture		*texture;
  t_hitbox		*texture_hitbox;
  struct s_object	*prev;
  struct s_object	*next;
}			t_object;

t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list);

#endif			/* !OBJECT_H_ */
