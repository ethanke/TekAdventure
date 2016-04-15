/*
** parsing_error_msg_1.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Fri Apr 15 00:08:35 2016 Philippe Lefevre
*/

#include		"main.h"

t_scene			*my_puterror_scene(char *beg, char *name, char *mid,
					   int id, char *end)
{
  t_scene		*tmp;

  write(2, beg, my_strlen(beg));
  write(2, name, my_strlen(name));
  write(2, mid, my_strlen(mid));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_ground		*my_puterror_ground(char *beg, char *name, char *mid,
					    int id, char *end)
{
  t_ground		*tmp;

  write(2, beg, my_strlen(beg));
  write(2, name, my_strlen(name));
  write(2, mid, my_strlen(mid));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_sky			*my_puterror_sky(char *beg, char *name, char *mid,
					    int id, char *end)
{
  t_sky			*tmp;

  write(2, beg, my_strlen(beg));
  write(2, name, my_strlen(name));
  write(2, mid, my_strlen(mid));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_player		*my_puterror_player(char *beg, int id, char *end)
{
  t_player 		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}

t_object		*my_puterror_object(char *beg, int id, char *end)
{
  t_object 		*tmp;

  write(2, beg, my_strlen(beg));
  if (id > -1)
    my_put_nbr(2, id);
  write(2, end, my_strlen(end));
  tmp = NULL;
  return (tmp);
}
