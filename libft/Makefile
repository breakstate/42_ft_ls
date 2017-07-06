# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 15:02:38 by bmoodley          #+#    #+#              #
#    Updated: 2017/06/25 18:11:12 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC1 = ft_isascii.c\
	  ft_strlen.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_strdup.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\

SRC2 = ft_putstr.c\
	  ft_putchar_fd.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_strclr.c\
	  ft_strjoin.c\
	  ft_strnew.c\
	  ft_strsub.c\
	  ft_putchar.c\

SRC3 = ft_putstr_fd.c\
	  ft_strncmp.c\
	  ft_strtrim.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strdel.c\
	  ft_memdel.c\
	  ft_memalloc.c\
	  ft_strlcat.c\

SRC4 = ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memmove.c\
	  ft_strtrim_delim.c\
	  ft_strsplit.c\
	  ft_atoi.c\
	  ft_isspace.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ3 = $(SRC3:.c=.o)

OBJ4 = $(SRC4:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I./includes $(SRC1) $(SRC2) $(SRC3) $(SRC4) 
	ar rc $(NAME) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ3) $(OBJ4)
	ranlib $(NAME)

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

fclean: clean
	rm -f $(NAME)

re: fclean all
