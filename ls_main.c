//ls_main.c

#include "ft_ls.h"

void	ls_print(char *path, char *flags)
{
	DIR				*dir_ptr;
	struct dirent	*cur_dir;
	//struct stat	*statbuf;
	t_lslist		*head;

	dir_ptr = NULL;
	cur_dir = NULL;
	//statbuf = NULL;
	head = NULL;
	if ((dir_ptr = opendir(path)) != NULL)
	{
		print_path(path);
		while ((cur_dir = readdir(dir_ptr)))
		{
			//statbuf(cur_dir->d_name, statbuf);
			list_add_back(&head, cur_dir->d_name, flags);
		}
	}
	else
	{
		ft_putendl(path);
		return ;
	}
	cleanup(head, &dir_ptr, path);
	if (check_flags(flags, 'R'))
		read_list_R(head, path, flags);
	free_list(head);
}

int		main()
{
	ft_putendl("-------------------START--------------------");
	ls_print("..", "R");
	return (0);
}

