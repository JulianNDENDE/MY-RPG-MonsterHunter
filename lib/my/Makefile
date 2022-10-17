##
## EPITECH PROJECT, 2020
## make file
## File description:
## compile all the files
##

all:    gcc cpylib cpymyh clean

gcc:
		gcc -c *.c -g
		ar rc libmy.a *.o

cpylib:
		cp libmy.a ../

cpymyh:
		cp my_lib.h ../../include/

clean:
		rm -f *.o

fclean:
		rm -f libmy.a
