# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 00:00:23 by ejahan            #+#    #+#              #
#    Updated: 2022/03/17 10:52:00 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCS	=	./INCS/philosophers.h

SRCS	=	./SRCS/main.c ./SRCS/utils.c ./SRCS/parsing.c ./SRCS/init.c \
			./SRCS/routine.c ./SRCS/start.c ./SRCS/sleep.c ./SRCS/check.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

RM		=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=thread #-g3 -fsanitize=address

all:		${NAME}

${NAME}:	${OBJS}
			$(CC) -lpthread ${CFLAGS} $(OBJS) -I $(INCS) -o $(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
