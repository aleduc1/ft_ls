/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:48:30 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:44:57 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	btree_insert_data(t_btree **root,\
		t_struct *info, int (*cmpf)(const char*, const char*))
{
	if (root)
	{
		if (*root)
		{
			if (cmpf((*root)->data->name, info->name) >= 0)
				btree_insert_data(&((*root)->left), info, cmpf);
			else
				btree_insert_data(&((*root)->right), info, cmpf);
		}
		else
			*root = btree_create_node(info);
	}
}

void	btree_insert_data_t(t_btree **root,\
		t_struct *info, int (*cmpf)(t_struct*, t_struct*))
{
	if (root)
	{
		if (*root)
		{
			if (cmpf((*root)->data, info) >= 0)
				btree_insert_data_t(&((*root)->left), info, cmpf);
			else
				btree_insert_data_t(&((*root)->right), info, cmpf);
		}
		else
			*root = btree_create_node(info);
	}
}

void	btree_insert_data_av(t_btree_av **root,\
		char *str, int (*cmpf)(const char*, const char*))
{
	if (root)
	{
		if (*root)
		{
			if (cmpf((*root)->names, str) >= 0)
				btree_insert_data_av(&((*root)->left), str, cmpf);
			else
				btree_insert_data_av(&((*root)->right), str, cmpf);
		}
		else
			*root = btree_create_node_av(str);
	}
}

void	display_data_2(t_btree *root, char *options)
{
	if (options[1])
	{
		if (root)
			btree_apply_infix_a(root, (void*)&ft_putendl);
	}
	else
	{
		if (root)
			btree_apply_infix(root, (void*)&ft_putendl);
	}
}

void	display_data(t_btree *root, char *options)
{
	if (options[0])
	{
		if (options[1])
		{
			if (root)
			{
				call_opt_la(&root);
			}
		}
		else
		{
			if (root)
			{
				call_opt_l(&root);
			}
		}
	}
	else
		display_data_2(root, options);
}
