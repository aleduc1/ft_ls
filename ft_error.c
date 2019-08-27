/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:35:51 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/18 18:19:39 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(int error, char *str)
{
	if (error == 1)
		ft_putendl("ls: illegal option\nUsage: ls [-Ralrt]");
	if (error == 2)
	{
		ft_putstr("ls: ");
		ft_putstr(str);
		ft_putendl(": No such file or directory");
	}
}

void	clean_three(t_btree **root)
{
	if (!root || !(*root))
		return ;
	if ((*root) && (*root)->left)
		clean_three(&(*root)->left);
	if ((*root) && (*root)->right)
		clean_three(&(*root)->right);
	if ((*root) && (*root)->data)
	{
		if ((*root)->data->path)
			free((*root)->data->path);
		if ((*root)->data->name)
			free((*root)->data->name);
		if ((*root)->data->mode)
			free((*root)->data->mode);
		if ((*root)->data->date)
			free((*root)->data->date);
		(*root)->data->path = 0;
		(*root)->data->name = 0;
		(*root)->data->mode = 0;
		(*root)->data->date = 0;
		free((*root)->data);
		(*root)->data = 0;
		free(*root);
		(*root) = 0;
	}
}

void	scd_half(t_norm **n, int *flag)
{
	if ((*flag) == 0 && (*n)->root)
	{
		display_data((*n)->root, (*n)->options);
		clean_three(&((*n)->root));
		(*flag) = 1;
	}
}

int		ft_ls_r(char *str, t_norm **n, int *flag, int *loop)
{
	t_struct	*info;

	info = ft_memalloc(sizeof(t_struct));
	if (call_stat(str, &info) == 2)
		return (2);
	if (ft_types(&info) == 0)
		insert_file(n, &info);
	else
	{
		scd_half(n, flag);
		ft_dir_r(str, n, (*flag), (*loop));
		free_info(&info);
		loop = 0;
	}
	free(info);
	return (0);
}

int		ft_ls(char *str, t_norm **n)
{
	static int	flag = 0;
	int			loop;
	t_struct	*info;

	loop = 0;
	if ((*n)->options[2] == 0)
	{
		info = ft_memalloc(sizeof(t_struct));
		if (half_ls(n, str, &info, &flag) == 2)
			return (2);
		free(info);
	}
	else
	{
		if (ft_ls_r(str, n, &flag, &loop) == 2)
			return (2);
	}
	return (flag);
}
