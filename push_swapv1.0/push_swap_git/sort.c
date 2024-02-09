/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:52:57 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/09 18:29:13 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **list_a, t_list **list_b)
{
	int	fi_elem;
	int	se_elem;
	int	th_elem;

	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;
	th_elem = (*list_a)->first->next->next->content;
	if (fi_elem > se_elem && fi_elem > th_elem)
	{
		rotate_ty('a', list_a, list_b);
		if (se_elem > th_elem)
			swap_ty('a', list_a, list_b);
	}
	else if (fi_elem < th_elem && (fi_elem > se_elem || se_elem > th_elem))
	{
		swap_ty('a', list_a, list_b);
		if (se_elem > th_elem)
			rotate_ty('a', list_a, list_b);
	}
	else if (fi_elem > th_elem)
		rev_rotate_ty('a', list_a, list_b);
}

void	sort_2(t_list **list_a, t_list **list_b)
{
	int	fi_elem;
	int	se_elem;

	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;
	if (fi_elem > se_elem)
		swap_ty('a', list_a, list_b);
}

int	check_litle_sort(t_list **list_a, t_list **list_b)
{
	int	nb_elem_l;

	nb_elem_l = count_list(*list_a);
	if (nb_elem_l == 3)
		sort_3(list_a, list_b);
	else if (nb_elem_l == 2)
		sort_2(list_a, list_b);
	if (nb_elem_l <= 3)
		return (1);
	else
		return (0);
}

int	start_big_sort(t_list **list_a, t_list **list_b)
{
	int	i;

	i = 0;
	if (check_litle_sort(list_a, list_b) == 0)
	{
		push_ty('b', list_a, list_b);
		push_ty('b', list_a, list_b);
		while (check_litle_sort(list_a, list_b) == 0)
		{
			move_a_to_b(cmp_elem_a_to_b(list_a, list_b), list_a, list_b);
			push_ty('b', list_a, list_b);
		}
		while (count_list(*list_b) != 0)
			put_first_b_to_a((*list_b)->first->content, list_a, list_b);
		sort_entire_list(list_a, list_b);
	}
	return (1);
}

void	sort_entire_list(t_list **list, t_list **list_b)
{
	int	size_list;
	int	place_start;
	int	min_list;

	size_list = count_list(*list);
	min_list = min_elem_list(*list);
	place_start = place_elem_list(min_list, *list);
	if (place_start > (size_list / 2))
		while ((*list)->first->content != min_list)
			rev_rotate_ty('a', list, list_b);
	else
		while ((*list)->first->content != min_list)
			rotate_ty('a', list, list_b);
}
