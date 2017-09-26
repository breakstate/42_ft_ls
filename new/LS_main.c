#include "ft_ls.h"

/*
**	read_list_R(
**	reads contents of dir recursively
**	when -R flag is present
*/

void	read_list_r(t_lslist *current, char *path, char *flags)
{
	char		*fullpath;
	struct stat	statbuf;

	while (current != NULL)
	{
		fullpath = temp_path(path, current->pack.data);
		lstat(fullpath, &statbuf);
		if (statbuf.st_mode & S_IFDIR && !is_dot(current->pack.data))
		{
			if (not_empty_dir(fullpath))
			{
				ft_putchar('\n');
				ls_loop(fullpath, flags);
			}
			else
				nl_print_path(fullpath);
		}
		free(fullpath);
		current = current->next;
	}
}

void		cleanup(t_lslist **head, char *path, char *flags)
{
	
	sort_controller(*head, flags);
	if (head)
	{
		print_list(*head, flags);
	}
	if (check_flags(flags, 'R'))
	{
		read_list_r(*head, path, flags);
	}
	free_list(head);
}

void	ls_loop(char *path, char *flags)
{
	DIR				*dir_ptr;
	struct dirent	*cur_dir;
	t_lslist		*head;

	init_to_null(&dir_ptr, &cur_dir, &head);
	if ((dir_ptr = opendir(path)) != NULL)
	{
		print_path(path);
		while ((cur_dir = readdir(dir_ptr)))
			list_add_back(&head, cur_dir->d_name, path, flags);
	}
	else
	{
		ft_putstr(path);
		ft_putendl(": No such file or directory bruh");
		return ;
	}
	cleanup(&head, path, flags);
	closedir(dir_ptr);
}

int		main(int argc, char **argv)
{
	char **args;
	char *flags;
	int		i;

	i = -1;
	flags = "";
	ft_putendl("-------------------START--------------------");
	if (argc > 1)
	{
		args = handle_args(argc, argv, &flags);
		if (args == 0)
			return (0);
	}
	else
		args = no_args();
	//sort args
	//check if args are valid (prints invalid first)
	while (args[++i])
	{
		ls_loop(args[i], flags);
		ft_putstr("\n");
	}
	//free(args);//ubuntu is complaining that this is an invalid pointer being freed
	return (0);
}