/*
** my_strcmp.c for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/my/src
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 17:36:47 2016 Philippe Lefevre
** Last update Mon Mar 28 17:38:01 2016 Philippe Lefevre
*/

int			my_strcmp(char *s1, char *s2)
{
  while (s1[0] != 0 && s2[0] != 0 && s1[0] == s2[0])
    {
      s1++;
      s2++;
    }
  return (s1[0] - s2[0]);
}
