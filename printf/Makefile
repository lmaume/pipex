# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:10:53 by lmaume            #+#    #+#              #
#    Updated: 2024/06/13 16:53:53 by lmaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		type_select/ft_type_c.c \
		type_select/ft_type_d.c \
		type_select/ft_type_i.c \
		type_select/ft_type_p.c \
		type_select/ft_type_d.c \
		type_select/ft_type_porcent.c \
		type_select/ft_type_s.c \
		type_select/ft_type_u.c \
		type_select/ft_type_x.c \
		type_select/ft_type_xmaj.c \
		utils/ft_hexa_converter.c \
		utils/ft_ptr_to_hexa.c \
		utils/ft_positive_itoa.c \
		utils/ft_str_toupper.c

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) all -C ./libft
	@cp $(LIBFT) $(NAME)
	@ar -rc $(NAME) $(OBJS)

clean :
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re : fclean all

debug : re
	clear && cc -Wall -Wextra -g3 debug/*.c debug/utils/*/*.c libftprintf.a && ./a.out