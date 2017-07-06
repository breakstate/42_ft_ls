/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:03:12 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/11 17:23:27 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_delim(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		while (s[i] == c)
		{
			i++;
			if (i == (int)ft_strlen(s))
				return ("");
		}
		j = (ft_strlen(s) - 1);
		while (s[j] == c)
			j--;
		j = j - i + 1;
		return (ft_strsub(s, i, j));
	}
	return (NULL);
}
