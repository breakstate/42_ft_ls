//ls_flags.c

#include "ft_ls.h"

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
	}
	return (0);
}

/*
**	verify_flags()
**	verifies that only these 5 flags are persent in the flag string
*/

int		verify_flags(*flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (flag[i] != 'R' || flag[i] != 'r' || flag[i] != 'l' 
			|| flag[i] != 'a' || flag[i] != 't')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
