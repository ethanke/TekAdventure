/*
** my_strcat.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 11 07:04:37 2016 Victor Sousa
** Last update Fri Apr 15 23:20:12 2016 Ethan Kerdelhue
*/

#include		"main.h"

char		*my_strcat(char *dest, char *src)
{
  int		len;
  int		i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
