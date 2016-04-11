/*
** my_itoa.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 11 07:57:01 2016 Victor Sousa
** Last update Mon Apr 11 07:58:12 2016 Victor Sousa
*/

#include	"main.h"

char		*my_itoa(int nb)
{
  int		len;
  char		*str;
  int		tmp;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (0);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
