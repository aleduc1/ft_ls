/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:07:11 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:07:22 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	call_opt_la(t_btree **root)
{
	t_var	*var;

	var = NULL;
	var = ft_memalloc(sizeof(t_var));
	btree_apply_infix_la((*root), &var);
	ft_memdel((void**)&var);
}

void	call_opt_l(t_btree **root)
{
	t_var	*var;

	var = NULL;
	var = ft_memalloc(sizeof(t_var));
	btree_apply_infix_l((*root), &var);
	ft_memdel((void**)&var);
}

void	call_opt_fla(t_btree **root)
{
	t_var	*var;

	var = NULL;
	var = ft_memalloc(sizeof(t_var));
	btree_apply_infix_fla((*root), &var);
	ft_memdel((void**)&var);
}

void	call_opt_fl(t_btree **root)
{
	t_var	*var;

	var = NULL;
	var = ft_memalloc(sizeof(t_var));
	btree_apply_infix_fl((*root), &var);
	ft_memdel((void**)&var);
}

void	clean_list(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
	list = NULL;
}
