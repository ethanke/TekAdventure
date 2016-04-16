/*
** my_printf1.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf/bonus
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 19:27:27 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:00:21 2016 Gaëtan Léandre
*/

#include "main.h"

void	color(int i)
{
  int	result;

  if (i < 0 || i > 7)
    result = 0;
  else
    result = 30 + i;
  my_putstr("\033[");
  my_put_nbr(result);
  my_putchar('m');
}

int	my_put_color(char *str, int i)
{
  if (str[i] >= '0' && str[i] <= '7')
    color(str[i] - 48);
  else
    {
      color(-1);
      i--;
    }
  return (i);
}
