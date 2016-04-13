/*
** parsing_error_msg_1.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 08:47:20 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*my_puterror_scene(char *str)
{
  t_scene		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_ground		*my_puterror_ground(char *str)
{
  t_ground		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_sky			*my_puterror_sky(char *str)
{
  t_sky 		*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

t_player		*my_puterror_player(char *str)
{
  t_player 		*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

t_object		*my_puterror_object(char *str)
{
  t_object 		*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}
