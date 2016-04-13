/*
** parsing_error_msg_2.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 22:01:54 2016 Philippe Lefevre
*/

#include		"main.h"

t_trade			*my_puterror_trade(char *beg, int id, char *end)
{
  t_trade		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_item			*my_puterror_item(char *beg, int id, char *end)
{
  t_item		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}
