/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 12:50:05 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/06 15:20:39 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include "./libft/includes/libft.h"

typedef struct	s_flags{
	char *flags;
}				t_flags;

int ft_isdir(char *path)
{
	DIR *dp;
	dp = opendir(path);
	printf("\n\n\n||ft_isdir [%s] ", path);
	if (dp == NULL)
	{
		printf("= null.\n");
		return (0);
	}
	printf("!= null.\n\n\n");
	return (1);
}
/*
int	check_flag(char n)//needs to receive flag string
{
	if (strchr(t_flags->flags, n))
		return (1);
	return (0);
}
*/
void printdir(char *path)
{
	DIR				*dir_ptr;
	struct dirent	*curr_dir;
	struct stat		statbuf;

	printf("recursing with [%s]\n", path);

	dir_ptr = opendir(path);
	if (dir_ptr == NULL)
	{
		printf("Cannot open directory. [%s]\n", path);
	}
	else
		printf("I was able to enter [%s]\n", path); 
	




	printf("pre while\n");
	//if (dir_ptr)
		while ((dir_ptr)) //!= NULL && dir_ptr != NULL)//reads into dirent struct
		{
			curr_dir = readdir(dir_ptr);
			printf("post while\n");
			lstat(curr_dir->d_name, &statbuf);//reads into stat struct
			printf("d_name = %s\n", curr_dir->d_name);
				if /*(dir_ptr != NULL)*/(ft_isdir(path))
			{
				printf("IS folder, path = [%s]\n", curr_dir->d_name);
				if (curr_dir->d_name[0] != '.')
				{
					printf("d_name = %s\n", curr_dir->d_name);
						if (dir_ptr == NULL)
						printf("I'm going in anyway, you're not my read dad.\n");
					path = ft_strjoin(ft_strjoin(path, "/"), curr_dir->d_name);
					printf("path just before recurse [%s]\n", path);
					printdir(path);
				}
			}
			else
			{
				printf("NOT folder\n");
				printf("%s\n", curr_dir->d_name);
			}
		}
}

int main()
{
	printf("_______________________________START_______________________________\n");
	printdir(".");
	return (0);
}
