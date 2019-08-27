/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:33:22 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:33:57 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				maxlen_grp_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_grp_a(root->left, var);
	if (root && root->data)
		(*var)->len_gp = len_grp(root->data->groupe, var);
	if (root && root->right)
		maxlen_grp_a(root->right, var);
	return ((*var)->len_gp);
}

int				maxlen_grp(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_grp(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			(*var)->len_gp = len_grp(root->data->groupe, var);
	if (root && root->right)
		maxlen_grp(root->right, var);
	return ((*var)->len_gp);
}

int				maxlen_usr_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_usr_a(root->left, var);
	if (root && root->data)
		(*var)->len_us = len_usr(root->data->proprio, var);
	if (root && root->right)
		maxlen_usr_a(root->right, var);
	return ((*var)->len_us);
}

int				maxlen_usr(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_usr(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			(*var)->len_us = len_usr(root->data->proprio, var);
	if (root && root->right)
		maxlen_usr(root->right, var);
	return ((*var)->len_us);
}

int				maxlen_oct_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_oct_a(root->left, var);
	if (root && root->data)
		(*var)->len_oc = len_oct(root->data->size, var);
	if (root && root->right)
		maxlen_oct_a(root->right, var);
	return ((*var)->len_oc);
}
