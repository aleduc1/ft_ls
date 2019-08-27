/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_eight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:34:23 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/21 17:47:19 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		len_usr(char *str, t_var **var)
{
	int		strlen;

	strlen = ft_strlen(str);
	if (strlen > (*var)->len_u)
		(*var)->len_u = strlen;
	return ((*var)->len_u);
}

int		len_grp(char *str, t_var **var)
{
	int		strlen;

	strlen = ft_strlen(str);
	if (strlen > (*var)->len_g)
		(*var)->len_g = strlen;
	return ((*var)->len_g);
}

int		check_total(t_btree *root, t_var **var)
{
	if (root && root->left)
		check_total(root->left, var);
	if (root && root->data)
		(*var)->total_flag++;
	if (root && root->right)
		check_total(root->right, var);
	return ((*var)->total_flag);
}

void	do_total(t_btree *root, t_var **var)
{
	ft_putstr("total ");
	ft_putnbr(print_total(root, var));
	ft_putchar('\n');
}

int		is_dot_2(char *str, char *options)
{
	if (options[1])
	{
		if (ft_strcmp(str, ".") == 0)
			return (1);
		else if (ft_strcmp(str, "..") == 0)
			return (1);
		return (0);
	}
	return (is_dot(str));
}
