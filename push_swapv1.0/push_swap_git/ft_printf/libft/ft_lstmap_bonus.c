/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:30:00 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/21 17:42:35 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*ft_freemalloc(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cpy_new;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		cpy_new = ft_lstnew(temp);
		if (cpy_new == NULL)
		{
			del(temp);
			return (ft_freemalloc(&new_lst, (*del)));
		}
		ft_lstadd_back(&new_lst, cpy_new);
		lst = lst -> next;
	}
	return (new_lst);
}

static t_list	*ft_freemalloc(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, (*del));
	return (NULL);
}
