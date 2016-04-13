/*
** parsing_error_msg_2.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 17:08:10 2016 Philippe Lefevre
*/

#include		"main.h"

t_trade			*my_puterror_trade(char *str)
{
  t_trade		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_item			*my_puterror_item(char *str)
{
  t_item		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}
