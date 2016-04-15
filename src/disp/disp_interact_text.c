/*
** disp_interact_text.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 23:30:25 2016 Victor Sousa
** Last update Fri Apr 15 23:32:25 2016 Victor Sousa
*/

#include		"main.h"

void			disp_decord_life_text(t_prog *prog)
{
  if ((prog->disp_str =
       malloc(my_strlen(my_itoa(prog->current_click.
				decors->decors_breakable->life)) + 20))
      == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str, "decors has now ");
  prog->disp_str =
  my_strcat(prog->disp_str, my_itoa(prog->current_click.
				    decors->decors_breakable->life));
  prog->disp_str = my_strcat(prog->disp_str, " life");
  prog->disp_delay = 25;
}

void			disp_need_tools(t_prog *prog)
{
  if ((prog->disp_str =
       malloc(my_strlen(fint_obj_by_id(prog->scene->object,
				       prog->current_click.
				       decors->decors_breakable->
				       breakable_by)->name) + 25))
      == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str, "Wrong tools, you need ");
  prog->disp_str =
  my_strcat(prog->disp_str,
	    fint_obj_by_id(prog->scene->object,
			   prog->current_click.decors->
			   decors_breakable->
			   breakable_by)->name);
  prog->disp_delay = 25;
}

void			disp_pick_item(t_prog *prog)
{
  if ((prog->disp_str = malloc(39)) == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str,
			     "Pick the item to use\nin your hotbar!");
  prog->disp_delay = 25;
}

void			disp_cant_break(t_prog *prog)
{
  if ((prog->disp_str = malloc(33)) == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str,
			     "Can't break this, Too Strong :D");
  prog->disp_delay = 25;
}

void			disp_out_of_space(t_prog *prog)
{
  if ((prog->disp_str = malloc(27)) == NULL)
    return;
  prog->disp_str =
  my_strcpy(prog->disp_str,
	    "Out of space in inventory");
  prog->disp_delay = 25;
}
