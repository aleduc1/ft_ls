/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:32:26 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:19:17 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(const char *file)
{
	struct stat		buff;

	if (lstat(file, &buff) == -1)
	{
		return (0);
	}
	else
	{
		if ((buff.st_mode & 0170000) == 0040000)
			return (1);
	}
	return (0);
}

int		comp_t(t_struct *n1, t_struct *n2)
{
	int		diff;

	diff = n1->timestamp - n2->timestamp;
	return (diff);
}

int		dir_sort(const char *s1, const char *s2)
{
	int		strcmp_ret;

	strcmp_ret = 0;
	if ((ft_isdir(s1) == 1) && (ft_isdir(s2) == 1))
		strcmp_ret = ft_strcmp(s1, s2);
	else if ((ft_isdir(s1) == 0) && (ft_isdir(s2) == 0))
		strcmp_ret = ft_strcmp(s1, s2);
	else if ((ft_isdir(s1) == 0) && (ft_isdir(s2) == 1))
		strcmp_ret = -2;
	else if ((ft_isdir(s1) == 1) && (ft_isdir(s2) == 0))
		strcmp_ret = 2;
	return (strcmp_ret);
}

int		dir_sort_r(const char *s1, const char *s2)
{
	int		strcmp_ret;

	strcmp_ret = 0;
	if ((ft_isdir(s1) == 1) && (ft_isdir(s2) == 1))
		strcmp_ret = opt_r(s1, s2);
	else if ((ft_isdir(s1) == 0) && (ft_isdir(s2) == 0))
		strcmp_ret = opt_r(s1, s2);
	else if ((ft_isdir(s1) == 0) && (ft_isdir(s2) == 1))
		strcmp_ret = -2;
	else if ((ft_isdir(s1) == 1) && (ft_isdir(s2) == 0))
		strcmp_ret = 2;
	return (strcmp_ret);
}

int		opt_t(t_struct *inb3, t_struct *wr2put)
{
	int		strcmp_ret;

	strcmp_ret = 0;
	if (comp_t(inb3, wr2put) > 0)
		strcmp_ret = -2;
	else if (comp_t(inb3, wr2put) < 0)
		strcmp_ret = 2;
	else
		strcmp_ret = ft_strcmp(inb3->name, wr2put->name);
	return (strcmp_ret);
}
