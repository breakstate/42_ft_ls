//file to handle all padding
#include "ft_ls.h"

char	*get_size(struct stat *statbuf)
{
	char	*size;
	size = ft_itoa(statbuf->st_size);//free since itoa uses malloc!
	return (size);
}