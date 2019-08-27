/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:28:47 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/24 12:38:11 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putendl_lst(t_list *lst)
{
	ft_putstr(lst->content);
}

void	ft_path(char *name, t_list **alst)
{
	int		namelen;
	t_list	*new;

	new = NULL;
	namelen = ft_strlen(name);
	if (*alst)
	{
		new = ft_lstnew(name, sizeof(*name) * namelen);
		ft_lsttail(alst, new);
	}
	else
		*alst = ft_lstnew(name, sizeof(*name) * namelen);
}

void	set_dir_var(t_dir **d)
{
	(*d) = ft_memalloc(sizeof(t_dir));
	(*d)->info_bis = ft_memalloc(sizeof(t_struct));
	(*d)->pdir = NULL;
	(*d)->pent = NULL;
	(*d)->path = NULL;
	(*d)->tmpp = NULL;
	(*d)->i = 0;
	(*d)->root_file = NULL;
}

void	error(t_dir **d, char *filename)
{
	ft_putchar('\n');
	ft_putstr("ft_ls: ");
	(*d)->i = ft_strlen(filename);
	(*d)->i--;
	while (filename[(*d)->i] != '/' && (*d)->i > -1)
		(*d)->i--;
	perror(filename + (*d)->i + 1);
	ft_memdel((void**)&((*d)->info_bis));
}

void	filename_fct(t_norm **n, int dirnb, int flag, char *filename)
{
	if ((*n)->argnbr && flag && (!dirnb))
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putendl(":");
	}
	else if ((*n)->argnbr && (!dirnb))
	{
		ft_putstr(filename);
		ft_putendl(":");
	}
	else if ((*n)->argnbr && dirnb)
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putendl(":");
	}
}
