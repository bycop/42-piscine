# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bycop <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 13:37:53 by bycop          #+#    #+#              #
#    Updated: 2020/10/26 09:35:45 by bycop         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = basic.c ft_tail.c input.c write_ft.c

OBJS = ${SRCS:.c=.o}

NAME = ft_tail

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I functions.h

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${FLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
