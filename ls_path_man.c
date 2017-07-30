//ls_path_man.c

#include "ft_ls.h"

/*
**	temp_path()
**	gives makes temporary path string for recrsive reading
*/

char		*temp_path(char *path, char *d_name)
{
	return (ft_strjoin(ft_strjoin(path, "/"), d_name));
}

/*
**	append_path()
**	might actually be redundant
**	changes actual path string
*/

char		*append_path(char *path, char *new_path)
{
	path = ft_strjoin(ft_strjoin(path, "/"), new_path);
	return (path);
}

/*
**	dir_reset()
**	resets the pointer dir_ptr
*/

void		dir_reset(DIR **dir_ptr, char *path)
{
	closedir(*dir_ptr);
	*dir_ptr = opendir(path);
}