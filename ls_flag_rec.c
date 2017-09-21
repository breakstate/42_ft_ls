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
		printf("temp = %s\n", temp);
		if ((opendir(temp)) != NULL && (!(is_dot((current->pack.data)))))//current->data[0] != '.')
		{
			if (!(is_empty_dir(temp)))
			{
				ft_putchar('\n');
				ls_print(temp_path(path, current->pack.data), flags);
			}
			else
			{
				ft_putchar('\n');
				ft_putstr(temp);
				ft_putendl(":");
			}
		}
		temp = NULL;
		current = current->next;
	}
}
