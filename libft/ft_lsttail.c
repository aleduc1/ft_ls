/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:45:19 by aleduc            #+#    #+#             */
/*   Updated: 2017/11/22 15:06:07 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsttail(t_list **alst, t_list *new)
{
	t_list	*curlist;

	curlist = *alst;
	while (curlist->next)
		curlist = curlist->next;
	curlist->next = new;
}
