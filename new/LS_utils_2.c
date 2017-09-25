#include "ft_ls.h"

void	init_to_null(DIR **d_ptr, struct dirent **c, t_l **h)
{
	*d_ptr = NULL;
	*c = NULL;
	*h = NULL;
}

void		nl_print_path(char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putendl(":");
}