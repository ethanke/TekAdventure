/*
** my_putchar.c for my_putchar in /home/leandr_g/rendu/Piscine_C_J07/lib/my
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Tue Oct  6 10:35:20 2015 Gaëtan Léandre
** Last update Mon Mar  7 03:25:54 2016 Victor Sousa
*/

#include "corewar.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
