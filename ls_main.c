/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:58:14 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:14:36 by bmoodley         ###   ########.fr       */
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
		ft_putendl(path);
		return ;
	}
	cleanup(head, &dir_ptr, path, flags);
	if (check_flags(flags, 'R'))
		read_list_r(head, path, flags);
	free_list(head);
}

int		main(int argc, char **argv)
{
	ft_putendl("-------------------START--------------------");
	ls_print(".", argv[argc - 1]);
	return (0);
}

