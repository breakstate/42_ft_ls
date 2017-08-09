/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:08:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/09 15:47:35 by bmoodley         ###   ########.fr       */
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

/*
char		**handle_args(int argc, char **argv, char **flags)
{
	int		n;
	int		j;
	char	**dirs;

	if (argv[1][0] == '-')
	{
		dirs = (char **)malloc((sizeof(char *) * argc - 1));
		*flags = argv[1];
		dirs[argc - 2] = "";
	}
	else
	{
		dirs = (char **)malloc((sizeof(char *) * argc));
		dirs[argc - 1] = "";
	}
	n = 1;
	j = 0;
	while (dirs[j])
	{
		if (!(n == 1 && argv[n][0] == '-'))
		{
			dirs[j++] = argv[n];
			//      j++;
		}
		n++;
	}
	return (dirs);
}
*/

char		**handle_args(int argc, char **argv, char **flags)
{
	char	**args;
	int		i;
	int		j;

	j  = 0;
	if (argv[1][0] == '-')
	{
		i = 2;
		*flags = argv[1];
		args = (char **)malloc(sizeof(char *) * argc - 1);
		while (i + j < argc)
		{
			args[j] = argv[i + j];
			j++;
		}
	}
	else
	{
		i = 1;
		args = (char **)malloc(sizeof(char *) * argc);
		while (i + j < argc)
		{
			args[j] = argv[i + j];
			j++;
		}
	}
	args[j] = 0;
	return (args);
}

char		**no_args()
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 2);
	args[0] = ".";
	args[1] = 0;
	return (args);
}
