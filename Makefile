##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

MAIN	=		main.c

SRC		=		src/my_rpg.c					\
				src/game.c						\
				src/load_textures.c				\
				src/hud/menu.c					\
				src/hud/minimap.c               \
				src/hud/in_game.c				\
				src/hud/pause.c					\
				src/hud/inventory.c             \
				src/hud/loading_screen.c		\
				src/hud/change_character.c		\
				src/hud/easter_egg.c			\
				src/hud/settings.c				\
				src/hud/init.c					\
				src/character/init.c			\
				src/character/dash.c 			\
				src/character/move.c 			\
				src/character/print.c			\
				src/character/check_colide.c	\
				src/character/particle_hit.c	\
				src/character/weapon/gun.c		\
				src/character/bonus.c			\
				src/enemies/init.c				\
				src/enemies/ai.c				\
				src/enemies/enemy_action.c 		\
				src/enemies/enemy_manager.c		\
				src/enemies/shot.c 				\
				src/cam/init.c					\
				src/cam/cam.c 					\
				src/pnj/pnj.c					\
				src/pnj/dialogues.c				\
				src/pnj/hub.c					\
				src/tp/switch_map.c				\
				src/tp/tp.c						\
				src/map/init.c					\
				src/map/change_lvl.c			\
				src/map/get_level.c				\
				src/map/sets_objects.c 			\
				src/map/level_index.c			\
				src/map/open_map.c 				\
				src/map/special_lvl.c			\
				src/map/parse_map.c 			\
				src/map/get_size.c 				\
				src/map/generate.c				\
				src/map/get_rect.c				\
				src/map/get_teleport.c          \
				src/map/print_map.c				\
				src/map/print_elem.c            \
				src/map/score.c 				\
				src/particle/particle.c			\
				src/particle/patern.c			\
				src/particle/anim.c				\
				src/particle/free.c				\
				src/particle/init.c				\
				src/particle/actions_list.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

TESTS	=

NAME	=		my_rpg

LIB		=		lib/libmy.a

LIB_2	=		lib/libbuttons.a

CFLAGS 	=		-W -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS	=	-Llib/

LDIBS	=	-lmy -lmy_csfml -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:		$(NAME)

$(NAME):	$(LIB) $(LIB_2) $(OBJ)
			gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)

$(LIB):
			$(MAKE) -C lib/my

$(LIB_2):	$(LIB)
			$(MAKE) -C lib/my_csfml

run:		$(NAME)
			./$(NAME)

tests_run:	LDIBS += -lcriterion --coverage
tests_run:	all
			gcc -o $@ $(SRC) $(TESTS) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)
			-./$@

clean:
		find . -name "*.o" -delete -o -name "*~" -delete -o -name "*.gc*" -delete

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(LIB)
		$(RM) $(LIB_2)
		$(RM) vgcore.*
		make -C lib/my fclean
		make -C lib/my_csfml fclean

re:		fclean all

.PHONY: re fclean clean tests_run run all