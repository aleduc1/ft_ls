/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:27:17 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:28:27 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_time(t_struct *data)
{
	int		i;

	i = 4;
	if (current_time(data->timestamp) == 1)
		while (data->date[i] && i < 16)
			ft_putchar(data->date[i++]);
	else
	{
		while (data->date[i] && i < 11)
			ft_putchar(data->date[i++]);
		i = 19;
		while (data->date[i] && i < 24)
			ft_putchar(data->date[i++]);
	}
}

void			print_link(char *type, char *path)
{
	char	*buff;

	buff = NULL;
	if (ft_strcmp(type, "SymLink") == 0)
	{
		if (!(buff = ft_memalloc(2048)))
		{
			ft_putendl("GNEEE");
			exit(0);
		}
		if (!readlink(path, buff, 2048))
		{
			ft_putendl("GNEEE");
			exit(0);
		}
		ft_putstr(" -> ");
		ft_putstr(buff);
		free(buff);
	}
}

void			print_types_short(int *ptr)
{
	ft_putchar('b');
	*ptr = 1;
}

int				print_types(char *str)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(str, "Fichier") == 0)
		ft_putchar('-');
	else if (ft_strcmp(str, "Dossier") == 0)
		ft_putchar('d');
	else if (ft_strcmp(str, "SymLink") == 0)
		ft_putchar('l');
	else if (ft_strcmp(str, "Socket") == 0)
		ft_putchar('s');
	else if (ft_strcmp(str, "SpecialBlock") == 0)
		print_types_short(&ret);
	else if (ft_strcmp(str, "FIFO") == 0)
		ft_putchar('f');
	else if (ft_strcmp(str, "CharacSpecial") == 0)
	{
		ft_putchar('c');
		ret = 1;
	}
	else if (ft_strcmp(str, "Whiteout") == 0)
		ft_putchar('w');
	return (ret);
}

unsigned long	print_total_a(t_btree *root, t_var **var)
{
	if (root && root->left)
		print_total_a(root->left, var);
	if (root && root->data)
		(*var)->total += root->data->blocks;
	if (root && root->right)
		print_total_a(root->right, var);
	return ((*var)->total);
}
