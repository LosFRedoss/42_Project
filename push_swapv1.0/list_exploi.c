/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_exploi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:18:01 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/07 12:59:08 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*chose_elem_list_cont(int nb_elem, t_list *list)
{
	t_element	*temp;
	int			i;

	if (!list || !list->first)
		return (NULL);
	temp = list->first;
	i = 0;
	while (++i < nb_elem)
		temp = temp->next;
	return (temp);
}
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
