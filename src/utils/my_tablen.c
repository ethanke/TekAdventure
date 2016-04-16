/*
** my_tablen.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 07:59:07 2016 Victor Sousa
** Last update Sat Apr 16 07:59:32 2016 Victor Sousa
*/

#include		"main.h"

int			my_tablen(char **tab)
{
  int			i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
