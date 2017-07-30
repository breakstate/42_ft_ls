#include "ft_ls.h"

/*
**	read_list_R(
**	reads contents of dir recursively
**	when -R flag is present
*/

void	read_list_R(t_lslist *head, char *path, char *flags)
{
	t_lslist	*current;
	char		*temp;

	current = head;
	while (current != NULL)
	{
		temp = temp_path(path, current->data);
		if ((opendir(temp)) != NULL && (!(is_dot((current->data))))) //current->data[0] != '.')
		{
			ft_putchar('\n');
			ls_print(temp_path(path, current->data), flags);
		}
		current = current->next;
	}
}
