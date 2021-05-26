# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 12:59:55 by stribuzi          #+#    #+#              #
#    Updated: 2021/02/10 13:03:04 by stribuzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	errors.c \
					find_index.c \
					ft_split.c \
					get_next_line.c \
					main.c \
					moves_1.c \
					moves.c \
					sort_sup.c \
					sort.c \
					utils_1.c \
					utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

%.o : %.c
	$(CC)  -c -o $@ $<

all:			$(NAME)

$(NAME):		 $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
