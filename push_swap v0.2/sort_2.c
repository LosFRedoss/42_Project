/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:34:15 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/02 00:52:36 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_first_a_to_b(int elem_content_a,t_list **list_a,t_list **list_b)
{
int plus_grand;
int plus_petit;

plus_grand = 0;
plus_petit = 0;
if (elem_content_a > (*list_b)->first->content)
	plus_grand++;
if (elem_content_a < last_elem_list(*list_b)->content)
	plus_petit++;
if ((plus_petit == 1 && plus_grand == 1) || (plus_petit == 0 && plus_grand == 1 
	&& (*list_b)->first->content == max_elem_list(*list_b)) || (plus_petit == 1 
		&& plus_grand == 0 && last_elem_list(*list_b)->content == min_elem_list(*list_b)))
		push_ty('b',list_a,list_b);
else if (plus_petit == 0 && plus_grand == 1)
{
		rev_rotate_ty('b',list_a, list_b);
		put_first_a_to_b((*list_a)->first->content, list_a, list_b);
}
else 
{
		rotate_ty('b',list_a,list_b);
		put_first_a_to_b((*list_a)->first->content, list_a, list_b);
}
}

void	put_first_b_to_a(int elem_content_b,t_list **list_a, t_list **list_b)
{
	int petit_debut;
	int grand_fin;

	petit_debut = 0;
	grand_fin = 0;
	if (elem_content_b < (*list_a)->first->content)
		petit_debut++;
	if (elem_content_b > last_elem_list(*list_a)->content)
		grand_fin++;
	if ((petit_debut == 1 && grand_fin == 1) || (petit_debut == 1 && grand_fin == 0 && (last_elem_list(*list_a)->content == max_elem_list(*list_a))) || (petit_debut == 0 && grand_fin == 1 && (*list_a)->first))
		push_ty('a',list_a,list_b);
	else if ((petit_debut == 1 && grand_fin == 0) || (petit_debut == 0 && grand_fin == 0))
	{
			rotate_ty('a',list_a, list_b);
			put_first_b_to_a(elem_content_b, list_a, list_b);
	}
	else
	{
			rev_rotate_ty('a',list_a,list_b);
			put_first_b_to_a(elem_content_b, list_a, list_b);
	}
}

int	check_litle_sort(char type, t_list **list_a,t_list **list_b)
{
	int nb_elem_l;

	nb_elem_l = 4;
	if(type == 'a')
	{
		nb_elem_l = count_list(*list_a);
		if (nb_elem_l == 3)
			sort_3(list_a, list_b);
		else if (nb_elem_l == 2)
			sort_2('a',list_a,list_b);
	}
	if (type == 'b')
	{
		nb_elem_l = count_list(*list_b);
		if (nb_elem_l == 3)
			sort_3(list_b, list_a);
		else if (nb_elem_l == 2)
			sort_2('a',list_a,list_b);
	}
	if (nb_elem_l <= 3)
		return (1);
	else
		return (0);
}

void	sort_entire_list(t_list **list, t_list **list_b)
{
	int size_list;
	int	place_start;
	int	min_list;

	size_list = count_list(*list);
	min_list = min_elem_list(*list);
	place_start = place_elem_list(min_list,*list);
	if (place_start > (size_list / 2))
		while ((*list)->first->content != min_list)
			rev_rotate_ty('a', list, list_b);
	else 
		while ((*list)->first->content != min_list)
			rotate_ty('a',list,list_b);
}
