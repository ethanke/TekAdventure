/*
** object.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:35:23 2016 Ethan Kerdelhue
** Last update Thu Apr  7 00:37:55 2016 Philippe Lefevre
*/

#ifndef 		OBJECT_H_
# define 		OBJECT_H_

# include "main.h"

typedef struct 		s_object
{
  int			id;
  char			*name;
  int			*damage;
  t_texture		*sprite;
}			t_object;

#endif			/* !OBJECT_H_ */
