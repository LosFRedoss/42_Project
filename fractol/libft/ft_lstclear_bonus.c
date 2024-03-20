/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:55:36 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/21 17:41:41 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !(*lst) || !del)
		return ((void)0);
	ft_lstclear(&(*lst)->next, (*del));
	ft_lstdelone(*lst, (*del));
	*lst = NULL;
}
