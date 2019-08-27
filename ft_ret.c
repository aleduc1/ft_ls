/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:19:29 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/24 12:38:28 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ret(int nb, t_norm **n)
{
	if (nb == 0)
	{
		display_data((*n)->root, (*n)->options);
		clean_three(&((*n)->root));
	}
}

void	set_dir_r_var(t_dir_r **dr, int flag, int loop)
{
	(*dr) = ft_memalloc(sizeof(t_dir_r));
	(*dr)->flagcpy = flag;
	(*dr)->loopcpy = loop;
	(*dr)->info_bis = ft_memalloc(sizeof(t_struct));
	(*dr)->pdir = NULL;
	(*dr)->root_file = NULL;
	(*dr)->pent = NULL;
	(*dr)->list = NULL;
	(*dr)->i = 0;
}

void	error_r(char *filename, t_dir_r **dr)
{
	ft_putstr("ft_ls: ");
	(*dr)->i = ft_strlen(filename);
	(*dr)->i--;
	while (filename[(*dr)->i] != '/' && (*dr)->i > -1)
		(*dr)->i--;
	perror(filename + (*dr)->i + 1);
	ft_memdel((void**)&((*dr)->info_bis));
}

int		filename_fct_r(t_dir_r **dr, t_norm **n, int dirnb, char *filename)
{
	if ((!(*dr)->loopcpy) && (*n)->argnbr && (*dr)->flagcpy && (!dirnb))
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putendl(":");
		(*dr)->loopcpy = 1;
	}
	else if ((!(*dr)->loopcpy) && (*n)->argnbr && (!dirnb))
	{
		ft_putstr(filename);
		ft_putendl(":");
		(*dr)->loopcpy = 1;
	}
	else if ((!(*dr)->loopcpy) && (*n)->argnbr && dirnb)
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putendl(":");
		(*dr)->loopcpy = 1;
	}
	return ((*dr)->loopcpy);
}

void	insert_fcts(t_norm **n, t_dir_r **dr)
{
	if ((*n)->options[3] && (*n)->options[4])
		btree_insert_data_t(&((*dr)->root_file), (*dr)->info_bis, &opt_rt);
	else if ((*n)->options[3])
		btree_insert_data(&((*dr)->root_file), (*dr)->info_bis, &opt_r);
	else if ((*n)->options[4])
		btree_insert_data_t(&((*dr)->root_file), (*dr)->info_bis, &opt_t);
	else
		btree_insert_data(&((*dr)->root_file), (*dr)->info_bis, &ft_strcmp);
}
