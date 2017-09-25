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

t_lslist		*create_elem(char *data, char* stats, time_t mtime)
{
	t_lslist	*tmp;

	tmp = (t_lslist *)malloc(sizeof(t_lslist));
	if (tmp != NULL)
	{
		tmp->pack.stats = stats;
		tmp->pack.data = data;
		tmp->pack.mtime = mtime;
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

void			list_add_back(t_lslist **head, char *data, char *path)//, char *flags)
{
	t_lslist		*current;
	struct stat		statbuf;
	char			*stats;

	current = *head;
	/*if (!(check_flags(flags, 'a')))//DONT DO THIS HERE YA COOT
		if (data[0] == '.')
			return ;*/
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		stat(temp_path(path, data), &statbuf);
		current->next = create_elem(node);
	}
	else
	{
		stat(temp_path(path, data), &statbuf);
		*head = create_elem(node);
	}
	//printf("  ->full = %s\n  ->path = %s\n  ->data = %s\n\n", fullpath, path, data);
	//printf("  ->data  = %s\n  ->stats = %s\n  ->debug = %d\n\n", data, stats, debug++);
}//node = data, stats = get_stats(&statbuf), statbuf.st_mtime

void			print_list(t_lslist *current, char *flags)//, struct stat *statbuf)//added statbuf
{
	while (current != NULL)
	{
		//add hidden file check!!!!!
		//remember to exlude "." and ".." when looking for hidden files.
		if (flags && (is_hidden(current->pack.data) == 0))
		{
			ft_putstr(">>>");
			ft_putendl(current->pack.data);
		}
/*		if (check_flags(flags, 'a'))
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
		}*/
		current = current->next;
	}
}

void			free_list(t_lslist *head)
{
	t_lslist	*current;
	t_lslist	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}
