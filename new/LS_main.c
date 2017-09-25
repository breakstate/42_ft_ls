#include "ft_ls.h"

/*
**	read_list_R(
**	reads contents of dir recursively
**	when -R flag is present
*/

void	read_list_r(t_lslist *head, char *path, char *flags)
{
	t_lslist	*current;
	char		*temp;
	struct stat	statbuf;
	//int	debug = 0;

	current = head;
	while (current != NULL)
	{
		//printf("debug = %d\n", debug++);//debug
		//printf("[]data = |%s|\n", current->pack.data);
		temp = temp_path(path, current->pack.data);
		stat(temp, &statbuf);//check lstat in print function
		//printf("[]temp = %s\n", temp);
		//check for hidden?
		if (statbuf.st_mode & S_IFDIR /*((opendir(temp)) != NULL */&& (!(is_dot((current->pack.data)))) && !(is_hidden(current->pack.data)))//forced to ignore all hidden files.
		{
			if (not_empty_dir(temp))
			{
				printf("\n\n TEMP = %s\n\n\n", temp);
				ft_putchar('\n');
				//printf("--------->%s\n", temp_path(path, current->pack.data));
				ls_loop(temp/*temp_path(path, current->pack.data)*/, flags);
			}
			else
				nl_print_path(temp);
		}
		temp = NULL;
		current = current->next;
	}
	//free_list(head); HERE IS RIGHT
	//printf nulled out
}

void		cleanup(t_lslist *head, /*DIR **dir_ptr,*/ char *path, char *flags)//, struct stat *statbuf)//added statbuf
{
	
	sort_controller(head, flags);
	if (head)
	{
		print_list(head, flags);
	}
	if (check_flags(flags, 'R'))
	{
		read_list_r(head, path, flags);
	}
	//dir_reset(dir_ptr, path);
}

void	ls_loop(char *path, char *flags)
{
	DIR				*dir_ptr;
	struct dirent	*cur_dir;
	t_lslist		*head;

	init_to_null(&dir_ptr, &cur_dir, &head);
	//if s_isdir here as well? what if you're given a symbolic link
	if ((dir_ptr = opendir(path)) != NULL)
	{
		print_path(path);
		while ((cur_dir = readdir(dir_ptr)))
			list_add_back(&head, cur_dir->d_name, path);
	}
	else
	{
		ft_putstr(path);
		ft_putendl(": No such file or directory bruh");
		return ;
	}
	cleanup(head, /*&dir_ptr,*/ path, flags);
	printf("done?? ");
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

/*
	*_*TO DO*_*

	manage flags in print function
	print function must account for symbolic links
	test sort fuctions thoroughly
	make sure header norms
	test free list
*/