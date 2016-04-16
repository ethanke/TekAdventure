##
## Makefile for Raytracer in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_raytracer1
##
## Made by Philippe Lefevre
## Login   <lefevr_h@epitech.net>
##
## Started on  Tue Mar  8 04:03:23 2016 Philippe Lefevre
## Last update Sat Apr 16 04:42:54 2016 Philippe Lefevre
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

SRC		+=	$(PARSDIR)/parsing_error_msg_1.c	\
			$(PARSDIR)/parsing_error_msg_2.c	\
			$(PARSDIR)/parsing_error_msg_3.c	\
			$(PARSDIR)/parsing.c			\
			$(PARSDIR)/parsing_object.c		\
			$(PARSDIR)/parsing_decors.c		\
			$(PARSDIR)/parsing_sprite.c		\
			$(PARSDIR)/parsing_player.c		\
			$(PARSDIR)/parsing_scene.c		\
			$(PARSDIR)/parsing_npc.c		\
			$(PARSDIR)/parsing_ground_linkage.c	\
			$(PARSDIR)/parsing_ground.c		\
			$(PARSDIR)/parsing_linkage.c		\
			$(PARSDIR)/parsing_player_linkage.c	\
			$(PARSDIR)/parsing_sky_linkage.c	\
			$(PARSDIR)/parsing_gate.c		\
			$(PARSDIR)/parsing_gate_linkage.c	\
			$(PARSDIR)/parsing_sky.c

SRC		+=	$(DISPDIR)/disp_hotbar.c		\
			$(DISPDIR)/disp_inventory.c		\
			$(DISPDIR)/disp_equipement.c		\
			$(DISPDIR)/disp_selected_inv_item.c	\
			$(DISPDIR)/disp_item_info.c		\
			$(DISPDIR)/disp_equip_info.c		\
			$(DISPDIR)/disp_equip_carac.c		\
			$(DISPDIR)/disp_floating_item.c		\
			$(DISPDIR)/disp_scene.c			\
			$(DISPDIR)/init_hitbox_scene.c		\
			$(DISPDIR)/disp_utils.c			\
			$(DISPDIR)/disp_choose_npc_action.c	\
			$(DISPDIR)/disp_npc_exchange.c		\
			$(DISPDIR)/disp_npc_interact.c		\
			$(DISPDIR)/disp_npc_item.c		\
			$(DISPDIR)/disp_interact_choice.c	\
			$(DISPDIR)/disp_interact_text.c		\
			$(DISPDIR)/disp_info_text.c		\
			$(DISPDIR)/disp_fight.c

SRC		+=	$(EVENTDIR)/event_key.c			\
			$(EVENTDIR)/event_click.c		\
			$(EVENTDIR)/inventory_click.c		\
			$(EVENTDIR)/get_click_inventory_pos.c	\
			$(EVENTDIR)/get_click_npc_trade_pos.c	\
			$(EVENTDIR)/get_grille_pos.c		\
			$(EVENTDIR)/click_map.c			\
			$(EVENTDIR)/move.c			\
			$(EVENTDIR)/check_pos.c

SRC		+=	$(FIGHTDIR)/start_fight.c		\
			$(FIGHTDIR)/round_fight.c		\
			$(FIGHTDIR)/draw_fight.c		\
			$(FIGHTDIR)/update_bar.c		\
			$(FIGHTDIR)/catch_button.c

SRC		+=	$(NPCDIR)/interact_npc.c		\
			$(NPCDIR)/pull_out_item.c		\
			$(NPCDIR)/put_in_item.c			\
			$(NPCDIR)/move_in_hotbar.c		\
			$(NPCDIR)/draw_folowing_item.c		\
			$(NPCDIR)/get_click_value.c		\
			$(NPCDIR)/handle_red_cross.c

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
			$(UTILSDIR)/my_swap.c			\
			$(UTILSDIR)/my_put_nbr.c		\
			$(UTILSDIR)/my_strcmp.c

SRC		+=	$(IMGDIR)/disp_image.c			\
			$(IMGDIR)/hitbox_creator.c		\
			$(IMGDIR)/load_image.c			\
			$(IMGDIR)/tektext.c			\
			$(IMGDIR)/tekpixel.c			\
			$(IMGDIR)/fill_image.c			\
			$(IMGDIR)/teknbr.c			\
			$(IMGDIR)/tektext_center.c		\
			$(IMGDIR)/animated_image.c

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
