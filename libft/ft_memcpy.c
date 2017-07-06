/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:14:18 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/06 11:13:27 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = dst;
	s = (char *)src;
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	dst = (void *)d;
	return (dst);
}
