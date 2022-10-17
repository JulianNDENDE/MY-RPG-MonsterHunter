##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

SRC		=		buttons_anim.c		\
				create_buttons.c	\
				create_struct.c		\
				free_struct.c		\
				buttons_set.c		\
				rect_gestion.c		\
				buttons_get.c		\
				sound_music.c		\
				clock.c				\
				window.c			\
				display_fonction.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy_csfml.a

CFLAGS 	=		-g

CPPFLAGS	=	-I../../include

LDIBS	=	-lcsfml -graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	gcc cpyh cpylib

gcc:
		gcc -c $(SRC) $(CFLAGS) $(CPPFLAGS)
		ar rc $(NAME) *.o

cpylib:
		cp $(NAME) ../

cpyh:
		cp my_csfml.h ../../include/

clean:
		$(RM) *.o

fclean:	clean
		$(RM) ../$(NAME)

.PHONY: re fclean clean cpyh cpylib all