##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	my_getnbr.c			\
		my_isneg.c			\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c			\
		my_revstr.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strlen.c			\
		my_strncmp.c		\
		my_swap.c			\
		sum_stdarg.c		\
		my_printf.c			\
		bis_disp.c			\
		number_base.c		\
		my_free_arr.c		\
		binary_convert.c	\
		clean_bin.c 		\
		my_clean_str.c 		\
		my_strncat.c 		\
		my_strcat.c			\
		my_strdup.c 		\
		my_str_c_copy.c 	\
		epur_shape.c 		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../$(Name)
	cp my.h ../../include/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clean fclean $(NAME) re
