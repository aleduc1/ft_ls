/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:29:04 by aleduc            #+#    #+#             */
/*   Updated: 2018/06/21 19:30:38 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_whitespaces(void)
{
	ft_putchar(' ');
	ft_putchar(' ');
}

void	print_newline(void)
{
	ft_putchar('\n');
}

void	apply_padding_nbr(int maxlen, int nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	while (nbrlen < maxlen)
	{
		print_whitespace();
		nbrlen++;
	}
}

void	apply_padding(int maxlen, char *str)
{
	int		strlen;

	strlen = ft_strlen(str);
	while (strlen < maxlen)
	{
		print_whitespace();
		strlen++;
	}
}

int		current_time(int nbr)
{
	time_t		cur_t;

	cur_t = time(NULL);
	if (cur_t - nbr >= 15768000)
		return (0);
	else
		return (1);
}
