# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 15:04:59 by bmoodley          #+#    #+#              #
#    Updated: 2017/07/05 16:04:28 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ls_main.c \
		ls_path_man.c \
		ls_lists.c \
		ls_is.c \
		ls_recursive.c \
		ls_utils.c \
		ls_long.c \
		ls_flags.c

FLAGS = -Wall -Werror -Wextra

LIBFT = -lft -L ./libft

INCLUDES = -I ./libft/includes/

all: $(NAME)

$(NAME):
	$(MAKE) -C libft
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LIBFT) $(INCLUDES)

lib:
	$(MAKE) -C ./libft

ft_ls:
	gcc -o $(NAME) $(SRC) $(FLAGS) $(LIBFT) $(INCLUDES)

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean:	clean
	$(MAKE) fclean -C ./libft

re: fclean lib all
	clear
