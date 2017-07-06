/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:13:12 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/11 17:17:26 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*word_length(char *s, char c, int word)
{
	int		i;
	int		start;
	int		word_count;

	start = 0;
	word_count = 0;
	i = 0;
	if (s[i] != c)
		word_count++;
	while (word_count < word)
	{
		if (s[i] != c && s[i - 1] == c)
		{
			word_count++;
		}
		start = i;
		i++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;
	return (ft_strsub((char *)s, start, i - start));
}

static int		count_words(char *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		if (s[i] == c || s[i] != c)
			i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**strsplit;
	int		word_count;

	word_count = count_words((char *)s, c);
	strsplit = (char **)ft_memalloc(sizeof(char) * word_count + 1);
	if (strsplit == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		strsplit[i] = word_length(ft_strtrim_delim(s, c), c, i + 1);
		i++;
	}
	strsplit[i] = NULL;
	return (strsplit);
}
