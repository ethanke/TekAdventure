/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Wed Apr 13 11:33:35 2016 Ethan Kerdelhue
*/

#include		"main.h"

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

int 			npc_damage(t_npc *npc, t_player *player)
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
      my_putstr("It's critical !\n");
    }
  my_puts("Damage : ", damage / 1000, 1);
  return (damage / 1000);
}

int 			player_damage(t_player *player)
{
  int			damage;
  int			max;
  int			min;

  min = player->damage * 1200;
  max = player->damage * 800;
  damage = ((rand() % (max - min )) + min);
  if (((rand() % (100 - 0)) + 0) <= player->caract->critical)
    {
      damage = damage * 1.5;
      my_putstr("It's critical !\n");
    }
  if (((rand() % (100 - 0)) + 0) <= player->caract->agility / 3)
    {
        damage = 0;
        my_putstr("I'm dodge !\n");
    }
  my_puts("Damage : ", damage / 1000, 1);
  return (damage / 1000);
}

int			prepare_fight(t_prog *prog, t_npc *npc)
{
  if ((prog->fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  prog->life_bar = xmalloc(sizeof(t_bar), &prog->ptr_list);
  prog->npc_bar = xmalloc(sizeof(t_bar), &prog->ptr_list);
  prog->life_bar->bar_sprite = load_image("ressources/sprites/bar.png", &prog->ptr_list);
  prog->npc_bar->bar_sprite = load_image("ressources/sprites/bar.png", &prog->ptr_list);
  prog->fight->player = prog->player;
  prog->fight->npc = npc;
  prog->fight->npc->life = 100;
  prog->fight->nb_round = 1;
  prog->fight->round_state = 1;
  prog->fight_img = load_image("ressources/sprites/fight.jpg", &prog->ptr_list);
  prog->attack_button = load_image("ressources/sprites/ATTACK.png", &prog->ptr_list);
  prog->attack_button_hover = load_image("ressources/sprites/ATTACK_HOVER.png", &prog->ptr_list);
  prog->defend_button = load_image("ressources/sprites/DEFEND.png", &prog->ptr_list);
  prog->defend_button_hover = load_image("ressources/sprites/DEFEND_HOVER.png", &prog->ptr_list);
  prog->magic_button = load_image("ressources/sprites/MAGIC.png", &prog->ptr_list);
  prog->magic_button_hover = load_image("ressources/sprites/MAGIC_HOVER.png", &prog->ptr_list);
  prog->skip_button = load_image("ressources/sprites/SKIP.png", &prog->ptr_list);
  prog->skip_button_hover = load_image("ressources/sprites/SKIP_HOVER.png", &prog->ptr_list);
  prog->fight->player->caract = xmalloc(sizeof(t_caract), &prog->ptr_list);
  prog->fight->player->caract->strength = 5;
  prog->fight->player->caract->critical = 20;
  prog->fight->player->caract->agility = 30;
  prog->fight->player->damage = get_player_damage(prog->fight->player, prog);
  prog->fight->npc->damage = 20;
  prog->life_bar->value_cur = &prog->fight->player->life;
  prog->life_bar->value_default = prog->fight->player->life;
  prog->npc_bar->value_cur = &prog->fight->npc->life;
  prog->npc_bar->value_default = prog->fight->npc->life;
  return (0);
}

void			update_bar_npc(t_bar *bar, t_prog *prog)
{
  t_hitbox		rect;
  t_bunny_position	pos;
  t_font		font;

  rect.x = WIN_WIDTH - 20 - prog->npc_bar->bar_sprite->width;
  rect.y = 100;
  rect.width =  ((float)bar->bar_sprite->width / 100.0 * (float) *bar->value_cur);
  rect.height = bar->bar_sprite->height;
  fill_image(rect, prog->pix, BLUE);
  pos.y = 100 + bar->bar_sprite->height / 2 - 5;
  pos.x = (bar->bar_sprite->width / 2) + 675;
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = WHITE;
  tektext(my_itoa(*bar->value_cur), &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  tektext(my_itoa(bar->value_default), &pos, prog->pix, &font);
}

void			update_bar_player(t_bar *bar, t_prog *prog)
{
  t_hitbox		rect;
  t_bunny_position	pos;
  t_font		font;

  rect.x = 20;
  rect.y = 100;
  rect.width =  ((float)bar->bar_sprite->width / 100.0 * (float) *bar->value_cur);
  rect.height = bar->bar_sprite->height;
  fill_image(rect, prog->pix, RED);
  pos.y = 100 + bar->bar_sprite->height / 2 - 5;
  pos.x = (bar->bar_sprite->width / 2);
  font.font_img = prog->font->font_img;
  font.font_size = 14;
  font.font_color.full = WHITE;
  tektext(my_itoa(*bar->value_cur), &pos, prog->pix, &font);
  pos.x += 60;
  tektext(" / ", &pos, prog->pix, &font);
  pos.x += 60;
  tektext(my_itoa(bar->value_default), &pos, prog->pix, &font);
}

void			draw_fight(t_prog *prog)
{
  t_bunny_position	player_pos;
  t_bunny_position	attack;
  t_bunny_position	defend;
  t_bunny_position	magic;
  t_bunny_position	skip;
  t_bunny_position	bar1;
  t_bunny_position	bar2;

  sleep(2);
  player_pos.x = prog->fight->player->sprite->width / 2;
  player_pos.y = WIN_HEIGHT / 2 - (prog->fight->player->sprite->height / 2);
  skip.x = WIN_WIDTH / 2 + 1 * prog->attack_button->width;
  skip.y = 600;
  magic.x = WIN_WIDTH / 2 + 0 * prog->defend_button->width;
  magic.y = 600;
  defend.x = WIN_WIDTH / 2 - 1 * prog->defend_button->width;
  defend.y = 600;
  attack.x = WIN_WIDTH / 2 - 2 * prog->skip_button->width;
  attack.y = 600;
  bar1.x = 20;
  bar1.y = 100;
  bar2.x =  WIN_WIDTH - 20 - prog->npc_bar->bar_sprite->width;
  bar2.y = 100;
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  put_image(prog->player->sprite, prog->pix, &player_pos);
  put_image(prog->attack_button, prog->pix, &attack);
  put_image(prog->defend_button, prog->pix, &defend);
  put_image(prog->magic_button, prog->pix, &magic);
  put_image(prog->skip_button, prog->pix, &skip);
  put_image(prog->life_bar->bar_sprite, prog->pix, &bar1);
  put_image(prog->npc_bar->bar_sprite, prog->pix, &bar2);
  update_bar_player(prog->life_bar, prog);
  update_bar_npc(prog->npc_bar, prog);
}

int			loop_fight(t_prog *prog)
{
  draw_fight(prog);
  my_puts("Round -> ", prog->fight->nb_round, 1);
  if (prog->fight->round_state == 1)
    {
      prog->fight->npc->life -= player_damage(prog->fight->player);
      my_puts("Npc life : ", prog->fight->npc->life, 1);
      prog->fight->nb_round += 1;
      prog->fight->round_state = 2;
    }
  if (prog->fight->round_state == 2)
    {
      prog->fight->player->life -=
	  npc_damage(prog->fight->npc, prog->fight->player);
      my_puts("Player life : ", prog->fight->player->life, 1);
      prog->fight->round_state = 1;
    }
  if (prog->player->life <= 0)
    {
      my_puts("npc win\n", 0, 0);
      prog->need_init_fight = 0;
    }
  if  (prog->fight->npc->life <= 0)
    {
      my_puts("player win\n", 0, 0);
      prog->need_init_fight = 0;
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
