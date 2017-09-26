/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:05:28 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:12:48 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lslist		*create_elem(char *data, char* stats, time_t mtime, char *flags)
{
	t_lslist	*tmp;

	tmp = (t_lslist *)malloc(sizeof(t_lslist));
	if (tmp != NULL)
	{
		tmp->pack.data = data;
		if (check_flags(flags, 'l'))
		{
			tmp->pack.stats = stats;
			tmp->pack.mtime = mtime;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
/*
"."
"./libft"
fs_ls(char *dir, lst)
{
	save(lst)
	sort
	print
	recurse
}
*/

void			list_add_back(t_l **head, char *data, char *path, char *flags)//, char *flags)
{
	t_lslist		*current;
	struct stat		statbuf;
	char			*stats;
	char			*fullpath;

	current = *head;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		lstat((fullpath = temp_path(path, data)), &statbuf);
		current->next = create_elem(node);
	}
	else
	{
		lstat((fullpath = temp_path(path, data)), &statbuf);
		*head = create_elem(node);
	}
	free(fullpath);
}

void			print_list(t_lslist *current, char *flags)//, struct stat *statbuf)//added statbuf
{
	while (current != NULL)
	{
		//add hidden file check!!!!!
		//remember to exlude "." and ".." when looking for hidden files.

//		if (check_flags(flags, 'a'))
//			ft_putendl(current->pack.data);
//		else

		if (check_flags(flags, 'a'))
		{
			if (check_flags(flags, 'l'))
				ft_putstr(current->pack.stats);
			ft_putendl(current->pack.data);
		}
		else
		{
			if(!is_hidden(current->pack.data))
			{
				if (check_flags(flags, 'l'))
					ft_putstr(current->pack.stats);
				ft_putendl(current->pack.data);
			}
		}
		current = current->next;
	}
}

void			free_list(t_lslist **head)
{
	t_lslist	*current;
	t_lslist	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}
