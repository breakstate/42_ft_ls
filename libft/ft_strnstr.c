/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:25:53 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/11 11:08:50 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(little) < 1)
		return ((char *)big);
	while (big[i] && i < (int)len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < (int)len)
		{
			j++;
			if (little[j] == '\0' && (i + j) <= (int)len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
