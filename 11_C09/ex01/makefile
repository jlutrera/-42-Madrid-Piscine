SRCS	=	srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
HEAD	=	includes
NAME	=	libft.a
LIBAR	=	ar rc
LIBRAN	=	ranlib
RM		=	rm -f
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	${SRCS:.c=.o}

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}:	${OBJS}
			${LIBAR} ${NAME} ${OBJS}
			${LIBRAN} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
