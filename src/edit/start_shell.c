/*
** start_shell.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/edit/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:49:05 2016 Victor Sousa
** Last update Sat Apr 16 08:08:25 2016 Victor Sousa
*/

#include		"main.h"

void			put_prompt(void)
{
  my_printf(1, "tekadventure editor >> ");
}

int			treat_cmd(int ac, char **av, t_ini *ini)
{
  (void)ini;
  if (ac == 3 && my_strcmp(av[0], "load") == 0 && my_strcmp(av[1], "ini") == 0)
    {
      if (load_ini(av[2], ini) == -1)
	return (-1);
      my_printf(1, "player name: %s", ini->player->name);
    }
  return (0);
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
      if (treat_cmd(my_tablen(tab), tab, &ini) == -1)
	return;
      free_tab(tab);
      free(cmd);
      put_prompt();
    }
}
