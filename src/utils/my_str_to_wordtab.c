/*
** my_str_to_wordtab.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/my/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 18:38:18 2016 Philippe Lefevre
** Last update Wed Apr 13 08:42:30 2016 Philippe Lefevre
*/

#include		<stdlib.h>

static int		is_separator(char c, char *separator)
{
  int			i;

  i = -1;
  while (separator[++i])
    {
      if (c == separator[i])
	return (1);
    }
  return (0);
}

static int		count_word(char *str, char *separator)
{
  int			i;
  int			n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if ((str[i]) && !(is_separator(str[i], separator)))
	n++;
      i++;
    }
  return (n);
}

int			my_tablen(char **str)
{
  int			i;

  i = -1;
  while (str[++i]);
  return (i);
}

int			my_free_wordtab(char **str)
{
  int			i;

  i = -1;
  while (str[++i])
    free(str[i]);
  free(str);
  return (0);
}

char			**my_str_to_wordtab(char *str, char *separator)
{
  char			**tab;
  int			i;
  int			j;
  int			cur_tab;
  int			word;

  i = 0;
  cur_tab = 0;
  word = count_word(str, separator);
  if ((tab = malloc(8 * (word + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] && (is_separator(str[i], separator)))
	i++;
      j = i;
      while (str[i] && (!(is_separator(str[i], separator))))
	i++;
      if ((tab[cur_tab] = malloc(i - j + 1)) == NULL)
      	return (NULL);
      tab[cur_tab] = my_strncpy(tab[cur_tab], (str + j), (i - j));
      cur_tab++;
    }
  tab[cur_tab] = NULL;
  return (tab);
}
