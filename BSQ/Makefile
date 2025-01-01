# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 12:35:42 by jutrera-          #+#    #+#              #
#    Updated: 2025/01/02 00:14:07 by jutrera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

SRCS	= srcs/main.c \
		  srcs/ft_checkmap.c \
		  srcs/ft_createmap.c \
		  srcs/ft_findlargest.c \
		  srcs/ft_utilities.c \
		  srcs/ft_utilities2.c \
		  srcs/ft_utilities3.c
HEAD	= includes
RM		= rm -f
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror 
LEAKS	= -fsanitize=address
OBJS	= ${SRCS:.c=.o}

${NAME}	: ${OBJS}
		  ${GCC} ${LEAKS} ${CFLAGS} -o ${NAME} ${OBJS}

all		: ${NAME}

.c.o	:
		  ${GCC} ${CFLAGS} -c  $< -o ${<:.c=.o} -I ${HEAD}

clean	:
		  rm -f ${OBJS}

fclean	: clean
		  rm -f ${NAME}

re		: fclean all

.PHONY : all clean fclean re
