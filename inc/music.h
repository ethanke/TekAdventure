/*
** music.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 17 04:05:37 2016 Ethan Kerdelhue
** Last update Sun Apr 17 05:49:17 2016 Ethan Kerdelhue
*/

#ifndef			MUSIC_H_
# define		MUSIC_H_

#include		"main.h"

typedef struct 		s_music
{
  t_bunny_music		*fight;
  t_bunny_music		*menu;
  t_bunny_music		*game;
  t_bunny_music		*fight_sword;
  t_bunny_music		*fight_critic;
  t_bunny_music		*fight_resist;
  t_bunny_music		*fight_magic;
  t_bunny_music		*fight_dodge;
  t_bunny_music		*brouek;
  t_bunny_music		*player_win;
  int			volume;
}			t_music;

int			start_music(t_prog *prog);

#endif
