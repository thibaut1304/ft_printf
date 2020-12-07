# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 01:05:16 by thhusser          #+#    #+#              #
#    Updated: 2020/12/05 01:05:16 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC 			= 	clang

CC_FLAGS 	= 	-Wall -Wextra -Werror

SRCS 		= 	./sources/basic_function.c \
				./sources/basic_function_print.c \
				./sources/char_pourcent.c \
				./sources/ft_printf.c \
				./sources/function_hex_pointer.c \
				./sources/function_parsing.c \
				./sources/hex.c \
				./sources/integer.c \
				./sources/parsing.c \
				./sources/pointeur.c \
				./sources/string.c \
				./sources/unsigned.c \

OBJS		=	${SRCS:.c=.o}

.c.o:
				$(CC) ${CFLAGS} -c $< -o $(<:.c=.o) ${HEADER}

all : 			$(NAME)

$(NAME) :		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:	
				rm -f $(OBJS)

fclean:			clean
				rm -f ${NAME}
			
re:				fclean	all

.PHONY: 		all clean fclean re