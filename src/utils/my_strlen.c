/*
** my_strlen.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 03:06:14 2016 Ethan Kerdelhue
** Last update Thu Apr  7 03:06:55 2016 Ethan Kerdelhue
*/

#include 		"main.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
      i++;
  return (i);
}
