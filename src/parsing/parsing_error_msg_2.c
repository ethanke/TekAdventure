/*
** parsing_error_msg_2.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 22:01:40 2016 Philippe Lefevre
*/

#include		"main.h"

t_sprite		*my_puterror_sprite(char *beg, int id, char *end)
{
  t_sprite		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_npc			*my_puterror_npc(char *beg, int id, char *end)
{
  t_npc			*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_breakable		*my_puterror_breakable(char *beg, int id, char *end)
{
  t_breakable 		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_decors		*my_puterror_decors(char *beg, int id, char *end)
{
  t_decors	 	*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_hitbox		*my_puterror_hitbox(char *beg, int id, char *end)
{
  t_hitbox 		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}
