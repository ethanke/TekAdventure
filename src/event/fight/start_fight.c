/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Sat Apr 16 00:10:31 2016 Gaëtan Léandre
*/

#include	"main.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_putnbr(int nb)
{
  int	mod;

  mod = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  my_putnbr(nb);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
  return (0);
}


int			my_puts(char *str, int nb, int flag)
{
  my_putstr(str);
  my_putnbr(nb);
  if (flag == 1)
    my_putchar('\n');
  return (0);
}

int			get_life_player(t_player *player)
{
  int			life_player;

  life_player = player->caract->stamina * 10 + 100;
  return (life_player);
}

int			get_player_magic_damage(t_player *player, t_prog *prog)
{
  int			player_magic_damage;

  player_magic_damage = prog->scene->object->damage *
      (1 + player->caract->intellect / 10);
  return (player_magic_damage);
}

int			get_player_damage(t_player *player, t_prog *prog)
{
  int			player_damage;

  (void) prog;
  player_damage = 20 *
      (1 + player->caract->strength / 10);
  return (player_damage);
}

int 			npc_damage(t_npc *npc, t_player *player, t_prog *prog)
{
  int			damage;
  int			max;
  int			min;

  max = npc->damage * 1200;
  min = npc->damage * 800;
  damage = ((rand() % (max - min)) + min);
  if (((rand() % (100 - 0)) + 0) <= 5)
    {
      damage = damage * 1.5;
      event_on_player(prog, 0);
    }
  if (((rand() % (100 - 0)) + 0) <= player->caract->agility / 3)
    {
      damage = 0;
      event_on_player(prog, 1);
    }
  if (player->fight_defense == 1)
    {
      player->fight_defense = 0;
      if (((rand() % (100 - 0)) + 0) <= player->caract->armor / 3)
	{
	  event_on_player(prog, 2);
	  damage = 0;
	}
      else
	{
	  damage = (damage / 1000) - player->caract->armor / 5;
	  event_on_player(prog, 3);
	  return (damage_on_player(prog, damage));
	}
    }
  return (damage_on_player(prog, damage / 1000));
}

int 			player_damage_magic(t_player *player, t_fight *fight, t_prog *prog)
{
  t_bunny_position	pos;
  int			damage;
  int			max;
  int			min;

  if (fight->player_action >= ATTACK_ENERGY)
    {
      min = player->magic_damage * 1200;
      max = player->magic_damage * 800;
      damage = ((rand() % (max - min )) + min);
      if (((rand() % (100 - 0)) + 0) <= player->caract->critical)
	{
	  damage = damage * 1.5;
	  event_on_npc(prog);
	}
      pos.x = WIN_WIDTH / 2;
      pos.y = WIN_HEIGHT / 2;
      pos = pos;
      fight->player_action -= MAGIC_ENERGY;
      return (damage_on_npc(prog, damage / 1000));
    }
  return (0);
}

int 			player_damage(t_player *player, t_fight *fight, t_prog *prog)
{
  int			damage;
  int			max;
  int			min;

  if (fight->player_action >= ATTACK_ENERGY)
    {
      min = player->damage * 1200;
      max = player->damage * 800;
      damage = ((rand() % (max - min )) + min);
      if (((rand() % (100 - 0)) + 0) <= player->caract->critical)
	{
	  damage = damage * 1.5;
	  event_on_npc(prog);
	}
      fight->player_action -= ATTACK_ENERGY;
      return (damage_on_npc(prog, damage / 1000));
    }
  return (0);
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
  prog->fight->npc->life = 100;
  prog->fight->nb_round = 1;
  prog->fight->round_state = 1;
  prog->fight->player->caract = xmalloc(sizeof(t_caract), &prog->ptr_list);
  prog->fight->player->caract->strength = 5;
  prog->fight->player->caract->critical = 20;
  prog->fight->player->caract->agility = 30;
  prog->fight->player->caract->armor = 50;
  prog->fight->player->caract->intellect = 8;
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
