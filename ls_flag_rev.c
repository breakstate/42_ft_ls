/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lists_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:47:59 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 15:53:36 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_list_r(t_lslist *head)
{
	int			sorted;
	t_lslist	*current;
	t_pack		tmp;

	current = head;
	while (current->next)
	{
		if (ft_strcmp(current->pack.data, current->next->pack.data) < 0)
		{
			sorted = 1;
			tmp = (current->pack);
			current->pack = current->next->pack;
			current->next->pack = tmp;
		}
		current = current->next;
		if (current->next == NULL && sorted == 0)
			return ;
		else if (current->next == NULL)
		{
			current = head;
			sorted = 0;
		}
	}
}
