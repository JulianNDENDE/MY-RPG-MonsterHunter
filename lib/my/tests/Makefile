##
## EPITECH PROJECT, 2020
## makefile lib
## File description:
## unit tests
##

OBJ		=		../my_char_isnum.c			\
				../my_getnbr.c				\
				../my_erase_neg.c			\
				../my_compute_power_rec.c

TEST	=		test_my_isnum.c			\
				test_my_getnbr.c		\
				test_my_erase_neg.c		\
				test_my_power.c

NAME	=		unit_test

all:
		cd .. && make
		gcc -o $(NAME) $(OBJ) $(TEST) --coverage -lcriterion -L ../ -lmy
		./unit_test

net:	all
		cd gcovr
		gcovr --html --html-detail -o website_test.html --html-title test_criterion -r .. --exclude ../tests/ --exclude ../gcovr/
		/usr/bin/firefox website_test.html

clean:
		rm -f *~
		rm -f *.gc*

fclean: clean
		rm -f $(NAME)
		rm -f a.out
		rm -f *html
