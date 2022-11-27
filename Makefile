# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:23:24 by ngennaro          #+#    #+#              #
#    Updated: 2022/11/27 19:10:06 by ngennaro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
var_type_int.c \
var_type_str.c \
var_type_unsigned_int.c

OBJS	= ${SRCS:.c=.o}

CC	= cc

HEADERS	= printf.h

NAME	= printf.a

CFLAGS	= -Wall -Wextra -Werror

all :		${NAME}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean
			$(MAKE) all

%.o: %.c	$(HEADERS) Makefile
			${CC} ${CFLAGS} -o $@ -c $< -I $(HEADERS)

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}

.PHONY:		all clean fclean re
