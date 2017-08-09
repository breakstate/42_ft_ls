/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:58:14 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/09 16:34:25 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_putstr(path);
		ft_putendl(": not a valid directory");
		return ;
	}
	cleanup(head, &dir_ptr, path, flags);
	if (check_flags(flags, 'R'))
		read_list_r(head, path, flags);
	free_list(head);
}

int		main(int argc, char **argv)
{
	char **args;
	char *flags;
	int		i;

	i = 0;
	flags = "";
	ft_putendl("-------------------START--------------------");
	if (argc > 1)
	{
		args = handle_args(argc, argv, &flags);
	}
	else
		args = no_args();
	while (args[i])
	{
		ls_print(args[i], flags);
		ft_putstr("\n");
		i++;
	}
	return (0);
}

