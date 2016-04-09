/*
** my_swap.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 14:43:29 2016 Victor Sousa
** Last update Sat Apr  9 14:55:14 2016 Victor Sousa
*/

#include		"main.h"

void			my_swap_item(t_item *a, t_item *b)
{
  int			tmp_id;
  int			tmp_amount;
  t_object		*tmp_obj;

  tmp_id = a->id;
  a->id = b->id;
  b->id = tmp_id;
  tmp_amount = a->amount;
  a->amount = b->amount;
  b->amount = tmp_amount;
  tmp_obj = a->object;
  a->object = b->object;
  b->object = tmp_obj;
}
