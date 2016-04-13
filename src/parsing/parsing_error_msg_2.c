/*
** parsing_error_msg_2.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 17:09:35 2016 Philippe Lefevre
*/

#include		"main.h"

t_sprite		*my_puterror_sprite(char *str)
{
  t_sprite		*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_npc			*my_puterror_npc(char *str)
{
  t_npc			*ret;

  write(2, str, my_strlen(str));
  ret = NULL;
  return (ret);
}

t_breakable		*my_puterror_breakable(char *str)
{
  t_breakable 		*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

t_decors		*my_puterror_decors(char *str)
{
  t_decors 	*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

t_hitbox		*my_puterror_hitbox(char *str)
{
  t_hitbox 	*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}
