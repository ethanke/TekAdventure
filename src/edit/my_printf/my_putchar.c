/*
** my_putchar.c for my_putchar in /home/leandr_g/rendu/Piscine_C_J07/lib/my
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Tue Oct  6 10:35:20 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:00:51 2016 Gaëtan Léandre
*/

#include "main.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
