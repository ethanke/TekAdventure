##
## Makefile for Raytracer in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_raytracer1
##
## Made by Philippe Lefevre
## Login   <lefevr_h@epitech.net>
##
## Started on  Tue Mar  8 04:03:23 2016 Philippe Lefevre
## Last update Wed Apr 13 03:45:56 2016 Gaëtan Léandre
##

NAME		=	tekadventure

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRCDIR		=	src
DISPDIR		=	$(SRCDIR)/disp
EVENTDIR	=	$(SRCDIR)/event
FIGHTDIR	=	$(EVENTDIR)/fight
NPCDIR		=	$(EVENTDIR)/npc
UTILSDIR	=	$(SRCDIR)/utils
IMGDIR		=	$(SRCDIR)/image
PARSDIR		=	$(SRCDIR)/parsing
ASTAR		=	$(SRCDIR)/astar
INCDIR		=	inc
LIBDIR		=	lib

RM		=	rm -f

CC		=	gcc
CFLAGS		=	-W -Wall -Wextra -g3 -ggdb	\
			-ansi -pedantic				\
			-I/home/${USER}/.froot/include		\
			-I$(INCDIR)

LDFLAGS		=	-L/home/${USER}/.froot/lib		\
			-llapin					\
			-L/usr/local/lib			\
			-lsfml-audio				\
			-lsfml-graphics				\
			-lsfml-window				\
			-lsfml-system				\
			-lstdc++ -ldl				\
			-lm

SRC		=	$(SRCDIR)/main.c			\
			$(SRCDIR)/loop.c			\
			$(SRCDIR)/end.c

SRC		+=	$(PARSDIR)/parsing.c			\
			$(PARSDIR)/parsing_object.c		\
			$(PARSDIR)/parsing_decors.c		\
			$(PARSDIR)/parsing_sprite.c		\
			$(PARSDIR)/parsing_player.c		\
			$(PARSDIR)/parsing_scene.c		\
			$(PARSDIR)/parsing_npc.c		\

SRC		+=	$(DISPDIR)/disp_hotbar.c		\
			$(DISPDIR)/disp_inventory.c		\
			$(DISPDIR)/disp_selected_inv_item.c	\
			$(DISPDIR)/disp_item_info.c		\
			$(DISPDIR)/disp_scene.c			\
			$(DISPDIR)/init_hitbox_scene.c		\
			$(DISPDIR)/disp_utils.c			\
			$(DISPDIR)/disp_npc_exchange.c		\
			$(DISPDIR)/disp_npc_interact.c

SRC		+=	$(EVENTDIR)/event_key.c			\
			$(EVENTDIR)/event_click.c		\
			$(EVENTDIR)/inventory_click.c		\
			$(EVENTDIR)/get_click_inventory_pos.c	\
			$(EVENTDIR)/get_click_npc_trade_pos.c	\
			$(EVENTDIR)/get_grille_pos.c		\
			$(EVENTDIR)/click_map.c			\

SRC		+=	$(FIGHTDIR)/start_fight.c

SRC		+=	$(NPCDIR)/interact_npc.c

SRC		+=	$(UTILSDIR)/xmalloc.c			\
			$(UTILSDIR)/ptr_list.c			\
			$(UTILSDIR)/my_strdup.c			\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/my_strcat.c			\
			$(UTILSDIR)/my_strcpy.c			\
			$(UTILSDIR)/my_puterror.c		\
			$(UTILSDIR)/my_strlen.c			\
			$(UTILSDIR)/my_itoa.c			\
			$(UTILSDIR)/list_create_node.c		\
			$(UTILSDIR)/list_add_node.c		\
			$(UTILSDIR)/my_draw_square.c		\
			$(UTILSDIR)/my_swap.c

SRC		+=	$(IMGDIR)/disp_image.c			\
			$(IMGDIR)/hitbox_creator.c		\
			$(IMGDIR)/load_image.c			\
			$(IMGDIR)/tektext.c			\
			$(IMGDIR)/tekpixel.c

SRC		+=	$(ASTAR)/astar.c			\
			$(ASTAR)/calculs.c			\
			$(ASTAR)/go_back.c			\
			$(ASTAR)/go_to.c			\
			$(ASTAR)/init_tab.c

OBJ		=	$(SRC:.c=.o)

all		:	title $(NAME)

title		:
			@$(ECHO) $(GREEN)Tek$(TEAL)Adventure$(DEFAULT)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) &&	\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ &&		\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

clean		:
			@$(RM) $(OBJ)

fclean		:	clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
