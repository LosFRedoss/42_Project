/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:34:15 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/07 15:42:46 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_a_to_b(int elem_place, t_list **list_a, t_list **list_b)
{
	t_element *elem;
	int	rank_list;
	int	rank_move;

	elem = chose_elem_list_place(elem_place, *list_a);
	rank_move = to_b_rank(elem->content, *list_b);
	rank_list = place_a_rank(elem_place, *list_a);
	if (rank_move <= rank_list)
	{
		if (rank_list <= 0)
			move_neg(1, elem, list_a,list_b);
		else if (rank_move >= 0)
			move_pos(1, elem, list_a, list_b);
		else
			move_mid(1, elem, list_a, list_b);
	}
	else
	{
		if (rank_move <= 0)
			move_neg(2, elem, list_a, list_b);
		else if (rank_list >= 0)
			move_pos(2, elem, list_a, list_b);
		else
			move_mid(2, elem, list_a, list_b);
	}
}
void move_neg(int sense,t_element *elem, t_list **list_a, t_list **list_b)
{
	int rank_move;
	int rank_list;
	
	rank_move = to_b_rank(elem->content,*list_b);
	rank_list = place_a_rank(place_elem_list(elem->content, *list_a), *list_a);
	if (sense == 1)
	{
		while(rank_move < 0)
		{
			if(rank_move++ < rank_list)
				rotate_ty('b', list_a, list_b);
			else
				rotate_ty('r', list_a, list_b);
		}
	}
	else
	{
		while(rank_list < 0)
		{
			if (rank_list++ < rank_move)
				rotate_ty('a',list_a, list_b);
			else
				rotate_ty('r', list_a,list_b);
		}
	}
}

void move_pos(int sense,t_element *elem, t_list **list_a, t_list **list_b)
{
	int rank_move;
	int rank_list;
	
	rank_move = to_b_rank(elem->content,*list_b);
	rank_list = place_a_rank(place_elem_list(elem->content, *list_a), *list_a);
	if (sense == 1)
	{
		while(rank_list > 0)
		{
			if(rank_list-- > rank_move)
				rev_rotate_ty('a', list_a, list_b);
			else
				rev_rotate_ty('r', list_a, list_b);
		}
	}
	else
	{
		while(rank_move < 0)
		{
			if (rank_move-- > rank_list)
				rev_rotate_ty('b',list_a, list_b);
			else
				rev_rotate_ty('r', list_a,list_b);
		}
	}
}
void move_mid(int sense,t_element *elem, t_list **list_a, t_list **list_b)
{
	int rank_move;
	int rank_list;
	
	rank_move = to_b_rank(elem->content,*list_b);
	rank_list = place_a_rank(place_elem_list(elem->content, *list_a), *list_a);
	if (sense == 1)
	{
		while(rank_move < rank_list)
		{
			if(rank_move++ < 0)
				rotate_ty('b', list_a, list_b);
			else
				rev_rotate_ty('a', list_a, list_b);
		}
	}
	else
	{
		while(rank_list < rank_move)
		{
			if (rank_list++ < 0)
			{
				//print_list(*list_a);
				//print_list(*list_b);
				//printf ("elem = %i rank =%i rank_list =%i rank_move =%i\n", elem->content,elem->rang,rank_list,rank_move);
				rotate_ty('a',list_a, list_b);
			}
			else
				rev_rotate_ty('b', list_a,list_b);
		}
	}
}

/*
rank_list = deplacement de a;
rank move = deplacement de b;
sense : 1 = rank_move < rank_list;
sense : 2 = rank_list < rank_move;
list_a list_
*/


/*void put_first_a_to_b(int elem_content_a,t_list **list_a,t_list **list_b)
{
int plus_grand;
int plus_petit;
int rev_or_rotate;

plus_grand = 0;
plus_petit = 0;
rev_or_rotate = betwen_elem_list_b_old(elem_content_a,*list_b);
if (elem_content_a > (*list_b)->first->content)
	plus_grand++;
if (elem_content_a < last_elem_list(*list_b)->content)
	plus_petit++;
if ((plus_petit == 1 && plus_grand == 1) || (plus_petit == 0 && plus_grand == 1 
	&& (*list_b)->first->content == max_elem_list(*list_b)) || (plus_petit == 1 
		&& plus_grand == 0 && last_elem_list(*list_b)->content == min_elem_list(*list_b)))
		push_ty('b',list_a,list_b);
else if (rev_or_rotate == 1)
		rev_rotate_ty('b',list_a, list_b);
else if (rev_or_rotate == 2)
		rotate_ty('b',list_a,list_b);
}
*/
void	put_first_b_to_a(int elem_content_b,t_list **list_a, t_list **list_b)
{
	int petit_debut;
	int grand_fin;
	int rev_or_rotate;

	petit_debut = 0;
	grand_fin = 0;
	rev_or_rotate = betwen_elem_list(elem_content_b, *list_a);
	if (elem_content_b < (*list_a)->first->content)
		petit_debut++;
	if (elem_content_b > last_elem_list(*list_a)->content)
		grand_fin++;
	if ((petit_debut == 1 && grand_fin == 1) || (petit_debut == 1 && grand_fin == 0 && (*list_a)->first->content == min_elem_list(*list_a)) || (petit_debut == 0 && grand_fin == 1 && (last_elem_list(*list_a)->content == max_elem_list(*list_a))))
		push_ty('a',list_a,list_b);
	else if (rev_or_rotate == 1)
			rotate_ty('a',list_a, list_b); 
	else if (rev_or_rotate == 2)
			rev_rotate_ty('a',list_a,list_b);
}


