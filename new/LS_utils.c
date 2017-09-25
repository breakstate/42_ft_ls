/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:08:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/10 16:53:34 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		not_empty_dir(char *path)
{
	int		i;
	DIR		*dir_ptr;
	struct dirent	*cur_dir;

	dir_ptr = NULL;
	cur_dir = NULL;
	i = 0;
	if ((dir_ptr = opendir(path)))
	{
		while ((cur_dir = readdir(dir_ptr)))
			i++;
		closedir(dir_ptr);
	}
	return (i);
	/*
	//char *fullpath;
	struct stat statbuf;
	int		nlink;
	
	//fullpath = ft_strjoin(path, ft_strjoin("/", data));
	stat(path, &statbuf);
	if ((nlink = (statbuf.st_nlink)) == 2)
		return (1);
	return (0);
	*/
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
**	calls verify_flags()
*/

char		**handle_args(int argc, char **argv, char **flags)
{
	char	**args;
	int		i;
	int		j;

	j  = -1;
	i = 2;
    args = NULL;
	if (argv[1][0] == '-')
	{
        args = handle_flags(argc, argv, flags, args);
        if (!(verify_flags(*flags)))
			return (0);//should return NULL if a flag is invalid
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

/*
**	handle_flags()
**	finds each flag arg and appends them to flag string until non flag arg found
**	any flag after that treated as dir and will be shown as erroneous
*/

char		**handle_flags(int argc, char **argv, char **flags, char **args)
{
	int		i;
    int     j;
	char	*new;

	new = "";
    j = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-')
   	{
    	new = ft_strjoin(new, argv[i] + 1);
    	*flags = new;
        i++;
   	}
	if (i == argc)
		return (no_args());//returns "." if no dir specified
    args = (char **)malloc(sizeof(char *) * (argc - (--i - 1)));// malloc one extra
	i++;
    while (i + j < argc)
    {
        args[j] = argv[i + j];
        j++;
    }
    args[j] = 0;
    return (args);
}

/*
**	no_args()
**	sets null terminated 2d array with first arg as "." (current dir)
*/

char		**no_args(void)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 2);
	args[0] = ".";
	args[1] = 0;
	return (args);
}
