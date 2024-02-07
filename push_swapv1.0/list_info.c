/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:37:43 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/06 19:33:47 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_list(t_list *list)
{
	int			count;
	t_element	*temp;
	
	count = 0;
	if (!list || !list->first)
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
	
	if (!list || !list->first)
		return (NULL);
	temp = list->first;
	while (temp->next)
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

	if (!list || !list->first)
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

	if (!list || !list->first)
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

int betwen_elem_list(int content_elem, t_list *list)
{
	int size_list;
	int count;
	t_element	*temp;

	if (!list || !list->first)
		return (-1);
	size_list = count_list(list);
	temp = list->first;
	count = 1;
	while (temp->next)
	{
		if ((content_elem > temp->content && content_elem < temp->next->content ) ||
			(temp->content == max_elem_list (list) && (content_elem > temp->content || content_elem < temp->next->content)))
		{
			if (count <= (size_list / 2))
				return (1);
			else
				return (2);
		}
		count++;
		temp = temp->next;
	}
	return(-1);
}

int betwen_elem_list_b_old(int content_elem, t_list *list)
{
	int size_list; 
	int count;
	t_element	*temp;

	if (!list || !list->first)
		return (-1);
	size_list = count_list(list);
	temp = list->first;
	count = 1;
	while (temp->next)
	{
		if ((content_elem < temp->content && content_elem > temp->next->content) ||
			(temp->content == min_elem_list(list) && (content_elem < temp->content || content_elem > temp->next->content)))
		{
			if (count <= (size_list / 2))
				return (2);
			else
				return (1);
		}
		count++;
		temp = temp->next;
	}
	return(0);
}

int betwen_elem_list_b(int content_elem, t_list *list)
{
	int size_list; 
	int count;
	t_element	*temp;

	if (!list || !list->first)
		return (-1);
	size_list = count_list(list);
	temp = list->first;
	count = 1;
	while (temp->next)
	{
		if ((content_elem < temp->content && content_elem > temp->next->content) ||
			(temp->content == min_elem_list(list) && (content_elem < temp->content || content_elem > temp->next->content)))
		{
			return (count);
		}
		count++;
		temp = temp->next;
	}
	return(0);
}




