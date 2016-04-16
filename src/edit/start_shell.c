/*
** start_shell.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/edit/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 05:49:05 2016 Victor Sousa
** Last update Sat Apr 16 19:20:37 2016 Victor Sousa
*/

#include		"main.h"

void			put_prompt(void)
{
  my_printf(1, "tekadventure editor >> ");
}

int			treat_cmd(int ac, char **av, t_ini *ini)
{
  if (ac == 1 && my_strcmp(av[0], "exit") == 0)
    return (-1);
  if (ac == 3 && my_strcmp(av[0], "load") == 0
      && my_strcmp(av[1], "ini") == 0)
    {
      if (load_ini(av[2], ini) == -1)
	return (-1);
    }
  if (ac == 3 && my_strcmp(av[0], "write") == 0
      && my_strcmp(av[1], "ini") == 0)
    {
      if (write_ini(av[2], ini) == -1)
	return (-1);
    }
  if (ac == 2 && my_strcmp(av[0], "close") == 0
      && my_strcmp(av[1], "ini") == 0)
    close_ini(ini);
  if (ac >= 1 && my_strcmp(av[0], "aff") == 0)
    aff_stuff(ac, av, ini);
  if (ac >= 1 && my_strcmp(av[0], "add") == 0)
    add_stuff(ac, av, ini);
  return (0);
}

void			start_shell()
{
  char			*cmd;
  char			**tab;
  t_ini			ini;

  ini.has_been_loaded = 0;
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
