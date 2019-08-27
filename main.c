/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:42:46 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/23 18:27:24 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_var(t_norm **n)
{
	(*n) = ft_memalloc(sizeof(t_norm));
	(*n)->root = NULL;
	(*n)->dir_order = NULL;
	(*n)->i = 1;
	(*n)->j = 1;
	(*n)->options = ft_memalloc(6);
}

int		one_ac_main(t_norm **n)
{
	(*n)->argnbr = 0;
	ft_ls(".", n);
	free((*n)->options);
	free((*n));
	return (0);
}

int		main_two(t_norm **n)
{
	(*n)->argnbr = ft_argnbr(&((*n)->dir_order));
	ft_ret(ft_ls_btree(&((*n)->dir_order), n), n);
	free((*n)->options);
	clean_three_av(&((*n)->dir_order));
	free((*n));
	return (0);
}

int		ft_types(t_struct **info)
{
	if (ft_strcmp((*info)->types, "Dossier") == 0)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_norm	*n;

	set_var(&n);
	if (ac == 1)
		return (one_ac_main(&n));
	while (n->j < ac)
	{
		if (av[n->j][0] == '-')
		{
			if (ft_opts(av[n->j], &n) == 1)
				return (1);
			else if (ft_opts(av[n->j], &n) == 2)
				n->i = n->j;
			else if (ft_opts(av[n->j], &n) == 0)
				n->i = n->j + 1;
		}
		else
			break ;
		n->j++;
	}
	if (n->i == ac)
		return (one_ac_main(&n));
	ft_args(ac, av, &n);
	return (main_two(&n));
}
