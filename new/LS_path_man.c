/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_path_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:13:15 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:13:24 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	temp_path()
**	dir_reset()
**	is_dot()
**	is_hidden()
*/

/*
**	temp_path()
**	gives makes temporary path string for recrsive reading
*/

char		*temp_path(char *path, char *d_name)
{
	if (path[ft_strlen(path) - 1] != '/')
		return (ft_strjoin(ft_strjoin(path, "/"), d_name));
	else
		return (ft_strjoin_f(path, d_name));	
}

/*
**	dir_reset()
**	resets the pointer dir_ptr
*/

void		dir_reset(DIR **dir_ptr, char *path)
{
	closedir(*dir_ptr);
	*dir_ptr = opendir(path);
}

/*
**	is_dot()
**	checks if dirname is "." or ".."
*/

int		is_dot(char *d_name)
{
	if (ft_strcmp(d_name, ".") == 0)
		return (1);
	else if (ft_strcmp(d_name, "..") == 0)
		return (1);
	else
		return (0);
}

/*
**	is_hidden()
**	checks if file/dir is hidden (starts with '.')
*/

int		is_hidden(char *d_name)
{
	if (d_name[0] == '.')
		return (1);
	return (0);
}