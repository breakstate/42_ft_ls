#include "ft_ls.h"

/*
**	read_list_R(
**	reads contents of dir recursively
**	when -R flag is present
*/

void	read_list_r(t_structs *s, char *path, char *flags)
{
	char		*fullpath;
	struct stat	statbuf;
	t_lslist *current;

	current = (*s).head;
	while (current != NULL)
	{
		printf("current pack data = %s\n", current->pack.data);
		fullpath = temp_path(path, current->pack.data);
		lstat(fullpath, &statbuf);
		if (statbuf.st_mode & S_IFDIR && !is_dot(current->pack.data))
		{
			if (not_empty_dir(fullpath))
			{
				ft_putchar('\n');
				ls_loop(fullpath, flags, s);
			}
			else
				nl_print_path(fullpath);
		}
		free(fullpath);
		current = current->next;
	}
}


void	ls_loop(char *path, char *flags, t_structs *s)
{
	if ((s->dir_ptr = opendir(path)) != NULL)
	{
		print_path(path);
		while ((s->cur_dir = readdir(s->dir_ptr)))
		list_add_back(&s->head, s->cur_dir->d_name, path, flags);
	}
	else
	{
		ft_putstr(path);
		ft_putendl(": No such file or directory bruh");
		return ;
	}
	closedir(s->dir_ptr);
}

void	controller(char *path, char *flags)
{
	t_structs	s;
	
	init_to_null(&s);
	ls_loop(path, flags, &s);
	sort_controller(s.head, flags);
	print_list(s.head, flags);
	if (check_flags(flags, 'R'))
	{
		read_list_r(&s, path, flags);
	}
	//free_list(&s.head);
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
		controller(args[i], flags);
		ft_putstr("\n");
	}
	//free(args);//ubuntu is complaining that this is an invalid pointer being freed
	return (0);
}