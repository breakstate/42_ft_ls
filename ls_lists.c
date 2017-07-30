//ls_lists.c

#include "ft_ls.h"

t_lslist	*create_elem(char *data)
{
	t_lslist *tmp;

	tmp = (t_lslist *)malloc(sizeof(t_lslist));
	if (tmp != NULL)
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}

void	list_add_back(t_lslist **head, char *data, char *flags)
{
	t_lslist *current;

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
		current->next = create_elem(data);
	}
	else
		*head = create_elem(data);
}

void	print_list(t_lslist *head)
{
	t_lslist *current;

	current = head;
	while (current != NULL)
	{
		ft_putendl(current->data);
		current = current->next;
	}
}

void	sort_list(t_lslist *head)
{
	int			sorted;
	t_lslist	*current;
	char		*tmp;

	current = head;
	while (current->next)
	{
		if (ft_strcmp(current->data, current->next->data) > 0)
		{
			sorted = 1;
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
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

void	free_list(t_lslist *head)
{
	t_lslist *current;
	t_lslist *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}
