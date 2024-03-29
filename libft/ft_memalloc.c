/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:07:37 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/07 15:11:55 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
