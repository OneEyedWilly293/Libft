# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 21:00:09 by jgueon            #+#    #+#              #
#    Updated: 2025/05/02 16:57:49 by jgueon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

OBJECTS := $(SOURCES:%.c=%.o)

HEADERS := libft.h
NAME := libft.a
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
		ar -rcs $@ $^

%.o: %.c %(HEADERS)
		cc -c $< -o $@ $(CFLAGS)

all: $(NAME)

re: fclean all

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

.PHONY: all re fclean clean
.SECONDARY: $(OBJECTS) $(BONUS_OBJECTS)