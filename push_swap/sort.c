/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:52:57 by tmimault          #+#    #+#             */
/*   Updated: 2024/01/27 21:57:16 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **list_a, t_list **list_b)
{
	int fi_elem;
	int se_elem;
	int th_elem;
	
	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;
	th_elem = (*list_a)->first->next->next->content;

	if(fi_elem > se_elem && fi_elem > th_elem)
	{
		rotate_ty('a', list_a, list_b);
		if (se_elem > th_elem)
				swap_ty('a', list_a, list_a);
	}
	else if (fi_elem < th_elem && (fi_elem > se_elem || se_elem > th_elem))
	{
		swap_ty('a', list_a, list_b);
		if(se_elem > th_elem)
			rotate_ty('a', list_a, list_b);
	}
	else if (fi_elem > th_elem)
		rev_rotate_ty('a',list_a,list_b);
}

void sort_2(t_list **list_a, t_list **list_b)
{
	int fi_elem;
	int se_elem;

	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;

	if (fi_elem > se_elem)
		swap_ty('a', list_a, list_b);
}