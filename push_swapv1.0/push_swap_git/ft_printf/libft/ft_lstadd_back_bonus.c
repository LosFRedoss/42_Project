/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:21:12 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/20 15:32:18 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_temp;

	if (!lst || !new)
		return ((void)0);
	if (!(*lst))
	{
		*lst = new;
		return ((void)0);
	}
	lst_temp = *lst;
	while (lst_temp -> next)
	{
		lst_temp = lst_temp -> next;
	}
	lst_temp->next = new;
}
