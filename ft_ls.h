/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:54:18 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/31 16:28:56 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <string.h>
# include "./libft/includes/libft.h"
# include "ft_ls.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>

typedef struct		s_lslist
{
	char			*data;
	struct s_lslist	*next;
}					t_lslist;

typedef t_lslist	t_l;

t_lslist			*create_elem(char *data);
void				list_add_back(t_lslist **head, char *data, char *flags);
void				print_list(t_lslist *head);
void				sort_list(t_lslist *head, char *flags);
void				sort_list_r(t_lslist *head);
void				free_list(t_lslist *head);
void				read_list_r(t_lslist *head, char *path, char *flags);
char				*temp_path(char *path, char *d_name);
char				*append_path(char *path, char *new_path);
void				ls_print(char *path, char *flags);
void				cleanup(t_l *head, DIR **dir_ptr, char *path, char *flags);
void				dir_reset(DIR **dir_ptr, char *path);
int					is_dot(char *d_name);
int					is_hidden(char *d_name);
void				print_path(char *path);
void				list_rev(t_lslist **head);
void				get_stats(struct stat *statbuf);
char				*get_perms(struct stat *statbuf);
char				*get_nlinks(struct stat *statbuf);
char				*get_usr_grp(struct stat *statbuf);
char				*get_mtime(struct stat *statbuf);
char				**handle_args(int argc, char **argv, char **flags);
int					check_flags(char *flags, char f);

#endif
