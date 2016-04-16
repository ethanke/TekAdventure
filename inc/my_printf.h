/*
** my_printf.h for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 14:36:04 2015 Gaëtan Léandre
** Last update Mon Mar 14 14:33:33 2016 Victor Sousa
*/

#ifndef		MY_PRINTF_H_
# define 	MY_PRINTF_H_

# include	<stdlib.h>
# include	<stdarg.h>

typedef struct	s_fonct
{
  char		flag;
  void		(*f)(va_list ap);
}		t_fonct;

int		my_printf(char *str, ...);
t_fonct		*init_struct(t_fonct *tab);
void		color(int i);
int		chose_function(char c, t_fonct *tab);
int		print_fct(va_list ap, t_fonct *tab, char *str, int i);
int		my_put_color(char *str, int i);

void		va_my_putchar(va_list ap);
void		va_my_putstr(va_list ap);
void		va_my_putnbr(va_list ap);
void		va_my_putunbr(va_list ap);
void		va_my_disp_unp(va_list ap);
void		va_my_examaj(va_list ap);
void		va_my_examin(va_list ap);
void		va_my_octal(va_list ap);
void		va_my_bin(va_list ap);
void		va_my_adress(va_list ap);

void		my_putstr(char *str);

void		my_putchar(char c);

void		my_put_nbr(int nbr);
void		display_numbers(int nbr);
int		positif(int nbr, int test);

void		my_put_unbr(unsigned int nbr);

void		disp_unprintable(char *str);

int		my_strlen(char *str);
void		my_putnbr_base(int nbr, char *base, int taille);
int		big_pow(int nbr, int base_size);
int		power(int nbr, int pow);

void		my_putnbr_base_u(unsigned int nbr, char *base);
int		big_pow_u(unsigned int nbr, int base_size);
unsigned int	power_u(unsigned int nbr, int pow);

void		my_putnbr_base_add(size_t nbr, char *base, int taille);
int		big_pow_add(size_t nbr, int base_size);
size_t		power_add(size_t nbr, int pow);

#endif	      /*MY_PRINTF_H_*/
