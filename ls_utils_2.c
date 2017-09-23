#include "ft_ls.h"

int		is_empty_dir(char *path)
{
	//char *fullpath;
	struct stat statbuf;
	int		nlink;
	
	//fullpath = ft_strjoin(path, ft_strjoin("/", data));
	stat(path, &statbuf);
	if ((nlink = (statbuf.st_nlink)) == 2)
		return (1);
	return (0);
}