#include "ft_ls.h"

void		sort_controller(t_lslist *head, char *flags)
{
	if not r & not t
		call normal sort 
	else if r & not t 
		call sort r 
	else if t & not r 
		call sort t 
	else if t & r 
		call t then r
}

void		sort_list_time(t_lslist *head)
{
	int			sorted;
	t_lslist	*current;
	t_pack		tmp;

	current = head;
	while (current->next)
	{
		if ((current->pack.mtime > current->next->pack.mtime))
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