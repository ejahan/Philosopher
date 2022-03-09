# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 00:00:23 by ejahan            #+#    #+#              #
#    Updated: 2022/03/10 00:40:27 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCS	=	./INCS/philosophers.h

SRCS	=	./SRCS/main.c ./SRCS/utils.c ./SRCS/parsing.c \

OBJS	=	${SRCS:.c=.o}

CC		=	clang

RM		=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror #-g3 -fsanitize=address

all:		${NAME}

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} $(OBJS) -I $(INCS) -o $(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
