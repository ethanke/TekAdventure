/*
** my_printf2.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:51:48 2015 Gaëtan Léandre
** Last update Mon Mar  7 03:25:14 2016 Victor Sousa
*/

#include "corewar.h"

void	va_my_putchar(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	va_my_putstr(va_list ap)
{
  my_putstr(va_arg(ap, char*));
}

void	va_my_putnbr(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	va_my_putunbr(va_list ap)
{
  my_put_unbr(va_arg(ap, unsigned int));
}

void	va_my_disp_unp(va_list ap)
{
  disp_unprintable(va_arg(ap, char*));
}
