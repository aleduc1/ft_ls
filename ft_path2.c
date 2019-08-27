/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:40:11 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/21 17:37:38 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*create_path(char *filename, char *name)
{
	char	*path;
	char	*tmp;

	if (ft_strcmp(filename, "/") != 0)
	{
		path = ft_strjoin(filename, "/");
		tmp = path;
		path = ft_strjoin(path, name);
		free(tmp);
	}
	else
		path = ft_strjoin(filename, name);
	return (path);
}

void	ft_path2(char *filename, t_list **alst, t_btree **root, char *options)
{
	char	*path;

	path = NULL;
	if ((*root) && (*root)->left)
		ft_path2(filename, alst, &(*root)->left, options);
	if ((*root) && (*root)->data)
	{
		if (ft_strcmp((*root)->data->types, "Dossier") == 0)
		{
			if (!(is_dot_2((*root)->data->name, options)))
			{
				path = create_path(filename, (*root)->data->name);
				ft_path(path, alst);
				free(path);
			}
		}
	}
	if ((*root) && (*root)->right)
		ft_path2(filename, alst, &(*root)->right, options);
}

void	reading_fct_r(t_dir_r **dr, t_norm **n, char *filename)
{
	while (((*dr)->pent = readdir((*dr)->pdir)))
	{
		if ((*dr)->pent == NULL)
		{
			perror("Readdir failed");
			exit(1);
		}
		(*dr)->path = create_path(filename, (*dr)->pent->d_name);
		if (ft_stat((*dr)->path, &((*dr)->info_bis), (*dr)->pent->d_name) == 2)
		{
			ft_memdel((void**)&((*dr)->path));
			return ;
		}
		insert_fcts(n, dr);
		ft_memdel((void**)&((*dr)->path));
	}
}

void	half_r(t_dir_r **dr, t_norm **n, char *filename)
{
	reading_fct_r(dr, n, filename);
	ft_path2(filename, &((*dr)->list), &((*dr)->root_file), (*n)->options);
	if (closedir((*dr)->pdir) == -1)
	{
		ft_putendl("Closedir a fail");
		exit(-1);
	}
	display_data_file((*dr)->root_file, (*n)->options);
	free((*dr)->info_bis);
	clean_three(&((*dr)->root_file));
	(*dr)->head = (*dr)->list;
}

void	ft_dir_r(char *filename, t_norm **n, int flag, int loop)
{
	static int	dirnb = -1;
	t_dir_r		*dr;

	set_dir_r_var(&dr, flag, loop);
	dirnb++;
	if (!(dr->pdir = opendir(filename)))
	{
		error_r(filename, &dr);
		free(dr->info_bis);
		free(dr);
		return ;
	}
	loop = filename_fct_r(&dr, n, dirnb, filename);
	half_r(&dr, n, filename);
	while (dr->list)
	{
		ft_putchar('\n');
		ft_putstr(dr->list->content);
		ft_putendl(":");
		ft_dir_r(dr->list->content, n, flag, loop);
		dr->list = dr->list->next;
	}
	clean_list(dr->head);
	free(dr);
}
