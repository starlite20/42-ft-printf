# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 19:14:16 by ssujaude          #+#    #+#              #
#    Updated: 2025/11/29 01:14:13 by ssujaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a


MAKE = make -C
RM = rm -f

AR = ar rcs

SRCS = \
	ft_printf.c ft_print_utils_0.c\

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

OBJS = ${SRCS:.c=.o} 



all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	${MAKE} ${LIBFT_PATH} all
	cp ${LIBFT} $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re 