# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 19:14:16 by ssujaude          #+#    #+#              #
#    Updated: 2025/11/19 19:16:40 by ssujaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

RM = rm -f

AR = ar rcs

SRCS = \
	ft_printf.c

BONUS = \
	

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}


all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: ${OBJS} ${BONUS_OBJS}
	$(AR) ${NAME} $(OBJS) ${BONUS_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 