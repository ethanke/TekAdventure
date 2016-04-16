/*
** str_to_wordtab.c for str_to_wordtab in /Users/leandr_g/Documents/Shared folder/PSU_2015_minishell2/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr  9 01:06:04 2016 Gaëtan Léandre
** Last update Sat Apr 16 19:46:13 2016 Ethan Kerdelhue
*/

#include		"main.h"

char		check(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    if (delim[i] == c)
      return (0);
  return (c);
}

int		countchars(char *str, char *delim)
{
  int		i;

  i = 0;
  while (check(str[i], delim))
    i++;
  return (i + 1);
}

int		countwords(char *str, char *delim)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
  {
    if (!check(str[i], delim))
      {
	count++;
	while (str[i] && !check(str[i], delim))
	  i++;
      }
      if (str[i])
        i++;
   }
   return (count + 1);
}

char		**str_to_wordtab(char *str, char *delim)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  j = -1;
  if ((tab = malloc(countwords(str, delim) * sizeof(char *))) == NULL)
      return (NULL);
  while (str[i] && !check(str[i], delim))
    i++;
  while (str[i])
    {
      if ((tab[++j] = malloc(countchars(&str[i], delim))) == NULL)
	  return (NULL);
      k = -1;
      while (check(str[i], delim))
	tab[j][++k] = str[i++];
      tab[j][++k] = 0;
      while (str[i] && !check(str[i], delim))
	i++;
    }
  tab[++j] = NULL;
  return (tab);
}
