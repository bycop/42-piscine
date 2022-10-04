# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bycop <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 16:52:33 by bycop          #+#    #+#              #
#    Updated: 2020/10/21 11:06:36 by bycop         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = main.c put.c

OBJS = ${SRCS:.c=.o}

HEADER = put.h

NAME = do-op

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${FLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
