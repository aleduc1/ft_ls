/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_btree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:47:56 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/18 18:19:41 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_btree(t_btree_av **dir_order, t_norm **n)
{
	static int	ls_ret = 0;

	if ((*dir_order) && (*dir_order)->left)
		ft_ls_btree(&(*dir_order)->left, n);
	if ((*dir_order) && (*dir_order)->names)
	{
		ls_ret = ft_ls((*dir_order)->names, n);
		if (ls_ret == 2)
		{
			ft_error(2, (*dir_order)->names);
			ls_ret = 0;
		}
	}
	if ((*dir_order) && (*dir_order)->right)
		ft_ls_btree(&(*dir_order)->right, n);
	return (ls_ret);
}

void	ft_dir(char *filename, t_norm **n, int flag)
{
	static int	dirnb = -1;
	t_dir		*d;

	set_dir_var(&d);
	dirnb++;
	if (!(d->pdir = opendir(filename)))
	{
		error(&d, filename);
		free(d->info_bis);
		free(d);
		return ;
	}
	filename_fct(n, dirnb, flag, filename);
	reading_fct(&d, n, filename);
	if (closedir(d->pdir) == -1)
	{
		ft_putendl("closedir a fail");
		exit(0);
	}
	display_data_file(d->root_file, (*n)->options);
	clean_three(&(d->root_file));
	free(d->info_bis);
	free(d);
}

void	insert_file(t_norm **n, t_struct **info)
{
	if ((*n)->options[3] && (*n)->options[4])
		btree_insert_data_t(&((*n)->root), (*info), &opt_rt);
	else if ((*n)->options[3])
		btree_insert_data(&((*n)->root), (*info), &opt_r);
	else if ((*n)->options[4])
		btree_insert_data_t(&((*n)->root), (*info), &opt_t);
	else
		btree_insert_data(&((*n)->root), (*info), &ft_strcmp);
}

int		call_stat(char *str, t_struct **info)
{
	if (ft_stat(str, info, str) == 2)
	{
		free((*info));
		return (2);
	}
	return (0);
}

int		half_ls(t_norm **n, char *str, t_struct **info, int *flag)
{
	if (call_stat(str, info) == 2)
		return (2);
	if (ft_types(info) == 0)
		insert_file(n, info);
	else
	{
		free_info(info);
		if ((*flag) == 0 && (*n)->root)
		{
			display_data((*n)->root, (*n)->options);
			clean_three(&((*n)->root));
			(*flag) = 1;
		}
		ft_dir(str, n, (*flag));
	}
	return (0);
}
