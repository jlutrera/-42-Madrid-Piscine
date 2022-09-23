SRCS	=  	srcs/cat.c srcs/ft_cat.c srcs/ft_display_custom_error.c srcs/ft_stdin.c
HEAD	=	includes
OBJS	= 	${SRCS:.c=.o}
NAME	= 	ft_cat
CC		= 	gcc
RM		= 	rm -f
CFLAGS	= 	-Wall -Wextra -Werror

.c.o :		${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME} : 	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : 		${NAME}

clean :
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME}

.PHONY: 	all clean fclean re .c.o
