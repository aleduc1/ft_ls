/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:40:53 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:44:51 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree			*btree_create_node(void *info)
{
	t_btree	*node;

	if (!(node = ft_memalloc(sizeof(t_btree))))
	{
		ft_putendl("ECHEC!");
		exit(0);
	}
	if ((node->data = ft_memalloc(sizeof(t_struct))))
		node->data = ft_memcpy(node->data, info, sizeof(t_struct));
	else
	{
		ft_putendl("ECHEC, SALE PLEUTRE!");
		exit(0);
	}
	return (node);
}

t_btree_av		*btree_create_node_av(char *names)
{
	t_btree_av	*node;

	if (!(node = ft_memalloc(sizeof(t_btree_av))))
	{
		ft_putendl("ECHEC CUISANT!");
		exit(0);
	}
	node->names = ft_strdup(names);
	return (node);
}

int				opt_rt(t_struct *inb3, t_struct *wr2put)
{
	int		strcmp_ret;

	strcmp_ret = 0;
	if (opt_t(inb3, wr2put) > 0)
		strcmp_ret = -2;
	else if (opt_t(inb3, wr2put) < 0)
		strcmp_ret = 2;
	return (strcmp_ret);
}

void			display_data_file_2(t_btree *root, char *options)
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

void			display_data_file(t_btree *root, char *options)
{
	if (options[0])
	{
		if (options[1])
		{
			if (root)
				call_opt_fla(&root);
		}
		else
		{
			if (root)
				call_opt_fl(&root);
		}
	}
	else
		display_data_file_2(root, options);
}
