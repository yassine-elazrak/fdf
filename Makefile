# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:04:02 by yelazrak          #+#    #+#              #
#    Updated: 2019/07/09 11:49:38 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = draw_line.c \
	   read_file.c \
	   mangement_fonction_of_key.c \
	   main.c \
	    rotation_of_map_and_zoom.c \
		ft_free.c \
		 management_tab.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = shell.h

CC = gcc -Wall -Werror -Wextra
DD = -lmlx -framework OpenGL -framework AppKit
all : $(NAME)

$(NAME):
	@make  -C libft
	@$(CC) $(SRCS) $(DD) libft/libft.a -I $(INCLUDES) -o  $(NAME)
clean :
	@rm -rf $(OBJS)
	@make clean -C libft
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
re: fclean all
