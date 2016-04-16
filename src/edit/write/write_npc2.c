/*
** write_npc2.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 19:17:26 2016 Gaëtan Léandre
** Last update Sat Apr 16 19:33:50 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_npc_sprite_hitbox_x(t_npc *npc, int fd,
						  int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_sprite_hitbox_x=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->texture_hitbox->x);
      else
	my_printf(fd, "\"%d\"\n", tmp->texture_hitbox->x);
      tmp = tmp->next;
      i++;
    }
}


void			write_npc_sprite_id(t_npc *npc, int fd,
					    int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_sprite_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->sprite_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->sprite_id);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_trade_given_amount(t_npc *npc, int fd,
						     int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_trade_given_amount=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->trade->given->amount);
      else
	my_printf(fd, "\"%d\"\n", tmp->trade->given->amount);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_trade_given_id(t_npc *npc, int fd,
						 int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_trade_given_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->trade->given->id);
      else
	my_printf(fd, "\"%d\"\n", tmp->trade->given->id);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_trade_needed_ammout(t_npc *npc, int fd,
						      int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_trade_needed_ammout=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->trade->needed->amount);
      else
	my_printf(fd, "\"%d\"\n", tmp->trade->needed->amount);
      tmp = tmp->next;
      i++;
    }
}
