SRCS		= srcs/main.c srcs/ft_strdup.c srcs/ft_squares.c srcs/ft_checkmaps.c srcs/ft_create_map.c

OBJS		= ${SRCS:.c=.o}

HEAD		= includes

NAME		= bsq

RM			= rm -f

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c  $< -o ${<:.c=.o} -I ${HEAD}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean
