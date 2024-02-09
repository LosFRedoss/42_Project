/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_exploi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:18:01 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/09 18:05:31 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*chose_elem_list_place(int plc_elem, t_list *list)
{
	t_element	*temp;
	int			i;

	if (!list || !list->first)
		return (NULL);
	temp = list->first;
	i = 1;
	while (i != plc_elem)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

int	betwen_elem_list(int content_elem, t_list *list)
{
	int			size_list;
	int			count;
	t_element	*temp;

	if (!list || !list->first)
		return (-1);
	size_list = count_list(list);
	temp = list->first;
	count = 1;
	while (temp->next)
	{
		if ((content_elem > temp->content && content_elem < temp->next->content)
			|| (temp->content == max_elem_list (list)
				&& (content_elem > temp->content
					|| content_elem < temp->next->content)))
		{
			if (count <= (size_list / 2))
				return (1);
			else
				return (2);
		}
		count++;
		temp = temp->next;
	}
	return (-1);
}

int	betwen_elem_list_b(int content_elem, t_list *list)
{
	int			size_list;
	int			count;
	t_element	*temp;

	if (!list || !list->first)
		return (-1);
	size_list = count_list(list);
	temp = list->first;
	count = 1;
	while (temp->next)
	{
		if ((content_elem < temp->content && content_elem > temp->next->content)
			|| (temp->content == min_elem_list(list)
				&& (content_elem < temp->content
					|| content_elem > temp->next->content)))
		{
			return (count);
		}
		count++;
		temp = temp->next;
	}
	return (0);
}
