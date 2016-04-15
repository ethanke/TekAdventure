/*
** utils.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Apr  6 23:08:25 2016 victor sousa
** Last update Fri Apr 15 03:46:20 2016 Philippe Lefevre
*/

#ifndef                 UTILS_H_
# define                UTILS_H_

/* PTR LIST */
typedef	struct		s_ptr_list
{
  void			*ptr;
  struct s_ptr_list	*next;
}			t_ptr_list;
int			push_ptr(t_ptr_list **head, void *ptr);
void			free_ptr(t_ptr_list *ptr_list);

/* COMMON */
int			my_puterror(char *str);
int			my_strlen(char *str);
int			my_getnbr(char *str);
void                    *xmalloc(int size, t_ptr_list **ptr_list);
char			*my_strdup(char *str, t_ptr_list **ptr_list);
char			*my_strcpy(char *dest, char *src);
char			*my_strcat(char *dest, char *src);
char			*my_itoa(int nb);
int			my_put_nbr(int fd, int nb);
int			my_strcmp(char *s1, char *s2);

/* COMMON GRAPH */
void			my_draw_square(t_bunny_pixelarray *pix,
				       t_bunny_position *pos,
				       t_bunny_position *size,
				       unsigned int color);

#endif                  /* !UTILS_H_ */
