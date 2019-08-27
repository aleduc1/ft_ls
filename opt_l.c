/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:19 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/24 13:07:20 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_nbrlen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int				len_maj(int nbr, t_var **var)
{
	int			nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (nbrlen > (*var)->len_m1)
		(*var)->len_m1 = nbrlen;
	return ((*var)->len_m1);
}

int				len_min(int nbr, t_var **var)
{
	int			nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (nbrlen > (*var)->len_m2)
		(*var)->len_m2 = nbrlen;
	return ((*var)->len_m2);
}

int				len_lnk(int nbr, t_var **var)
{
	int			nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (nbrlen > (*var)->len_l)
		(*var)->len_l = nbrlen;
	return ((*var)->len_l);
}

int				len_oct(int nbr, t_var **var)
{
	int			nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (nbrlen > (*var)->len_o)
		(*var)->len_o = nbrlen;
	return ((*var)->len_o);
}
