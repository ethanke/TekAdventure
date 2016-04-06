/*
** main.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 20:02:40 2016 Philippe Lefevre
** Last update Wed Apr  6 23:12:42 2016 victor sousa
*/

#ifndef			MAIN_H_
# define		MAIN_H_

# include		<lapin.h>
# include		<unistd.h>

# include		"utils.h"

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
  t_ptr_list		*ptr_list;
  t_bunny_position	position;
}			t_prog;

t_bunny_response	mainloop(void *p);
t_bunny_response	event_key(t_bunny_event_state state,
				  t_bunny_keysym      key,
				  void                *data);
int			clean(t_prog *prog, int out);

# define		SUCCESS	0
# define		ERROR	-1

#endif			/* !MAIN_H_ */
