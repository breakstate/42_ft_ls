# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 15:04:59 by bmoodley          #+#    #+#              #
#    Updated: 2017/09/21 13:35:27 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls


SRC = LS_main.c \
		LS_flag_long.c \
		LS_flag_long_2.c \
		LS_flags.c \
		LS_path_man.c \
		LS_sorting.c \
		LS_utils.c \
		LS_lists.c

FLAGS = -Wall -Werror -Wextra

LIBFT = -lft -L ./libft

INCLUDES = -I ./libft/includes/

all: $(NAME)

$(NAME):
	gcc -o -g $(NAME) $(SRC) $(FLAGS) $(LIBFT) $(INCLUDES)

lib:
	$(MAKE) -C libft

ft_ls:
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LIBFT) $(INCLUDES)

clean:
	rm -f $(NAME)

fclean:	clean
	$(MAKE) fclean -C ./libft

re: fclean lib all
	clear
