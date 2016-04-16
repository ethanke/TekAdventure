/*
** start_shell.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/edit/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:49:05 2016 Victor Sousa
** Last update Sat Apr 16 07:20:25 2016 Gaëtan Léandre
*/

#include		"main.h"

void			start_shell()
{
  char			*cmd;
  char			**tab;

  while ((cmd = get_next_line(0)) != NULL)
    {
      tab = str_to_wordtab(cmd, " \t");

      free_tab(tab);
      free(cmd);
    }
}
