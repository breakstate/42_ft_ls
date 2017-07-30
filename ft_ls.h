/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:54:18 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/07 17:48:26 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "./libft/includes/libft.h"
#include "ft_ls.h"

typedef struct	s_node{
	char	*data;
	struct s_node	*next;
}				t_node;

t_node	*create_elem(char *data);
void	list_add_back(t_node **head, char *data);
void	print_list(t_node *head);
void	sort_list(t_node *head);

#endif
