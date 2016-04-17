/*
** edit_npc.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 07:21:35 2016 Victor Sousa
** Last update Sun Apr 17 10:15:57 2016 Victor Sousa
*/

#include		"main.h"

static void		pick_what_to_edit_(t_ini *ini, t_npc *npc, int act)
{
  if (act == 3)
    {
      my_printf(1, "\nGive some text for your npc,\n");
      my_printf(1, "It will be displayed while");
      my_printf(1, " trading with him.\nYou can skip line using ';'\n");
      if ((npc->text = get_next_line(0)) == NULL)
	return;
    }
  if (act == 4)
    {
      my_printf(1, "\nWhat is your npc trading\nid : ");
      if ((npc->trade->given->id = get_npc_trade_id_given(ini)) == -1)
	return;
      my_printf(1, "amount : ");
      if ((npc->trade->given->amount = get_npc_trade_amount_given(ini)) == -1)
	return;
      my_printf(1, "\nWhat your npc require for trading\nid : ");
      if ((npc->trade->needed->id = get_npc_trade_id_given(ini)) == -1)
	return;
      my_printf(1, "amount : ");
      if ((npc->trade->needed->amount = get_npc_trade_amount_given(ini)) == -1)
	return;
    }
}

static void		pick_what_to_edit__(t_ini *ini, t_npc *npc, int act)
{
  if (act == 5)
    {
      my_printf(1, "\nChoose a sprite id for your object : ");
      npc->sprite_id = get_existing_sprite(ini);
      if ((npc->texture_hitbox = xmalloc(sizeof(t_hitbox),
					 &ini->ptr_list)) == NULL)
	return;
      my_printf(1, "\ntop left position in the sprite\nx : ");
      npc->texture_hitbox->x = get_x_pos_sprite(ini, npc->sprite_id);
      my_printf(1, "y : ");
      npc->texture_hitbox->y = get_y_pos_sprite(ini, npc->sprite_id);
      my_printf(1, "\nwidth in the sprite : ");
      npc->texture_hitbox->width = get_x_pos_sprite(ini, npc->sprite_id);
      my_printf(1, "height in the sprite : ");
      npc->texture_hitbox->height = get_y_pos_sprite(ini, npc->sprite_id);
    }
}

static void		pick_what_to_edit(t_ini *ini, t_npc *npc, int act)
{
  if (act == 1)
    {
      my_printf(1, "\nGive me a new id for your npc : ");
      npc->npc_id = get_npc_id(ini);
    }
  if (act == 2)
    {
      my_printf(1, "Give me a new name to your npc : ");
      if ((npc->name = get_obj_name(ini)) == NULL)
	return;
    }
  pick_what_to_edit_(ini, npc, act);
  pick_what_to_edit__(ini, npc, act);
}

static void		edit_cur_npc(t_ini *ini, t_npc *npc)
{
  char			*str;

  my_printf(1, "What do you want to edit?\n1: id\n2: name\n3: text\n");
  my_printf(1, "4: trade\n5: texture\n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "1") && my_strcmp(str, "2") && my_strcmp(str, "3") &&
	 my_strcmp(str, "4") && my_strcmp(str, "5"))
    {
      free(str);
      my_printf(1, "\nWrong input, choose between 1, 2, 3, 4, 5\n");
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  pick_what_to_edit(ini, npc, my_getnbr_free(str));
}

void			edit_npc(t_ini *ini, int id, char *str)
{
  my_printf(1, "\nWich one do you want to edit?\n");
  my_printf(1, "Select from and id : \n");
  if ((str = get_next_line(0)) == NULL)
    return;
  while ((id = my_getnbr(str)) - 1 <= -1 || npc_id_is_taken(ini, id) == 0)
    {
      my_printf(1, "No player found with this Id\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  my_printf(1, "Selected player is %s, are you sure\n",
	    look_for_npc_name(ini, id));
  if ((str = get_next_line(0)) == NULL)
    return;
  while (my_strcmp(str, "yes") != 0 && my_strcmp(str, "no") != 0)
    {
      my_printf(1, "yes or no\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return;
    }
  if (my_strcmp(str, "yes") == 0)
    edit_cur_npc(ini, look_for_npc(ini, id));
}
