#include "ft_ls.h"

/*
**	init_to_null()
**	nl_print_path()
*/

/*
**	init_to_null()
**	initializes a few variables to NULL to save lines
*/

void	init_to_null(t_structs *strcts)
{
	(*strcts).dir_ptr = NULL;
	(*strcts).cur_dir = NULL;
	(*strcts).head = NULL;
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