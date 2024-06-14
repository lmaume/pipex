# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 15:13:38 by lmaume            #+#    #+#              #
#    Updated: 2024/06/14 20:09:00 by lmaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	verif/ft_isalpha.c \
		verif/ft_isdigit.c \
		verif/ft_isalnum.c \
		verif/ft_isascii.c \
		verif/ft_isprint.c \
		memory/ft_memset.c \
		memory/ft_bzero.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_calloc.c \
		strings/ft_atoi.c \
		strings/ft_itoa.c \
		strings/ft_strlen.c \
		strings/ft_split.c \
		strings/ft_strdup.c \
		strings/ft_substr.c \
		strings/ft_strjoin.c\
		strings/ft_strchr.c \
		strings/ft_strtrim.c \
		strings/ft_strlcpy.c \
		strings/ft_strlcat.c \
		strings/ft_toupper.c \
		strings/ft_tolower.c \
		strings/ft_strrchr.c \
		strings/ft_strncmp.c \
		strings/ft_strnstr.c \
		strings/ft_strmapi.c \
		strings/ft_striteri.c \
		strings/ft_check_line.c \
		strings/ft_file_to_tab.c \
		strings/ft_count_selected_char_in_tab.c \
		prints/ft_putstr_fd.c \
		prints/ft_putnbr_fd.c \
		prints/ft_print_tab.c \
		prints/ft_putendl_fd.c \
		prints/ft_putchar_fd.c \
		lists/ft_lstnew.c \
		lists/ft_lstdelone.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
