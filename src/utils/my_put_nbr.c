/*
** my_put_nbr.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/my/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 17:32:38 2016 Philippe Lefevre
** Last update Wed Apr 13 18:35:07 2016 Philippe Lefevre
*/

#include		"main.h"

static int		my_char(int fd, char c)
{
  return (write(fd, &c, 1));
}

static int		my_puts(int fd, char *str)
{
  int			i;

  i = -1;
  while (str[++i])
    my_char(fd, str[i]);
  return (0);
}

int			my_put_nbr(int fd, int nb)
{
  if (nb == -2147483648)
    return (my_puts(fd, "-2147483648"));
  else if (nb < 0)
    nb *= -my_char(fd, '-');
  if (nb >= 10)
    my_put_nbr(fd, (nb / 10));
  return (my_char(fd, (nb % 10 + '0')));
}
