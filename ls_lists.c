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
		//printf("::::::data = %s\n", tmp->pack.data);//debug
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
	t_lslist	*current;
	struct stat		statbuf;
	char *stats;
	char *fullpath;

	current = *head;
	/*if (!(check_flags(flags, 'a')))//DONT DO THIS HERE YA COOT
		if (data[0] == '.')
			return ;*/
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		fullpath = ft_strjoin(path, ft_strjoin("/", data));//maybe strjoin_f
		stat(fullpath, &statbuf);
		current->next = create_elem(node);
	}
	else
	{
		fullpath = ft_strjoin(path, ft_strjoin("/", data));
		stat(fullpath, &statbuf);
		*head = create_elem(node);
	}
	printf("  ->data  = %s\n  ->stats = %s\n\n", data, stats);
}
/*
void			print_list(t_lslist *head, char *flags)//, struct stat *statbuf)//added statbuf
{
	t_lslist	*current;

	current = head;
	(void)flags;
	while (current != NULL)
	{
		//get_stats(statbuf);//testing L stuff - should probs be in list_add_back
		//don't send statbuf here, it never changes
		//instead send updated d_name each time
		//and refresh the statbuf

		//add hidden file check!!!!!
		//remember to exlude "." and ".." when looking for hidden files.
		if (check_flags(flags, 'a'))
		{
			if (check_flags(flags, 'l'))
				ft_putstr(current->pack.stats);
			ft_putendl(current->pack.data);
			current = current->next;
		}
		else
		{
			if(!is_hidden(current->pack.data))
			{
				if (check_flags(flags, 'l'))
					ft_putstr(current->pack.stats);
				ft_putendl(current->pack.data);
			}
				current = current->next;
		}
	}
}
*/
void			sort_list(t_lslist *head)
{
	int			sorted;
	t_lslist	*cur;
	t_pack		tmp;

	cur = head;
	while (cur->next)
	{
		if (ft_strcmp(cur->pack.data, cur->next->pack.data) > 0)
		{
			sorted = 1;
			tmp = (cur->pack);//not sure if & is correct
			cur->pack = cur->next->pack;
			(cur->next->pack) = tmp;
		}
		cur = cur->next;
		if (cur->next == NULL && sorted == 1)
		{
			cur = head;
			sorted = 0;
		}
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
