/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:57:52 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/24 13:57:27 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_fill(char c, char *options)
{
	char	*check;

	check = "laRrt";
	if (options[0] == 0 && c == 'l')
		options[0] = '1';
	else if (options[1] == 0 && c == 'a')
		options[1] = '1';
	else if (options[2] == 0 && c == 'R')
		options[2] = '1';
	else if (options[3] == 0 && c == 'r')
		options[3] = '1';
	else if (options[4] == 0 && c == 't')
		options[4] = '1';
	if (ft_strchr((const char *)check, (int)c) == NULL)
		return (1);
	return (0);
}

int		ft_check(char *str, char *options)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 1)
		return (2);
	while (str[++i])
		if (ft_fill(str[i], options) == 1)
			return (1);
	return (0);
}

int		ft_opts(char *str, t_norm **n)
{
	int		stock;

	stock = ft_check(str, (*n)->options);
	if (stock == 1)
	{
		ft_error(stock, (*n)->options);
		free((*n)->options);
		free((*n));
	}
	return (stock);
}

void	insert_fct(t_norm **n, t_dir **d)
{
	if ((*n)->options[3] && (*n)->options[4])
		btree_insert_data_t(&((*d)->root_file), (*d)->info_bis, &opt_rt);
	else if ((*n)->options[3])
		btree_insert_data(&((*d)->root_file), (*d)->info_bis, &opt_r);
	else if ((*n)->options[4])
		btree_insert_data_t(&((*d)->root_file), (*d)->info_bis, &opt_t);
	else
		btree_insert_data(&((*d)->root_file), (*d)->info_bis, &ft_strcmp);
}

void	reading_fct(t_dir **d, t_norm **n, char *filename)
{
	while (((*d)->pent = readdir((*d)->pdir)))
	{
		if ((*d)->pent == NULL)
		{
			perror("Readdir failed");
			exit(1);
		}
		(*d)->path = ft_strjoin(filename, "/");
		(*d)->tmpp = (*d)->path;
		(*d)->path = ft_strjoin((*d)->path, (*d)->pent->d_name);
		free((*d)->tmpp);
		if (ft_stat((*d)->path, &((*d)->info_bis), (*d)->pent->d_name) == 2)
		{
			ft_memdel((void**)&((*d)->path));
			return ;
		}
		insert_fct(n, d);
		ft_memdel((void**)&((*d)->path));
	}
}
