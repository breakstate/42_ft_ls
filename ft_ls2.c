typedef struct s_ll{
	char	*perm;
	int		hrdlnks;
	char	*owner;
	char	*group;
	int		size;
	int		time;//not sure of type
	char	*name;
}				t_ll;

int main()
{
	DIR *dir_ptr;
	struct dirent *entry;
	struct stat statbuf;

	dir_ptr - opendir(".");
	while ((d = readdir(dir_ptr)))
	{
		stat(entry->d_name, &statbuf);
		
	}
}

