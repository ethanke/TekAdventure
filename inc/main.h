/*
** main.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Mon Mar 28 20:02:40 2016 Philippe Lefevre
** Last update Thu Apr  7 22:35:01 2016 Philippe Lefevre
*/

#ifndef			MAIN_H_
# define		MAIN_H_

# include		<lapin.h>
# include		<unistd.h>

# include		"utils.h"
# include		"image.h"
# include		"back.h"
# include		"object.h"
# include		"sprite.h"
# include		"player.h"
# include		"prog.h"
# include		"disp.h"
# include		"parsing.h"

# ifndef		WIN_SETTING
#  define		WIN_SETTING
#  define		WIN_NAME	"TEKADVENTURE"
#  define		WIN_HEIGHT	768
#  define		WIN_WIDTH	1024
# endif			/* !WIN_SETTING */

t_bunny_response	mainloop(void *p);
t_bunny_response	event_key(t_bunny_event_state state,
				  t_bunny_keysym      key,
				  void                *data);
int			clean(t_prog *prog, int out);

# define		SUCCESS	0
# define		ERROR	-1

#endif			/* !MAIN_H_ */
