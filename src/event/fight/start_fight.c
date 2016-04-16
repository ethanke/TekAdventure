/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Sat Apr 16 08:00:15 2016 Ethan Kerdelhue
*/

#include	"main.h"

int			get_player_magic_damage(t_player *player, t_prog *prog)
{
  int			player_magic_damage;

  (void)prog;
  player_magic_damage = 5 + (1 + player->caract->intellect / 2);
  return (player_magic_damage);
}

int			get_player_damage(t_player *player, t_prog *prog)
{
  int			player_damage;

  (void)prog;
  player_damage = 5 + (1 + player->caract->strength / 2);
  return (player_damage);
}

int			prepare_fight(t_prog *prog, t_npc *npc)
{
  if ((prog->fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  prog->fight->bar_action = xmalloc(sizeof(t_bar), &prog->ptr_list);
  prog->fight->bar_action->bar_sprite = load_image("ressources/sprites/bar.png", &prog->ptr_list);
  prog->fight->bar_npc = xmalloc(sizeof(t_bar), &prog->ptr_list);
  prog->fight->bar_npc->bar_sprite = load_image("ressources/sprites/bar.png", &prog->ptr_list);
  prog->fight->bar_player = xmalloc(sizeof(t_bar), &prog->ptr_list);
  prog->fight->bar_player->bar_sprite = load_image("ressources/sprites/bar.png", &prog->ptr_list);
  prog->fight->animate = 0;
  prog->fight->last_action = -1;
  prog->fight->font.font_img = prog->font->font_img;
  prog->fight->font.font_size = 14;
  prog->fight->font.font_color.full = WHITE;
  prog->fight->fireball = load_image("ressources/sprites/fireballsprite.png", &prog->ptr_list);
  prog->fight->player = prog->player;
  prog->fight->npc = npc;
  prog->fight->player_action = 100;
  prog->fight->bonus_action = 0;
  prog->fight->npc->life = 100;
  prog->fight->nb_round = 1;
  prog->fight->round_state = 1;
  prog->fight->round_energy = ROUND_ENERGY;
  prog->fight->player->damage = get_player_damage(prog->fight->player, prog);
  prog->fight->player->magic_damage = get_player_magic_damage(prog->fight->player, prog);
  prog->fight->player->fight_defense = 0;
  prog->fight->npc->damage = 20;
  prog->fight->pos.x = 0;
  prog->fight->pos.y = WIN_HEIGHT / 2;
  prog->fight->pos.height = prog->fight->fireball->height;
  prog->fight->pos.width = 83;
  prog->fight->fetch.x = 0;
  prog->fight->fetch.y = 0;
  prog->fight->fetch.height = prog->fight->fireball->height;
  prog->fight->fetch.width = 83;
  prog->fight->bar_action->value_cur = prog->fight->player_action;
  prog->fight->bar_action->value_default = prog->fight->player_action;
  prog->fight->bar_npc->value_cur = prog->fight->npc->life;
  prog->fight->bar_npc->value_default = prog->fight->npc->life;
  prog->fight->bar_player->value_cur = prog->fight->player->life;
  prog->fight->bar_player->value_default = prog->fight->player->life;
  return (0);
}

int			anime_fireball(t_prog *prog)
{
  if (prog->fight->fetch.x < prog->fight->fireball->width + 83)
    {
      prog->fight->fetch.x += 80;
      place_image(prog->fight->pos, prog->fight->fetch, prog->fight->fireball, prog->pix);
      return (1);
    }
  else
    {
      prog->fight->fetch.x = 0;
      return (1);
    }
  return (0);
}

int			start_fight(t_prog *prog, t_npc *npc)
{
  if (prog->need_init_fight == 1)
    {
      if (prepare_fight(prog, npc) == -1)
	return (-1);
      prog->need_init_fight = 0;
    }
  loop_fight(prog);
  return (0);
}
