//ls_utils.c

#include "ft_ls.h"

/*
 **	cleanup()
 **	calls other functions to save lines
 */

void	cleanup(t_lslist *head, DIR **dir_ptr, char *path)
{
	sort_list(head);
	print_list(head);
	dir_reset(dir_ptr, path);
	//	read_list(head, path);
	//	free_list(head);
}

/*
 **	print_path()
 **	prints path, saves lines
 */

void	print_path(char *path)
{
	ft_putstr(path);
	ft_putendl(":");
}

/*
**	handle_args()
**	splits args up and assigns flag string
*/

char    **handle_args(int argc, char **argv, char **flags)
{
	int     n;
	int     j;
	char    **dirs;

	if (argv[1][0] == '-')
	{
		dirs = (char **)malloc((sizeof(char *) * argc - 1));
		*flags = argv[1];
		dirs[argc - 2] = "";
	}
	else
	{
		dirs = (char **)malloc((sizeof(char *) * argc));
		dirs[argc - 1] = "";
	}
	n = 1;
	j = 0;
	while (dirs[j])
	{
		if (!(n == 1 && argv[n][0] == '-'))
		{
			dirs[j++] = argv[n];
			//      j++;
		}
		n++;
	}
	return (dirs);
}

