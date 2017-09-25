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
	//int	debug = 0;

	current = head;
	while (current != NULL)
	{
		//printf("debug = %d\n", debug++);//debug
		//printf("[]data = |%s|\n", current->pack.data);
		temp = temp_path(path, current->pack.data);
		//printf("[]temp = %s\n", temp);
		//check for hidden?
		if ((opendir(temp)) != NULL && (!(is_dot((current->pack.data)))))//current->data[0] != '.')
		{
			if (not_empty_dir(temp))
			{
				//printf("if\n");
				ft_putchar('\n');
				//printf("--------->%s\n", temp_path(path, current->pack.data));
				ls_loop(temp/*temp_path(path, current->pack.data)*/, flags);
			}
			else
			{
				//printf("else\n");
				ft_putchar('\n');
				ft_putstr(temp);
				ft_putendl(":");
			}
		}
		temp = NULL;
		current = current->next;
	}
	//free_list(head);moved here maybe? not sure if should
	//printf("****NULLED OUT*****\n");	
}
//end condition is empty dir I think so might be infinite looping when last dir sint empty, and not resetting .

void		cleanup(t_lslist *head, /*DIR **dir_ptr, char *path,*/ char *flags)//, struct stat *statbuf)//added statbuf
{
	sort_controller(head, flags);
	if (head)
		print_list(head, flags);
	//dir_reset(dir_ptr, path);
}

void	ls_loop(char *path, char *flags)
{
	DIR				*dir_ptr;
	struct dirent	*cur_dir;
	t_lslist		*head;

	dir_ptr = NULL;
	cur_dir = NULL;
	head = NULL;
	if ((dir_ptr = opendir(path)) != NULL)
	{
		print_path(path);
		while ((cur_dir = readdir(dir_ptr)))
		{
			if (!cur_dir)
				printf("cur_dir = %s\n", cur_dir->d_name);
			list_add_back(&head, cur_dir->d_name, path);
		}
	}
	else
	{
		ft_putstr(path);
		ft_putendl(": No such file or directory bruh");
		return ;
	}
	cleanup(head, /*&dir_ptr, path,*/ flags);
	if (check_flags(flags, 'R') && (cur_dir->d_name) != NULL)
		read_list_r(head, path, flags);
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