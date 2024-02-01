/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:37:43 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/01 22:15:32 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_list(t_list *list)
{
	int			count;
	t_element	*temp;
	
	count = 0;
	if (!list)
		return (count);
	temp = list->first;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_element *last_elem_list(t_list *list)
{
	t_element	*temp;
	
	if (!list)
		return (NULL);
	temp = list->first;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_element	*chose_elem_list(int nb_elem, t_list *list)
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

int	place_elem_list(int nb_elem, t_list	*list)
{
	t_element	*temp;
	int			i;
	
	if(!list || !list->first)
		return(0);
	i = 1;
	temp = list->first;
	while (temp->content != nb_elem)
	{
		temp = temp->next;
		i++;
		if(!temp)
			return(-1);
	}
	return(i);
}


int min_elem_list(t_list *list)
{
	t_element	*temp;
	int			min;

	if (!list || !list->first->content)
		return (-1);
	temp = list->first;
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return(min);
}

int	max_elem_list(t_list *list)
{
	t_element	*temp;
	int			max;

	if (!list || !list->first->content)
		return (-1);
	temp = list->first;
	max = temp->content;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return(max);
}



