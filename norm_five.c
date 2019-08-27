/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:31:19 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:32:03 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		maxlen_min_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_min_a(root->left, var);
	if (root && root->data)
		if (root->data->flag_dev)
			(*var)->len_mi = len_min(root->data->minor, var);
	if (root && root->right)
		maxlen_min_a(root->right, var);
	return ((*var)->len_mi);
}

int		maxlen_min(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_min(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)) && (root->data->flag_dev))
			(*var)->len_mi = len_min(root->data->minor, var);
	if (root && root->right)
		maxlen_min(root->right, var);
	return ((*var)->len_mi);
}

void	print(char *str)
{
	ft_putstr(str);
}

void	print_n(int nbr)
{
	ft_putnbr(nbr);
}

void	print_whitespace(void)
{
	ft_putchar(' ');
}
