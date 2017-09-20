/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:08:50 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:14:17 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	read_list_R(
**	reads contents of dir recursively
**	when -R flag is present
*/

void	read_list_r(t_lslist *head, char *path, char *flags)
{
	t_lslist	*current;
	char		*temp;

	current = head;
	while (current != NULL)
	{
		temp = temp_path(path, current->pack.data);
		if ((opendir(temp)) != NULL && (!(is_dot((current->pack.data)))))//current->data[0] != '.')
		{
			ft_putchar('\n');
			ls_print(temp_path(path, current->pack.data), flags);
		}
		current = current->next;
	}
}
