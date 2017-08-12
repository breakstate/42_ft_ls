# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 15:04:59 by bmoodley          #+#    #+#              #
#    Updated: 2017/07/31 15:34:34 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ls_main.c \
		ls_path_man.c \
		ls_lists.c \
		ls_is.c \
		ls_flag_rec.c \
		ls_utils.c \
		ls_flag_long.c \
		ls_flags.c \
		ls_flag_rev.c

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
