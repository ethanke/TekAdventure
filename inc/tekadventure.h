/*
** tekadventure.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 20:02:40 2016 Philippe Lefevre
** Last update Mon Mar 28 20:04:00 2016 Philippe Lefevre
*/

#ifndef			TEKADVENTURE_H_
# define		TEKADVENTURE_H_
# include		<lapin.h>

# ifndef		WIN_SETTING
#  define		WIN_SETTING
#  define		WIN_NAME	"TEKADVENTURE"
#  define		WIN_HEIGHT	768
#  define		WIN_WIDTH	1024
# endif			/* !WIN_SETTING */

typedef	struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*array;
  t_bunny_position	position;
  t_color		color;
}			t_prog;

t_bunny_response	mainloop(void *p);
int			clean(t_prog *prog, int out);

# define		SUCCESS	0
# define		ERROR	-1

#endif			/* !TEKADVENTURE_H_ */
