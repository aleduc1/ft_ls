/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:33:48 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/23 18:29:39 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort(char *str, t_norm **n)
{
	if ((*n)->options[3])
		btree_insert_data_av(&((*n)->dir_order), str, &dir_sort_r);
	else
		btree_insert_data_av(&((*n)->dir_order), str, &dir_sort);
}

void	ft_args(int ac, char **av, t_norm **n)
{
	int cpy;

	cpy = (*n)->i;
	while (cpy < ac)
	{
		ft_sort(av[cpy], n);
		cpy++;
	}
}

int		ft_argnbr(t_btree_av **dir_order)
{
	static int	count = 0;
	static int	ret = 0;

	if (!(*dir_order))
		return (-1);
	if ((*dir_order) && (*dir_order)->left)
		ft_argnbr(&(*dir_order)->left);
	if ((*dir_order))
	{
		count++;
		if (count == 2)
		{
			ret = 1;
			return (ret);
		}
	}
	if ((*dir_order) && (*dir_order)->right)
		ft_argnbr(&(*dir_order)->right);
	return (ret);
}

void	clean_three_av(t_btree_av **root)
{
	if (!root || !(*root))
		return ;
	if ((*root) && (*root)->left)
		clean_three_av(&(*root)->left);
	if ((*root) && (*root)->right)
		clean_three_av(&(*root)->right);
	if ((*root) && (*root)->names)
	{
		free((*root)->names);
		free((*root));
	}
}

void	free_info(t_struct **info)
{
	if ((*info)->path)
		free((*info)->path);
	if ((*info)->name)
		free((*info)->name);
	if ((*info)->mode)
		free((*info)->mode);
	if ((*info)->date)
		free((*info)->date);
}
