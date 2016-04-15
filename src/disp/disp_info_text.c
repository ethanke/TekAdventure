/*
** disp_info_text.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr 15 06:58:45 2016 Gaëtan Léandre
** Last update Fri Apr 15 23:29:48 2016 Gaëtan Léandre
*/

#include		"main.h"

t_text			*create_text(t_bunny_position pos, char *text,
				    int nbr, unsigned int color)
{
  t_text		*result;
  int			i;

  i = -1;
  if ((result =  malloc(sizeof(t_text))) == NULL)
    return (NULL);
  result->turn = 10;
  result->msg = NULL;
  if (text != NULL && (result->msg
		       =  malloc(sizeof(char) * (my_strlen(text) + 1))) == NULL)
    return (NULL);
  else if (text != NULL)
    {
      while (text[++i])
	result->msg[i] = text[i];
      result->msg[++i] = '\0';
    }
  result->nbr = nbr;
  result->font.font_size = 18;
  result->font.font_color.full = color;
  result->pos = pos;
  return (result);
}

void			add_text(t_prog *prog, t_text *text)
{
  if (text == NULL)
    return;
  text->next = prog->text;
  if (prog->text != NULL)
    prog->text->prev = text;
  text->prev = NULL;
  prog->text = text;
  text->font.font_img = prog->font->font_img;
}

void			delete_from_text(t_prog *prog, t_text *save)
{
  if (save->prev == NULL)
    prog->text = save->next;
  if (save->next != NULL)
    save->next->prev = save->prev;
  if (save->prev != NULL)
    save->prev->next = save->next;
  if (save->msg != NULL)
    free(save->msg);
  free(save);
}

void			disp_font(t_prog *prog, t_text *first,
				  t_bunny_pixelarray *pix)
{
  t_text		*tmp;
  t_text		*save;

  tmp = first;
  while (tmp != NULL)
    {
      if (tmp->msg)
	tektext(tmp->msg, &tmp->pos, pix, &tmp->font);
      else
	teknbr(tmp->nbr, &tmp->pos, pix, &tmp->font);
      tmp->turn--;
      save = tmp;
      tmp = tmp->next;
      if (save->turn == 0)
	delete_from_text(prog, save);
    }
}

t_bunny_position	pos_alea(int x_min, int x_max, int y_min, int y_max)
{
  t_bunny_position	pos;

  pos.x = ((rand() % (x_max - x_min)) + x_min);
  pos.y = ((rand() % (y_max - y_min)) + y_min);
  return (pos);
}
