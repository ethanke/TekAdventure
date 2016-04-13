/*
** my_list.h for Minishell2 in /home/lefevr_h/Repository/Epitech/Year_1/Unix_System_programming/PSU_2015_minishell2/lib/list/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Tue Mar 29 19:40:02 2016 Philippe Lefevre
** Last update Wed Apr 13 06:29:02 2016 Victor Sousa
*/

#ifndef			MY_LIST_H_
# define		MY_LIST_H_

# include		<unistd.h>
# include		<stdlib.h>

typedef	struct		s_list
{
  void			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

t_list			*list_create_node(void *data);
t_list			*list_delete_node(t_list *list,
					  void (*ptr_funct)(void *data));
t_list			*list_add_node(t_list *list, void *data);
void			list_free(t_list *list, void (*ptr_funct)(void *data));

#endif			/* !MY_LIST_H_ */
