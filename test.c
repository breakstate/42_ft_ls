/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:50:39 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/06 17:54:55 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include "./libft/includes/libft.h"
#define BUFF_SIZE 1024

typedef struct	s_flags{
	char *flag;
}				t_flags;

int	ft_isdir(int st_mode, char *dirname)
{
	DIR *d;
	d = opendir(dirname);
	if ((d = opendir(dirname)) == NULL) 
		return (0);
	else
		return (1);
	//return(st_mode >= 040000 && st_mode < 060000);
}


void printdir(char *dirname)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	//char *dirname;

	printf("\n\n\n***on recurse, dir = %s***\n\n\n", dirname);
	dp = opendir(dirname);
	if (dp == NULL)
	{
		printf("Cannot open directory\n");
	}
	//stat(entry->d_name, &statbuf);
	
	
	while ((entry = readdir(dp)) != NULL)
	{
		int a = stat(entry->d_name, &statbuf);
//		printf("\n**WHILE**\n");//remove
		printf("d_name %s st_mode - %o\n\n", entry->d_name, statbuf.st_mode);//remove
		if (ft_isdir(statbuf.st_mode, dirname))// || strcmp(entry->d_name, "includes") == 0)
		{
//			printf("\n**IS DIRECTORY**\n");//remove
			if (strcmp(".",entry->d_name) != 0 && strcmp("..",entry->d_name) != 0)// && strcmp(".git", entry->d_name) != 0 )
			{
//				printf("**ISNT . OR ..**\n\n");//remove
				printf("%s-\n", entry->d_name);//entryname
				if (strcmp(entry->d_name, "includes") == 0)
					dirname = ft_strjoin(ft_strjoin(dirname, "/"), entry->d_name);
				else
					dirname = ft_strjoin(ft_strjoin(dirname, "/"), entry->d_name);
				printf("%s-\n\n" , dirname);//dirname
				printdir(dirname);
			}
//			else
//				printf ("BUT IS . OR ..\n");
			//stat(entry->d_name,&statbuf);

		}
		else
		{
//			printf("\n**NOT DIRECTORY**\n");
			printf("%s - %o\n", entry->d_name, statbuf.st_mode);
		}
	}
	closedir(dp);
}




/*
	if((dp = opendir(dir)) == NULL) {
	printf("cannot open directory: %s\n", dir);
	return;
	}
	//chdir(dir);
	while((entry = readdir(dp)) != NULL) 
	{
		if(S_ISDIR(statbuf.st_mode)) 
		{
 Found a directory, but ignore . and .. 
			if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
				lstat(entry->d_name,&statbuf);
			printf("%s/\n",entry->d_name);
 Set new path if file is directory 
			if (ft_sidir())
 Recurse at a new indent level 
			printdir(dirname);
		}
		else printf("%s\n",entry->d_name);
	}
	//chdir("..");
	closedir(dp);
}
*/



int main()//will take args, first arg will be flag string, second will be starting directory
{
/*	DIR *dir_ptr;
	struct dirent *d;
	struct stat statbuf;

	dir_ptr = opendir(".");
	while ((d = readdir(dir_ptr)))
	{
		stat(d->d_name ,&statbuf);
		if (ft_isdir(statbuf.st_mode))
		{
			printf("is dir\n");
		}
		printf("%s\n", d->d_name);
	}*/
	printf("\n________________________________START_________________________________\n");
	printdir(".");
	return (0);
}
