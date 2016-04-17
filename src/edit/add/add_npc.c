/*
** add_npc.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 03:43:36 2016 Victor Sousa
** Last update Sun Apr 17 10:07:56 2016 Victor Sousa
*/

#include		"main.h"

void			list_add_new_npc(t_scene *scene, t_npc *new)
{
  t_npc			*tmp;

  tmp = scene->npc;
  while (tmp && tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else
    scene->npc = new;
}

static void		last_choice(t_ini *ini, t_npc *npc)
{
  char			*str;

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
    {
      list_add_new_npc(ini->scene, npc);
      my_printf(1, "Object added in your ini file :D\nYou can write it using");
      my_printf(1, " 'write ini path_to_file.ini'\n\n");
    }
}

static void		recap(t_npc *npc)
{
  my_printf(1, "\n\nHere is your item\nid: %d\n", npc->npc_id);
  my_printf(1, "name: %s\n", npc->name);
  my_printf(1, "texte: %s\n", npc->text);
  my_printf(1, "require id: %d\n", npc->trade->needed->id);
  my_printf(1, "require amount: %d\n", npc->trade->needed->amount);
  my_printf(1, "given id: %d\n", npc->trade->given->id);
  my_printf(1, "given amount: %d\n", npc->trade->given->amount);
  my_printf(1, "sprite id: %d\n", npc->sprite_id);
  my_printf(1, "sprite pos x: %d\n", npc->texture_hitbox->x);
  my_printf(1, "sprite pos y: %d\n", npc->texture_hitbox->y);
  my_printf(1, "sprite width: %d\n", npc->texture_hitbox->width);
  my_printf(1, "sprite height: %d\n", npc->texture_hitbox->height);
  my_printf(1, "So do you want to add it in ini?  (yes or no)\n");
}

void			get_trade_and_hitbox(t_npc *npc, t_ini *ini)
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

void			add_npc(t_ini *ini)
{
  t_npc			*npc;

  if ((npc = xmalloc(sizeof(t_npc), &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\nGive an id to your npc : ");
  if ((npc->npc_id = get_npc_id(ini)) == -1)
    return;
  my_printf(1, "Give a name to your npc : ");
  if ((npc->name = get_obj_name(ini)) == NULL)
    return;
  my_printf(1, "\nGive some text for your npc,\n It will be displayed while");
  my_printf(1, " trading with him.\nYou can skip line using ';'\n");
  if ((npc->text = get_next_line(0)) == NULL)
    return;
  if ((npc->trade = xmalloc(sizeof(t_trade), &ini->ptr_list)) == NULL)
    return;
  if ((npc->trade->needed = xmalloc(sizeof(t_item), &ini->ptr_list)) == NULL)
    return;
  if ((npc->trade->given = xmalloc(sizeof(t_item), &ini->ptr_list)) == NULL)
    return;
  get_trade_and_hitbox(npc, ini);
  recap(npc);
  last_choice(ini, npc);
}
