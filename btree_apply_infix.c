/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:41:40 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:44:45 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dot(char *str)
{
	if (str[0] == '.')
	{
		if (str[1])
		{
			if (str[1] != '/')
			{
				if (str[2])
				{
					if (str[2] != '/')
						return (1);
					else
						return (0);
				}
				else
					return (1);
			}
			else
				return (0);
		}
		else
			return (1);
	}
	return (0);
}

void	btree_apply_infix_a(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	if (root && root->left)
		btree_apply_infix_a(root->left, applyf);
	if (root && root->data)
		applyf((void*)root->data->name);
	if (root && root->right)
		btree_apply_infix_a(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	if (root && root->left)
		btree_apply_infix(root->left, applyf);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			applyf((void*)root->data->name);
	if (root && root->right)
		btree_apply_infix(root->right, applyf);
}

void	btree_apply_infix_av(t_btree_av *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	if (root && root->left)
		btree_apply_infix_av(root->left, applyf);
	if (root && root->names)
		applyf(root->names);
	if (root && root->right)
		btree_apply_infix_av(root->right, applyf);
}

int		opt_r(const char *s1, const char *s2)
{
	int		strcmp_ret;

	strcmp_ret = 0;
	if (ft_strcmp(s1, s2) > 0)
		strcmp_ret = -2;
	else if (ft_strcmp(s1, s2) < 0)
		strcmp_ret = 2;
	return (strcmp_ret);
}
