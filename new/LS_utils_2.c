#include "ft_ls.h"

/*
**	init_to_null()
**	nl_print_path()
*/

/*
**	init_to_null()
**	initializes a few variables to NULL to save lines
*/

void	init_to_null(DIR **d_ptr, struct dirent **c, t_l **h)
{
	*d_ptr = NULL;
	*c = NULL;
	*h = NULL;
}

/*
**	nl_print_path()
**	prints path preceeded by new line char ending in colon
*/

void		nl_print_path(char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putendl(":");
}