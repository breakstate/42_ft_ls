/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:33:57 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/25 18:34:29 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		ii;
	char	*dup;

	ii = 0;
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s[ii] != '\0')
	{
		dup[ii] = s[ii];
		ii++;
	}
	dup[ii] = '\0';
	return (dup);
}
