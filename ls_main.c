/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:58:14 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/09 16:56:19 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ls_print()
**	prints the specified current directory 
**	recurses if R is present in flag string
*/

void	ls_print(char *path, char *flags)
{
	DIR				*dir_ptr;
	struct dirent	*cur_dir;
	struct stat		statbuf;
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
			stat(cur_dir->d_name, &statbuf);
			printf("%lu\n", statbuf.st_nlink);
			list_add_back(&head, cur_dir->d_name, flags);
		}
	}
	else
	{
		ft_putstr(path);
		ft_putendl(": No such file or directory bruh");
		return ;
	}
	cleanup(head, &dir_ptr, path, flags, &statbuf);//added statbuf
	if (check_flags(flags, 'R'))
		read_list_r(head, path, flags);
	free_list(head);
}

/*
**	main()
**	initializes args and flags
**	checks if flags are valid
**	sorts args, checks if valid
**	prints contents of dir specified by current arg
*/

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
		ls_print(args[i], flags);
		ft_putstr("\n");
	}
	//free(args);//ubuntu is complaining that this is an invalid pointer being freed
	return (0);
}

