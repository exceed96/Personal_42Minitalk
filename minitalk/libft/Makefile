#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 13:07:20 by sangyeki          #+#    #+#              #
#    Updated: 2022/03/15 13:50:42 by sangyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror -c

SOURCES = ft_atoi.c \
		  ft_isalpha.c \
		  ft_memchr.c \
		  ft_memset.c \
		  ft_strlcpy.c \
		  ft_strrchr.c \
		  ft_bzero.c \
		  ft_isascii.c \
		  ft_memcmp.c \
		  ft_strchr.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_calloc.c \
		  ft_isdigit.c \
		  ft_memcpy.c \
		  ft_strdup.c \
		  ft_strncmp.c \
		  ft_toupper.c \
		  ft_isalnum.c \
		  ft_isprint.c \
		  ft_memmove.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_strtrim.c \
		  ft_striteri.c \
		  ft_split.c \

SOURCES_B = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstmap.c \

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

NAME = libft.a

ifdef WITH_BONUS
	OBJ = $(OBJECTS) $(OBJECTS_B)
else
	OBJ = $(OBJECTS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	ar cr $@ $^

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
