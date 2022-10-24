# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:22:24 by sangyeki          #+#    #+#              #
#    Updated: 2022/05/08 14:24:18 by sangyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk

all : server client

bonus : server client

server : server.o libft
	$(CC) -o $@ $< -Llibft -lft

client : client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o : %.c
	$(CC) -c $(CFLAGS) $?

libft :
	make -C libft

clean : 
	rm -f $(OBJECTS)
	make -C libft clean

fclean : clean
	rm -f server client libft/libft.a

re : fclean all

.PHONY : all libft clean fclean all bonus

