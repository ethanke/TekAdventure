/*
** free_shell.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 07:15:42 2016 Gaëtan Léandre
** Last update Sat Apr 16 07:33:35 2016 Gaëtan Léandre
*/

#include		"main.h"

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  if (tab == NULL)
    return;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
