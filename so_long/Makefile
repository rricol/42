# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:41:24 by rricol            #+#    #+#              #
#    Updated: 2022/02/24 15:10:13 by rricol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I ${DMLX}
CFILES = so_long.c fct_map.c
DMLX = ./mlx
MLX = ${DMLX}/libmlx.a
DLIBFT = ./Libft
LIBFT = ${DLIBFT}/libft.a
SRCS = ${CFILES}
OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${MLX} -L ${DMLX} -framework OpenGL -framework AppKit -o ${NAME}

${MLX}:	${DMLX}
	make -C ${DMLX}

${LIBFT}: ${DLIBFT}
	make -C ${DLIBFT}
	
clean:
	rm -rf ${OBJS}
	make -C ${DMLX} clean

fclean: clean
	rm -rf ${NAME}

re: fclean all
