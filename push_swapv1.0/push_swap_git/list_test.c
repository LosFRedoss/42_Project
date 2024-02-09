/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:54:34 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/09 18:15:24 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_croissant(t_list *list)
{
	t_element	*list_temp;

	if ((list) && (list->first))
	{
		list_temp = list->first;
		while (list_temp->next)
		{
			if (list_temp->content > list_temp->next->content)
				return (0);
			list_temp = list_temp->next;
		}
		return (1);
	}
	else
		return (0);
}

int	if_decroissant(t_list *list)
{
	t_element	*list_temp;

	if ((list) && (list->first))
	{
		list_temp = list->first;
		while (list_temp->next)
		{
			if (list_temp->content < list_temp->next->content)
				return (0);
			list_temp = list_temp->next;
		}
		return (1);
	}
	else
		return (0);
}
