/*
** disp_equip_carac.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 04:26:46 2016 Victor Sousa
** Last update Sat Apr 16 04:27:24 2016 Victor Sousa
*/

#include		"main.h"

void			disp_stamina(t_prog *prog, t_font *font, t_item *item,
				     t_bunny_position rect_pos)
{
  char			*nbr;
  char			*str;

  if ((str = malloc(20)) == NULL)
    return;
  str = my_strcpy(str, "stamina   : ");
  if ((nbr = my_itoa(item->object->caract->stamina)) == NULL)
    return;
  str = my_strcat(str, nbr);
  tektext(str, &rect_pos, prog->pix, font);
  free(str);
  free(nbr);
}

void			disp_strength(t_prog *prog, t_font *font, t_item *item,
				      t_bunny_position rect_pos)
{
  char			*nbr;
  char			*str;

  if ((str = malloc(20)) == NULL)
    return;
  str = my_strcpy(str, "strength  : ");
  if ((nbr = my_itoa(item->object->caract->strength)) == NULL)
    return;
  str = my_strcat(str, nbr);
  tektext(str, &rect_pos, prog->pix, font);
  free(str);
  free(nbr);
}

void			disp_critical(t_prog *prog, t_font *font, t_item *item,
				      t_bunny_position rect_pos)
{
  char			*nbr;
  char			*str;

  if ((str = malloc(20)) == NULL)
    return;
  str = my_strcpy(str, "critical  : ");
  if ((nbr = my_itoa(item->object->caract->critical)) == NULL)
    return;
  str = my_strcat(str, nbr);
  tektext(str, &rect_pos, prog->pix, font);
  free(str);
  free(nbr);
}

void			disp_intel(t_prog *prog, t_font *font, t_item *item,
				   t_bunny_position rect_pos)
{
  char			*nbr;
  char			*str;

  if ((str = malloc(20)) == NULL)
    return;
  str = my_strcpy(str, "intellect : ");
  if ((nbr = my_itoa(item->object->caract->intellect)) == NULL)
    return;
  str = my_strcat(str, nbr);
  tektext(str, &rect_pos, prog->pix, font);
  free(str);
  free(nbr);
}

void			disp_armor(t_prog *prog, t_font *font, t_item *item,
				   t_bunny_position rect_pos)
{
  char			*nbr;
  char			*str;

  if ((str = malloc(20)) == NULL)
    return;
  str = my_strcpy(str, "armor     : ");
  if ((nbr = my_itoa(item->object->caract->armor)) == NULL)
    return;
  str = my_strcat(str, nbr);
  tektext(str, &rect_pos, prog->pix, font);
  free(str);
  free(nbr);
}
