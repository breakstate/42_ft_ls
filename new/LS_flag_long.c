/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:09:42 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:09:50 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//lstat populates statbuf which gets passed to a function that puts together a string of
//all attributes collated from a bunch of other functions.

#include "ft_ls.h"

char	*get_stats(struct stat *statbuf)//might need temp or freeing funciton
{
	char	*stats;
	char	*str;
	stats = (char *)malloc(sizeof(char) * 1);
	stats[0] = '\0';
	stats = ft_strjoin_f(stats, ft_strjoin(" ", str = get_perms(statbuf)));
	free(str);
	stats = ft_strjoin_f(stats, ft_strjoin(" ", str = get_nlinks(statbuf)));
	free(str);
	stats = ft_strjoin_f(stats, ft_strjoin(" ", str = get_usr_grp(statbuf)));
	free(str);
	stats = ft_strjoin_f(stats, ft_strjoin(" ", str = get_size(statbuf)));
	free(str);
	stats = ft_strjoin_f(stats, ft_strjoin("\t", str = get_mtime(statbuf)));
	stats = ft_strjoin_f(stats, " ");
	free(str);
	return (stats);
}

char	*get_perms(struct stat *statbuf)
{
	char *perms;
	
	perms = (char *)malloc(sizeof(char) * 11);
	perms[0] = (statbuf->st_mode & S_IFSOCK) ? 's' : '-';
	perms[0] = (statbuf->st_mode & S_IFIFO) ? 'p' : '-';
	perms[0] = (statbuf->st_mode & S_IFCHR) ? 'c' : '-';
	perms[0] = (statbuf->st_mode & S_IFBLK) ? 'b' : '-';
	perms[0] = (statbuf->st_mode & S_IFLNK) ? 'l' : '-';
	perms[0] = (statbuf->st_mode & S_IFDIR) ? 'd' : '-';
	perms[1] = (statbuf->st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (statbuf->st_mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (statbuf->st_mode & S_IXUSR) ? 'x' : '-';
	perms[4] = (statbuf->st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (statbuf->st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (statbuf->st_mode & S_IXGRP) ? 'x' : '-';
	perms[7] = (statbuf->st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (statbuf->st_mode & S_IWOTH) ? 'w' : '-';
	perms[9] = (statbuf->st_mode & S_IXOTH) ? 'x' : '-';
	perms[10] = '\0';
	return (perms);
}

char	*get_nlinks(struct stat *statbuf)
{
	char	*nlink;
	char	*new_nlink;
	int		len;
	int		i;

	i = 2;
	nlink = ft_itoa(statbuf->st_nlink);//free since itoa uses malloc!
	len = ft_strlen(nlink);
	new_nlink = ft_memalloc(sizeof(char) * 4);
	ft_memset((void*)new_nlink, ' ', 3);
	while (len > 0)
	{
		new_nlink[i] = nlink[len - 1];
		i--;
		len--;
	}
	free(nlink);
	return (new_nlink);
}

char	*get_usr_grp(struct stat *statbuf)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(statbuf->st_uid);
	grp = getgrgid(statbuf->st_gid);
	return ((char *)ft_strjoin(ft_strjoin(pwd->pw_name, "  "), grp->gr_name));
}

char	*get_mtime(struct stat *statbuf)
{
	char	*mtime;

	mtime = ft_strsub(ctime(&statbuf->st_mtime), 4, 12);
	return (mtime);
}
