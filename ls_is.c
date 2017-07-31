/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:52:08 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 15:52:13 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
