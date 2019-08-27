/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:32:16 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:33:00 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				maxlen_oct(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_oct(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			(*var)->len_oc = len_oct(root->data->size, var);
	if (root && root->right)
		maxlen_oct(root->right, var);
	return ((*var)->len_oc);
}

int				maxlen_lnk_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_lnk_a(root->left, var);
	if (root && root->data)
		(*var)->len_lk = len_lnk(root->data->nlinks, var);
	if (root && root->right)
		maxlen_lnk_a(root->right, var);
	return ((*var)->len_lk);
}

int				maxlen_lnk(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_lnk(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			(*var)->len_lk = len_lnk(root->data->nlinks, var);
	if (root && root->right)
		maxlen_lnk(root->right, var);
	return ((*var)->len_lk);
}

int				maxlen_maj_a(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_maj_a(root->left, var);
	if (root && root->data)
		if (root->data->flag_dev)
			(*var)->len_ma = len_maj(root->data->major, var);
	if (root && root->right)
		maxlen_maj_a(root->right, var);
	return ((*var)->len_ma);
}

int				maxlen_maj(t_btree *root, t_var **var)
{
	if (!root)
	{
		ft_putendl("Bitch!");
		return (-1);
	}
	if (root && root->left)
		maxlen_maj(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)) && (root->data->flag_dev))
			(*var)->len_ma = len_maj(root->data->major, var);
	if (root && root->right)
		maxlen_maj(root->right, var);
	return ((*var)->len_ma);
}
