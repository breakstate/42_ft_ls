/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:37:41 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/07 17:48:29 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

t_list	*create_elem(char *data)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp != NULL)
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}

void	list_add_back(t_list **head, char *data)
{
	t_list *current;
	current = *head;

	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = create_elem(data);
	}
	else
		*head = create_elem(data);
}

void	print_list(t_list *head)
{
	t_list *current;

	current = head;
	while (current != NULL)
	{
		ft_putstr(current->data);
		ft_putchar('\n');
		current = current->next;
	}
}

void	sort_list(t_list *head)
{
	int		sorted;
	t_list	*current;
	char	*tmp;

	current = head;
	while (current->next->next)
	{
		if (ft_strcmp(current->data, current->next->data) > 0)
		{
			sorted = 1;
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
		}
		current = current->next;
		if (current->next->next == NULL && sorted == 0)
			return;
		else if (current->next->next == NULL)
		{
			current = head;
			sorted = 0;
		}
	}
}
