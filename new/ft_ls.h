/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:54:18 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/10 16:53:36 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include "./libft/includes/libft.h"
# include "ft_ls.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>

# define node data, stats = get_stats(&statbuf), statbuf.st_mtime, flags

typedef struct		s_pack
{
	char			*data;
	char			*stats;
	time_t			mtime;
	char			*path;
}					t_pack;

typedef struct		s_lslist
{
	t_pack			pack;
	//char			*data;
	//char			*stats;
	//time_t			mtime;

	/* :::TO ADD::: (for sorting)
	int		block; ()st_block
	char	date/time;
	*/
	struct s_lslist	*next;
}					t_lslist;

typedef t_lslist	t_l;

t_lslist			*create_elem(char *data, char *stats, time_t mtime, char *flags);
void				list_add_back(t_lslist **head, char *data, char *path, char* flags);//, char *flags);
void				print_list(t_lslist *head, char *flags);//, struct stat *statbuf);//added statbuff
void				sort_list(t_lslist *head);//, char *flags);
void				sort_list_r(t_lslist *head);
void				free_list(t_lslist **head);
void				read_list_r(t_lslist *head, char *path, char *flags);
char				*temp_path(char *path, char *d_name);
char				*append_path(char *path, char *new_path);
void				ls_loop(char *path, char *flags);
void				cleanup(t_l **head, char *path, char *flags);//, struct stat *statbuf);//added statbuf
void				dir_reset(DIR **dir_ptr, char *path);
int					is_dot(char *d_name);
int					is_hidden(char *d_name);
void				print_path(char *path);
void				list_rev(t_lslist **head);
char				*get_stats(struct stat *statbuf);
char				*get_perms(struct stat *statbuf);
char				*get_nlinks(struct stat *statbuf);
char				*get_usr_grp(struct stat *statbuf);
char				*get_mtime(struct stat *statbuf);
char				**handle_args(int argc, char **argv, char **flags);
int					check_flags(char *flags, char f);
char				*get_flags(int argc, char **argv, char **flags);
char				**no_args();
char                **handle_flags(int argc, char **argv, char **flags, char **args);
int                 verify_flags(char *flags);
char	*get_size(struct stat *stabuf);
void		sort_controller(t_lslist *head, char *flags);
void		sort_list_time(t_lslist *head);
int		not_empty_dir(char *path);
void	init_to_null(DIR **d_ptr, struct dirent **c, t_lslist **h);
void		nl_print_path(char *path);

#endif
/*
**	#define	S_ISDIR(m)	((m & 0170000) == 0040000)	
**	okay so is_dir is replaced by the expression in brackets,
**	m is the parameter to be used within the brackets as well.
**	only certain bits will match and result in 40000 when is directory
*/