/*
** my_getnbr.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 03:03:18 2016 Ethan Kerdelhue
** Last update Sat Apr 16 23:12:14 2016 Gaëtan Léandre
*/

#include 	"main.h"

int			my_getnbr_free(char *str)
{
  int			nb;
  int			neg;
  int			i;

  nb = 0;
  neg = 1;
  i = 0;
  if (str == NULL)
    return (ERROR);
  while (str[i] && (str[i] == '+' || str[i] == '-'))
    if (str[i++] == '-')
	neg *= -1;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    nb = nb * 10 + (str[i++] - 48);
  free(str);
  return (nb * neg);
}
