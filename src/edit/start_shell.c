/*
** start_shell.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/edit/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:49:05 2016 Victor Sousa
** Last update Sat Apr 16 08:00:41 2016 Victor Sousa
*/

#include		"main.h"

void			put_prompt(void)
{
  my_printf(1, "tekadventure editor >> ");
}

void			treat_cmd(char **tab, t_ini *ini)
{
  int			len;

  (void)ini;
  len = my_tablen(tab);
  printf("len: %d", len);
}

void			start_shell()
{
  char			*cmd;
  char			**tab;
  t_ini			ini;

  put_prompt();
  while ((cmd = get_next_line(0)) != NULL)
    {
      tab = str_to_wordtab(cmd, " \t");
      treat_cmd(tab, &ini);
      free_tab(tab);
      free(cmd);
      put_prompt();
    }
}
