/*
** my_printf.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 12:27:44 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:00:13 2016 Gaëtan Léandre
*/

#include "main.h"

t_fonct	*init_struct(t_fonct *tab)
{
  tab = xmalloc(11 * sizeof(t_fonct));
  tab[0].flag = 'c';
  (tab[0].f) = va_my_putchar;
  tab[1].flag = 's';
  (tab[1].f) = va_my_putstr;
  tab[2].flag = 'i';
  (tab[2].f) = va_my_putnbr;
  tab[3].flag = 'd';
  (tab[3].f) = va_my_putnbr;
  tab[4].flag = 'u';
  (tab[4].f) = va_my_putunbr;
  tab[5].flag = 'o';
  (tab[5].f) = va_my_octal;
  tab[6].flag = 'x';
  (tab[6].f) = va_my_examin;
  tab[7].flag = 'X';
  (tab[7].f) = va_my_examaj;
  tab[8].flag = 'b';
  (tab[8].f) = va_my_bin;
  tab[9].flag = 'S';
  (tab[9].f) = va_my_disp_unp;
  tab[10].flag = 'p';
  (tab[10].f) = va_my_adress;
  return (tab);
}

int	chose_function(char c, t_fonct *tab)
{
  int	i;

  i = 0;
  while (i < 11)
    {
      if (c == tab[i].flag)
	return (i);
      i++;
    }
  if (c == '\0')
    return (-2);
  return (-1);
}

int	print_fct(va_list ap, t_fonct *tab, char *str, int i)
{
  int	fct;
  int	wait;

  wait = str[i] == ' ' ? 1 : 0;
  while (str[i] == ' ')
    i++;
  fct = chose_function(str[i], tab);
  if (fct == -1)
    {
      my_putchar('%');
      if (str[i] != '%')
	{
	  if (wait == 1)
	    my_putchar(' ');
	  my_putchar(str[i]);
	}
    }
  else if (fct > -1)
    {
      if (wait == 1)
	my_putchar(' ');
      tab[fct].f(ap);
    }
  return (i);
}

int	my_printf(char *str, ...)
{
  va_list	ap;
  t_fonct	*tab;
  int		i;

  tab = NULL;
  tab = init_struct(tab);
  i = 0;
  if (str == NULL || tab == NULL)
    return (-1);
  va_start(ap, str);
  while (i < my_strlen(str))
    {
      if (str[i] == '%')
	i = print_fct(ap, tab, str, i + 1);
      else if (str[i] == '#')
	i = my_put_color(str, i + 1);
      else
	my_putchar(str[i]);
      i++;
    }
  color(-1);
  va_end(ap);
  free(tab);
  return (0);
}
