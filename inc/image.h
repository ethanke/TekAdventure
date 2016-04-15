/*
** image.h for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr 15 03:26:21 2016 Gaëtan Léandre
** Last update Fri Apr 15 03:32:09 2016 Gaëtan Léandre
*/

/*
 ** image.h for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
 **
 ** Made by Gaëtan Léandre
 ** Login   <leandr_g@epitech.eu>
 **
 ** Started on  Wed Apr  6 23:41:06 2016 Gaëtan Léandre
 ** Last update Fri Apr 15 03:09:51 2016 Gaëtan Léandre
 */

 #ifndef   _IMAGE_H_
 # define  _IMAGE_H_

 # define  PLACE_IMG_ALPHA  60

 typedef struct          s_texture
 {
   int                   width;
   int                   height;
   t_color               **color;
 }                       t_texture;

 typedef struct          s_hitbox
 {
   int                   x;
   int                   y;
   int                   width;
   int                   height;
 }                       t_hitbox;

 typedef struct          s_anim
 {
   int   		pos;
   int   		max;
   t_texture 	 	*texture;
   t_hitbox  		*hitbox;
 }                      t_anim;

 typedef struct  	s_font
 {
   t_texture		*font_img;
   int   		font_size;
   t_color  		font_color;
 }   			t_font;

 t_texture        	*load_image(const char *file, t_ptr_list **ptr_list);
 t_texture  		*pix_array_to_texture(t_bunny_pixelarray *pix,
					      t_ptr_list **pr);
 void   		put_image(t_texture *bmp,
				  t_bunny_pixelarray *pix,
				  t_bunny_position *pos);
 void   		place_image(t_hitbox pos,
				    t_hitbox fetch,
				    t_texture *tex,
				    t_bunny_pixelarray *pix);
 void   		place_image_transpa(t_hitbox pos,
					    t_hitbox fetch,
					    t_texture *tex,
					    t_bunny_pixelarray *pix);
 void   		fill_image(t_hitbox box,
				   t_bunny_pixelarray *pix, unsigned int col);
 void   		fill_pix(t_bunny_pixelarray *pix, unsigned int col);
 void   		redim_image(t_hitbox *pos,
				    t_texture *tex,
				    t_bunny_pixelarray *pix);
 t_hitbox  		create_hitbox(int x, int y, int width, int height);
 t_hitbox  		*create_hitbox_ptr(t_bunny_position pos, int width,
					   int height, t_ptr_list *ptr_list);
 void   		tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
 void   		tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);
 void             	tekchar(t_bunny_pixelarray *out,
				t_font *font,
				const t_bunny_position *pos,
				const char c);
 void   		tektext(const char *str,
				const t_bunny_position *pos,
				t_bunny_pixelarray *out,
				t_font *font);
 void   		teknbr(int nb, const t_bunny_position *pos,
			       t_bunny_pixelarray *out,
			       t_font *font);
void			tektextcenter(const char *str,
				      const t_bunny_position *pos,
				      t_bunny_pixelarray *out,
				      t_font *font);
void			animated_image(t_anim *anim, t_hitbox hitbox,
				       t_bunny_pixelarray *pix);

 #endif   /*_IMAGE_H_*/
