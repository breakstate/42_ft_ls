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


SRC = ls_main.c \
		ls_path_man.c \
		ls_lists.c \
		ls_is.c \
		ls_flag_rec.c \
		ls_utils.c \
		ls_flag_long.c \
		ls_flags.c \
		ls_flag_rev.c \
		ls_flag_long_2.c \
		ls_flag_time.c \
		ls_utils_2.c

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
