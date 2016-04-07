/*
** my_puterror.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 01:18:01 2016 Ethan Kerdelhue
** Last update Thu Apr  7 01:18:33 2016 Ethan Kerdelhue
*/

#include 	"main.h"

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
