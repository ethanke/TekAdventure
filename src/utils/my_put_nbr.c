/*
** my_put_nbr.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/my/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 17:32:38 2016 Philippe Lefevre
** Last update Wed Apr 13 10:35:17 2016 Philippe Lefevre
*/

#include		"main.h"

int			my_puterror_nbr(int nb)
{
  if (nb == -2147483648)
    return (my_putstr(fd, "-2147483648"));
  else if (nb < 0)
    nb *= -my_putchar(fd, '-');
  if (nb >= 10)
    my_put_nbr(fd, (nb / 10));
  return (my_putchar(fd, (nb % 10 + '0')));
}
