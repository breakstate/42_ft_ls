/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:50:44 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/10 16:43:53 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	check_flags()
**	verify_flags()
*/

/*
**	check_flags()
**	returns 1 if specified flag is found in flag string
*/

int		check_flags(char *flags, char f)
{
	int		i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == f)
			return (1);
		i++;
	}
	return (0);
}

/*
**	verify_flags()
**	verifies that only these 5 flags are persent in the flag string
*/

int		verify_flags(char *flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] != 'R' && flags[i] != 'r' && flags[i] != 'l'
			&& flags[i] != 'a' && flags[i] != 't')
		{
			ft_putstr("ft_ls: ");
			ft_putstr("invalid option -- '");
			ft_putchar(flags[i]);;
			ft_putstr("'\n");
			return (0);
		}
		i++;
	}
	return (1);
}
