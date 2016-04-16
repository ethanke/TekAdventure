/*
** free_shell.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 07:15:42 2016 Gaëtan Léandre
** Last update Sat Apr 16 07:16:56 2016 Gaëtan Léandre
*/

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  if (tab == NULL)
    return (NULL);
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
