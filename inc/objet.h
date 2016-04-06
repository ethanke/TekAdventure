/*
** objet.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:35:23 2016 Ethan Kerdelhue
** Last update Wed Apr  6 23:44:33 2016 Ethan Kerdelhue
*/

#ifndef OBJET_H_
# define OBJET_H_

# include "main.h"

typedef struct 		s_objet
{
  int			id;
  char			*name;
  int			*damage;
  t_texture		*sprite;
}			t_objet;

#endif
