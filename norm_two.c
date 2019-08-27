/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:25:57 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/24 13:27:25 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned long	print_total(t_btree *root, t_var **var)
{
	if (root && root->left)
		print_total(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			(*var)->total += root->data->blocks;
	if (root && root->right)
		print_total(root->right, var);
	return ((*var)->total);
}

void			first_half_l(t_struct **data, t_var **var)
{
	print_whitespaces();
	if ((*var)->len_maj)
		apply_padding_nbr((*var)->len_maj + (*var)->len_min + 3, \
				(*data)->size);
	else
		apply_padding_nbr((*var)->len_oct, (*data)->size);
	print_n((*data)->size);
	print_whitespace();
	print_time((*data));
	print_whitespace();
	ft_putstr((*data)->name);
	print_link((*data)->types, (*data)->path);
	print_newline();
}

void			second_half_l(t_struct **data, t_var **var)
{
	ft_putstr("   ");
	apply_padding_nbr((*var)->len_maj, (*data)->major);
	print_n((*data)->major);
	ft_putchar(',');
	print_whitespace();
	apply_padding_nbr((*var)->len_min, (*data)->minor);
	print_n((*data)->minor);
	print_whitespace();
	print_time((*data));
	print_whitespace();
	ft_putstr((*data)->name);
	print_link((*data)->types, (*data)->path);
	print_newline();
}

void			opt_l(t_struct *data, t_var **var)
{
	int flag;

	flag = 0;
	if (print_types(data->types) == 1)
		flag = 1;
	print(data->mode);
	print_whitespaces();
	apply_padding_nbr((*var)->len_lnk, data->nlinks);
	print_n(data->nlinks);
	print_whitespace();
	print(data->proprio);
	apply_padding((*var)->len_usr, data->proprio);
	print_whitespaces();
	print(data->groupe);
	apply_padding((*var)->len_grp, data->groupe);
	if (flag == 0)
		first_half_l(&data, var);
	else
		second_half_l(&data, var);
}

void			reset_var(t_var **var)
{
	(*var)->len_usr = 0;
	(*var)->len_grp = 0;
	(*var)->len_oct = 0;
	(*var)->len_lnk = 0;
	(*var)->len_maj = 0;
	(*var)->len_min = 0;
	(*var)->len_us = 0;
	(*var)->len_gp = 0;
	(*var)->len_oc = 0;
	(*var)->len_lk = 0;
	(*var)->len_ma = 0;
	(*var)->len_mi = 0;
	(*var)->len_u = 0;
	(*var)->len_g = 0;
	(*var)->len_o = 0;
	(*var)->len_l = 0;
	(*var)->len_m1 = 0;
	(*var)->len_m2 = 0;
	(*var)->total_flag = 0;
}
