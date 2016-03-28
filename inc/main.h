/*
** main.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 19:52:27 2016 Philippe Lefevre
** Last update Mon Mar 28 19:52:53 2016 Philippe Lefevre
*/

#ifndef			MAIN_H_
# define		MAIN_H_
# define		WIN_NAME	"TEKADVENTURE"
# define		WIN_HEIGHT	800
# define		WIN_WIDTH	1280

typedef	struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*array;
  t_bunny_position	position;
  t_color		color;
}			t_prog;

# define		SUCCESS	0
# define		ERROR	-1

#endif			/* !MAIN_H_ */
