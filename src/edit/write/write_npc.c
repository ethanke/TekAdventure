/*
** write_npc.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 19:02:15 2016 Gaëtan Léandre
** Last update Sat Apr 16 19:35:32 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_npc_trade_needed_id(t_npc *npc, int fd, int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_trade_needed_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->trade->needed->id);
      else
	my_printf(fd, "\"%d\"\n", tmp->trade->needed->id);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_text(t_npc *npc, int fd, int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_text=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", tmp->text);
      else
	my_printf(fd, "\"%s\"\n", tmp->text);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_name(t_npc *npc, int fd, int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_name=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", tmp->name);
      else
	my_printf(fd, "\"%s\"\n", tmp->name);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc_id(t_npc *npc, int fd, int size)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  my_printf(fd, "npc_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->npc_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->npc_id);
      tmp = tmp->next;
      i++;
    }
}

void			write_npc(t_npc *npc, int fd)
{
  t_npc			*tmp;
  int			i;

  i = 0;
  tmp = npc;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "[npc]\nnpc_count=\"%d\"\n", i);
  write_npc_id(npc, fd, i);
  write_npc_name(npc, fd, i);
  write_npc_text(npc, fd, i);
  write_npc_trade_needed_id(npc, fd, i);
  write_npc_trade_needed_ammout(npc, fd, i);
  write_npc_trade_given_id(npc, fd, i);
  write_npc_trade_given_amount(npc, fd, i);
  write_npc_sprite_id(npc, fd, i);
  write_npc_sprite_hitbox_x(npc, fd, i);
  write_npc_sprite_hitbox_y(npc, fd, i);
  write_npc_sprite_hitbox_w(npc, fd, i);
  write_npc_sprite_hitbox_h(npc, fd, i);
  my_printf(fd, "\n\n");
}
