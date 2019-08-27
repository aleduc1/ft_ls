/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:18:14 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/21 17:32:52 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <grp.h>
# include <time.h>
# include <pwd.h>
# include "libft/libft.h"

typedef struct		s_var
{
	int				len_usr;
	int				len_grp;
	int				len_oct;
	int				len_lnk;
	int				len_maj;
	int				len_min;
	int				len_lk;
	int				len_oc;
	int				len_us;
	int				len_gp;
	int				len_ma;
	int				len_mi;
	int				len_l;
	int				len_o;
	int				len_u;
	int				len_g;
	int				len_m1;
	int				len_m2;
	int				flag;
	unsigned long	total;
	int				total_flag;
}					t_var;

typedef struct		s_struct
{
	char			*path;
	char			*name;
	char			*types;
	char			*mode;
	int				nlinks;
	char			*proprio;
	char			*groupe;
	int				size;
	unsigned long	blocks;
	char			*date;
	int				timestamp;
	unsigned int	minor;
	unsigned int	major;
	int				flag_dev;
}					t_struct;

typedef struct		s_btree_av
{
	struct s_btree_av	*left;
	struct s_btree_av	*right;
	char				*names;
}					t_btree_av;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	t_struct		*data;
}					t_btree;

typedef struct		s_norm
{
	char		*options;
	t_btree		*root;
	t_btree_av	*dir_order;
	int			i;
	int			j;
	int			argnbr;
}					t_norm;

typedef struct		s_dir
{
	DIR				*pdir;
	struct dirent	*pent;
	char			*path;
	char			*tmpp;
	int				i;
	t_struct		*info_bis;
	t_btree			*root_file;
}					t_dir;

typedef struct		s_dir_r
{
	DIR				*pdir;
	struct dirent	*pent;
	char			*path;
	int				i;
	int				flagcpy;
	int				loopcpy;
	t_struct		*info_bis;
	t_btree			*root_file;
	t_list			*list;
	t_list			*head;
}					t_dir_r;

int					check_total(t_btree *root, t_var **var);
void				put_devs(struct stat *buff, t_struct **data);
void				put_types(struct stat *buff, t_struct **data);
void				put_modes(struct stat *buff, t_struct **data);
void				put_data(struct stat *buff, t_struct **data, char *path, \
		char *name);
int					put_uids(struct stat *buff, struct passwd **pwd, \
		struct group **grp);
void				set_dir_r_var(t_dir_r **dr, int flag, int loop);
void				error_r(char *filename, t_dir_r **dr);
int					filename_fct_r(t_dir_r **dr, t_norm **n, int dirnb, \
		char *filename);
void				insert_fcts(t_norm **n, t_dir_r **dr);
void				reading_fct_r(t_dir_r **dr, t_norm **n, char *filename);
void				half_r(t_dir_r **dr, t_norm **n, char *filename);
void				set_dir_var(t_dir **d);
void				error(t_dir **d, char *filename);
void				filename_fct(t_norm **n, int dirnb, int flag, \
		char *filename);
void				insert_fct(t_norm **n, t_dir **d);
void				reading_fct(t_dir **d, t_norm **n, char *filename);
void				insert_file(t_norm **n, t_struct **info);
int					call_stat(char *str, t_struct **info);
int					half_ls(t_norm **n, char *str, t_struct **info, int *flag);
void				scd_half(t_norm **n, int *flag);
int					ft_ls_r(char *str, t_norm **n, int *flag, int *loop);
int					ft_fill(char c, char *options);
int					ft_check(char *str, char *options);
void				set_var(t_norm **n);
int					one_ac_main(t_norm **n);
int					main_two(t_norm **n);
void				call_opt_la(t_btree **root);
void				call_opt_l(t_btree **root);
void				call_opt_fla(t_btree **root);
void				call_opt_fl(t_btree **root);
int					ft_opts(char *str, t_norm **n);
void				ft_error(int error, char *str);
int					ft_ls(char *str, t_norm **n);
int					ft_ls_btree(t_btree_av **dir_order, t_norm **n);
void				ft_ret(int nb, t_norm **n);
int					ft_stat(char *path, t_struct **data, char *name);
int					ft_types(t_struct **info);
char				*create_path(char *filename, char *name);
void				ft_path(char *name, t_list **alst);
void				ft_path2(char *filename, t_list **alst, t_btree **root,\
		char *options);
void				ft_args(int ac, char **av, t_norm **n);
int					ft_argnbr(t_btree_av **dir_order);
void				ft_sort(char *str, t_norm **n);
int					dir_sort(const char *s1, const char *s2);
int					dir_sort_r(const char *s1, const char *s2);
int					opt_r(const char *s1, const char *s2);
int					ft_isdir(const char *file);
t_btree				*btree_create_node(void *info);
t_btree_av			*btree_create_node_av(char *names);
void				ft_dir(char *filename, t_norm **n, int flag);
void				ft_dir_r(char *filename, t_norm **n, int flag, int loop);
void				ft_putendl_lst(t_list *lst);
void				btree_insert_data(t_btree **root,\
		t_struct *info, int (*cmpf)(const char*, const char*));
void				btree_insert_data_t(t_btree **root,\
		t_struct *info, int (*cmpf)(t_struct*, t_struct*));
void				btree_insert_data_av(t_btree_av **root,\
		char *str, int (*cmpf)(const char*, const char*));
void				display_data(t_btree *root, char *options);
void				display_data_2(t_btree *root, char *options);
void				display_data_file(t_btree *root, char *options);
void				display_data_file_2(t_btree *root, char *options);
void				btree_apply_infix_date(t_btree *root);
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix_a(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix_av(t_btree_av *root,\
		void (*applyf)(void *));
int					opt_t(t_struct *inb3, t_struct *wr2put);
int					comp_t(t_struct *n1, t_struct *n2);
int					opt_rt(t_struct *inb3, t_struct *wr2put);
int					is_dot(char *str);
int					is_dot_2(char *str, char *options);
void				clean_three(t_btree **root);
void				clean_list(t_list *list);
void				clean_three_av(t_btree_av **root);
void				free_info(t_struct **info);
void				btree_apply_infix_l(t_btree *root, t_var **var);
void				btree_apply_infix_la(t_btree *root, t_var **var);
void				btree_apply_infix_fl(t_btree *root, t_var **var);
void				btree_apply_infix_fla(t_btree *root, t_var **var);
void				reset_var(t_var **var);
void				opt_l(t_struct *data, t_var **var);
void				second_half_l(t_struct **data, t_var **var);
void				first_half_l(t_struct **data, t_var **var);
unsigned long		print_total(t_btree *root, t_var **var);
unsigned long		print_total_a(t_btree *root, t_var **var);
int					print_types(char *str);
void				print_types_short(int *ptr);
void				print_link(char *type, char *path);
void				print_time(t_struct *data);
int					current_time(int nbr);
void				print(char *str);
void				print_n(int nbr);
void				print_whitespace(void);
void				print_whitespaces(void);
void				print_newline(void);
void				apply_padding(int maxlen, char *str);
void				apply_padding_nbr(int maxlen, int nbr);
int					maxlen_grp(t_btree *root, t_var **var);
int					maxlen_grp_a(t_btree *root, t_var **var);
int					maxlen_usr(t_btree *root, t_var **var);
int					maxlen_usr_a(t_btree *root, t_var **var);
int					maxlen_oct(t_btree *root, t_var **var);
int					maxlen_oct_a(t_btree *root, t_var **var);
int					maxlen_lnk(t_btree *root, t_var **var);
int					maxlen_lnk_a(t_btree *root, t_var **var);
int					maxlen_maj(t_btree *root, t_var **var);
int					maxlen_maj_a(t_btree *root, t_var **var);
int					maxlen_min(t_btree *root, t_var **var);
int					maxlen_min_a(t_btree *root, t_var **var);
int					len_grp(char *str, t_var **var);
int					len_usr(char *str, t_var **var);
int					len_oct(int nbr, t_var **var);
int					len_lnk(int nbr, t_var **var);
int					len_min(int nbr, t_var **var);
int					len_maj(int nbr, t_var **var);
int					ft_nbrlen(int nb);
void				do_total(t_btree *root, t_var **var);
#endif
