/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:20:06 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/18 18:10:23 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_stat(char *path, t_struct **data, char *name)
{
	struct stat		buff;
	struct passwd	*pwd;
	struct group	*grp;
	char			*ct_ret;

	if (lstat(path, &buff) == -1)
		return (2);
	else
	{
		if (put_uids(&buff, &pwd, &grp) == 2)
			return (2);
		else
		{
			put_data(&buff, data, path, name);
			put_types(&buff, data);
			put_modes(&buff, data);
			(*data)->proprio = pwd->pw_name;
			(*data)->groupe = grp->gr_name;
			ct_ret = ctime(&buff.st_mtimespec.tv_sec);
			(*data)->date = ft_strdup(ct_ret);
		}
	}
	return (0);
}

void	btree_apply_infix_l(t_btree *root, t_var **var)
{
	if (!root)
		return ;
	if ((*var)->flag == 0)
	{
		reset_var(var);
		(*var)->len_usr = maxlen_usr(root, var);
		(*var)->len_grp = maxlen_grp(root, var);
		(*var)->len_oct = maxlen_oct(root, var);
		(*var)->len_lnk = maxlen_lnk(root, var);
		(*var)->len_maj = maxlen_maj(root, var);
		(*var)->len_min = maxlen_min(root, var);
		(*var)->flag = 1;
	}
	if (root && root->left)
		btree_apply_infix_l(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			opt_l(root->data, var);
	if (root && root->right)
		btree_apply_infix_l(root->right, var);
}

void	btree_apply_infix_la(t_btree *root, t_var **var)
{
	if (!root)
		return ;
	if ((*var)->flag == 0)
	{
		reset_var(var);
		(*var)->len_usr = maxlen_usr_a(root, var);
		(*var)->len_grp = maxlen_grp_a(root, var);
		(*var)->len_oct = maxlen_oct_a(root, var);
		(*var)->len_lnk = maxlen_lnk_a(root, var);
		(*var)->len_maj = maxlen_maj_a(root, var);
		(*var)->len_min = maxlen_min_a(root, var);
		(*var)->flag = 1;
	}
	if (root && root->left)
		btree_apply_infix_la(root->left, var);
	if (root && root->data)
		opt_l(root->data, var);
	if (root && root->right)
		btree_apply_infix_la(root->right, var);
}

void	btree_apply_infix_fla(t_btree *root, t_var **var)
{
	if (!root)
		return ;
	if ((*var)->flag == 0)
	{
		reset_var(var);
		(*var)->len_usr = maxlen_usr_a(root, var);
		(*var)->len_grp = maxlen_grp_a(root, var);
		(*var)->len_oct = maxlen_oct_a(root, var);
		(*var)->len_lnk = maxlen_lnk_a(root, var);
		(*var)->len_maj = maxlen_maj_a(root, var);
		(*var)->len_min = maxlen_min_a(root, var);
		ft_putstr("total ");
		ft_putnbr(print_total_a(root, var));
		ft_putchar('\n');
		(*var)->flag = 1;
	}
	if (root && root->left)
		btree_apply_infix_fla(root->left, var);
	if (root && root->data)
		opt_l(root->data, var);
	if (root && root->right)
		btree_apply_infix_fla(root->right, var);
}

void	btree_apply_infix_fl(t_btree *root, t_var **var)
{
	if (!root)
		return ;
	if ((*var)->flag == 0)
	{
		reset_var(var);
		(*var)->len_usr = maxlen_usr(root, var);
		(*var)->len_grp = maxlen_grp(root, var);
		(*var)->len_oct = maxlen_oct(root, var);
		(*var)->len_lnk = maxlen_lnk(root, var);
		(*var)->len_maj = maxlen_maj(root, var);
		(*var)->len_min = maxlen_min(root, var);
		if (check_total(root, var) > 2)
			do_total(root, var);
		(*var)->flag = 1;
	}
	if (root && root->left)
		btree_apply_infix_fl(root->left, var);
	if (root && root->data)
		if (!(is_dot(root->data->name)))
			opt_l(root->data, var);
	if (root && root->right)
		btree_apply_infix_fl(root->right, var);
}
