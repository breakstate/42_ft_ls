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

void			list_add_back(t_lslist **head, char *data, char *flags)
{
	t_lslist	*current;
	struct stat		statbuf;
	char *stats;

	current = *head;
	if (!(check_flags(flags, 'a')))
		if (data[0] == '.')
			return ;
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		stat(data, &statbuf);
		current->next = create_elem(node);
	}
	else
	{
		stat(data, &statbuf);
		*head = create_elem(node);
	}
	//printf("  ->data  = %s\n  ->stats = %s\n\n", data, stats);
}

void			print_list(t_lslist *head)//, struct stat *statbuf)//added statbuf
{
	t_lslist	*current;

	current = head;
	while (current != NULL)
	{
		//get_stats(statbuf);//testing L stuff - should probs be in list_add_back
		//don't send statbuf here, it never changes
		//instead send updated d_name each time
		//and refresh the statbuf

		//add if flag -l
		ft_putstr(current->pack.stats);
		ft_putendl(current->pack.data);
		current = current->next;
	}
}

void			sort_list(t_lslist *head, char *flags)
{
	int			sorted;
	t_lslist	*cur;
	t_pack		*tmp;

	cur = head;
	tmp = (t_pack*)malloc(sizeof(t_pack) * 1);
	if (!(check_flags(flags, 'r')))
		while (cur->next)
		{
			if (ft_strcmp(cur->pack.data, cur->next->pack.data) > 0)
			{
				sorted = 1;
				tmp = &(cur->pack);//not sure if & is correct
				cur->pack = cur->next->pack;
				(cur->next->pack) = *tmp;

				//tmp_stats = cur->stats;//too
				//cur->stats = cur->next->stats;//many
				//cur->next->stats = tmp_stats;//lines
			}
			cur = cur->next;
			if (cur->next == NULL && sorted == 1)
			{
				cur = head;
				sorted = 0;
			}
		}
	else
		sort_list_r(head);
}
/*
void	sort_list(t_lslist **head, char *flags)
{
	t_lslist	current;
	t_lslist	prev_n;
	t_lslist	next_n;

	current 
}
*/
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
