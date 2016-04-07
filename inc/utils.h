/*
** utils.h for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Wed Apr  6 23:08:25 2016 victor sousa
** Last update Thu Apr  7 02:11:00 2016 victor sousa
*/

#ifndef                 UTILS_H_
# define                UTILS_H_

# include		"main.h"

/* PTR LIST */
typedef	struct		s_ptr_list
{
  void			*ptr;
  struct s_ptr_list	*next;
}			t_ptr_list;

int			push_ptr(t_ptr_list **head, void *ptr);
void			free_ptr(t_ptr_list *ptr_list);

/* COMMON */
void                    *xmalloc(int size, t_ptr_list **ptr_list);

#endif                  /* !UTILS_H_ */
