NAME = push_swap

FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = ${SRCS= .c:.o}

DIRLIBFT = ../libft
LIBFT = ${LIBFT}/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	cc ${FLAGS} ${OBJS} -o ${NAME}

${LIBFT}: ${DIRLIBFT}
	make -C ${LIBFT}

clean:
	rm -rf ${OBJS}
	make -C ${DIRLIBFT} fclean

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: clean fclean re
