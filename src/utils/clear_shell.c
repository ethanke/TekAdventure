/*
** clear_shell.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 23:58:15 2016 Victor Sousa
** Last update Sat Apr 16 23:59:45 2016 Victor Sousa
*/

#include		"main.h"

void    		clear_scr(void)
{
  my_printf(1, "\033[1;1H\033[2J");
}
