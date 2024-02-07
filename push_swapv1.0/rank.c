/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:13:50 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/07 13:38:13 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int to_b_rank(int content_elem, t_list *list_b)
{
	int			place_in_b;
	int			size_list;

	size_list = count_list(list_b);
	place_in_b = betwen_elem_list_b(content_elem,list_b);
	if (place_in_b == 0)
		return (place_in_b);
	if (place_in_b <= (size_list/2))
		return (-place_in_b);
	else
		return (size_list - place_in_b);
}

int place_a_rank(int place_a, t_list *list_a)
{ 
	int			size_list;
	int			middle;
	
	size_list = count_list(list_a);
	middle = (size_list / 2) + 1;
	if (place_a == 0)
		return (0); 
	if (place_a <= middle)
		return (-(place_a - 1));
	else
		return ((size_list - place_a) + 1);
}

int total_rank(int elem_place, int content_elem,t_list *list_a,t_list *list_b)
{
	int place_rank;
	int move_rank;
	int min;
	int max;

	place_rank = place_a_rank(elem_place,list_a);
	move_rank = to_b_rank(content_elem,list_b);
	if (place_rank <= move_rank)
	{
		min = place_rank;
		max = move_rank;
	}
	else
	{
		min = move_rank;
		max = place_rank;
	}
	if (max <= 0)
		return(-min);
	if (min >= 0)
		return(max);
	else
		return(-(min) + max);
}
