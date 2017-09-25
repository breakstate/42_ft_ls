#include "ft_ls.h"

void		sort_controller(t_lslist *head, char *flags)
{
	sort_list(head);
	return ;//debug
	printf("SORT CONTROLLER\n");
	if (check_flags(flags, 'r') == 0 && check_flags(flags, 't') == 0)
	{
		printf("     neither\n");//debug
		sort_list(head);
	}
	else if (check_flags(flags, 'r') && check_flags(flags, 't') == 0)
	{
		printf("     just r\n");//debug
		sort_list_r(head);//needs address
	}
	else if (check_flags(flags, 't') && check_flags(flags, 'r') == 0)
	{
		printf("     just t\n");//debug
		sort_list(head);
		sort_list_time(head);
	}
	else if (check_flags(flags, 'r') && check_flags(flags, 't'))
	{
		printf("     both\n");//debug
		sort_list_time(head);
		sort_list_r(head);
	}
}

void		sort_list_time(t_lslist *head)
{
	int			sorted;
	t_lslist	*current;
	t_pack		tmp;

	current = head;
	while (current->next)
	{
		if ((current->pack.mtime < current->next->pack.mtime))
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
	sorted = 0;
}

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
	sorted = 0;
}

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
	sorted = 0;
}