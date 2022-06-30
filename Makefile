##
## EPITECH PROJECT, 2021
## makefile
## File description:
## compile all program
##

IFLAG   =       -I ./includes

SRC	=	handle_anthill.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		free_all.c	\
		pop_tab.c	\
		strwa/clean_string.c	\
		strwa/my_strwa.c	\
		strwa/my_strlen.c	\
		strwa/my_strcpy.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		data_man.c	\
		display.c	\
		erase_elt.c	\
		err_cases.c	\
		get_elt.c

CFLAG	=	-W -Werror -Wextra -Wall

TFLAG	=	-lcriterion --coverage

NAME	=	lem_in
all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(IFLAG) $(SRC) $(CFLAG) $(LFLAG) -g -g3

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)	\
	rm -f *.gcno	\
	rm -f *.gcda

val:
	gcc -o $(NAME) -I ./includes/ main.c $(SRC) $(IFLAG) $(CFLAG) -g -g3

tests_run:
	gcc -o unit_test $(MFLAG) -I ./includes/ $(SRC) $(CFLAG) $(TFLAG)
	./unit_test

re: fclean all
