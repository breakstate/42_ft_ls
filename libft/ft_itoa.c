/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:42:30 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/27 14:30:07 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_abs(int num)
{
	int sign;

	sign = 1;
	printf("ft_abs in = %d\n", num);
	if (num < 0)
	{
		num = num * -1;
	}
	printf("ft_abs = %d\n", num);
	return (num);
}


static int		digit_count(int n)
{
	int		num;
	int 	i;

	i = 0;
	num = n;
	if (n <= 0)
	{
		i++;
		num = -n;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int dc(int n)
{
	if (n < 0)
	{
		return (n > -10) ?  2: 1 + dc(n/10);
	}
	return (n < 10) ? 1 : 1 + dc(n/10) ;
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		mod;
	int		sign;
	int		div;

	i = dc(n);
	num = ft_strnew(i);
	printf("n = %d, i = %d\n", n, i);
	if (n < 0)
	{
		sign = -1;
		//n *= sign;
	}
	//mod = ft_abs(n % 10);
	while (i-- >= 0)
	{
		mod = ft_abs(n % 10);
		if (n < 10 && n > -10)
		{
			num[i] = ft_abs(n) + '0';
			printf("---if---\n");
		}
		else if (mod < 10)
		{
			num[i] = mod + '0';
			printf("---else---\n");
		}
		//mod = ft_abs(n % 10);
		n = (n / 10);
		printf("num[%d] = %c\n", i, num[i]);
	}
	if (sign < 0)
		num[0] = '-';
	return (num);
}

int main()
{
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}
//int min -2147483648
