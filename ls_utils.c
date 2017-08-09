/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:08:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/09 16:30:04 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	cleanup()
**	calls other functions to save lines
*/

void		cleanup(t_lslist *head, DIR **dir_ptr, char *path, char *flags)
{
	sort_list(head, flags);
	print_list(head);
	dir_reset(dir_ptr, path);
	//	read_list(head, path);
	//	free_list(head);
}

/*
**	print_path()
**	prints path, saves lines
*/

void		print_path(char *path)
{
	ft_putstr(path);
	ft_putendl(":");
}

/*
**	handle_args()
**	splits args up and assigns flag string
*/

char		**handle_args(int argc, char **argv, char **flags)
{
	char	**args;
	int		i;
	int		j;

	j  = -1;
	i = 2;
	if (argv[1][0] == '-')
	{
		*flags = argv[1];
		args = (char **)malloc(sizeof(char *) * argc - 1);
		while (i + ++j < argc)
			args[j] = argv[i + j];
	}
	else
	{
		args = (char **)malloc(sizeof(char *) * argc);
		while ((i - 1) + ++j < argc)
			args[j] = argv[(i - 1) + j];
	}
	args[j] = 0;
	return (args);
}

char		**no_args(void)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 2);
	args[0] = ".";
	args[1] = 0;
	return (args);
}
