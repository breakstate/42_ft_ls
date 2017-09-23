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
	//int	debug = 0;

	current = head;
	while (current != NULL)
	{
		//printf("debug = %d\n", debug++);//debug
		printf("data = |%s|\n", current->pack.data);
		temp = temp_path(path, current->pack.data);
		//printf("temp = %s\n", temp);
		//check for hidden?
		if ((opendir(temp)) != NULL && (!(is_dot((current->pack.data)))))//current->data[0] != '.')
		{
			if (!(is_empty_dir(temp)))
			{
				//printf("if\n");
				ft_putchar('\n');
				ls_print(temp_path(path, current->pack.data), flags);
			}
			else
			{
				//printf("else\n");
				ft_putchar('\n');
				ft_putstr(temp);
				ft_putendl(":");
			}
		}
		temp = NULL;
		current = current->next;
	}
	//free_list(head);moved here maybe? not sure if should
	printf("****NULLED OUT*****\n");	
}
//end condition is empty dir I think so might be infinite looping when last dir sint empty, and not resetting .