/*
** back.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:35:23 2016 Ethan Kerdelhue
** Last update Thu Apr  7 03:09:39 2016 Gaëtan Léandre
*/

#ifndef 		BACK_H_
# define 		BACK_H_

# include "main.h"

typedef struct 		s_back
{
  int			dist;
  t_texture		*sprite;
  struct s_back		*next;
  struct s_back		*prev;
}			t_back;

#endif			/* !BACK_H_ */
