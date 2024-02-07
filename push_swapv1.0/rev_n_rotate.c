/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_n_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:32:03 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/05 19:48:11 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void rotate(t_list *list)
{
	int int_temp;
	t_element *point_elem;
	t_element *point_sec_elem;

	if (list && list->first && list->first->next)
	{
		point_elem = list->first;
		point_sec_elem= list->first->next;
		int_temp = point_elem->content;
		point_elem->content = point_sec_elem->content;
		while (point_sec_elem->next)
		{
			point_elem = point_elem->next;
			point_sec_elem = point_sec_elem->next;
			point_elem->content = point_sec_elem->content;
		}
		point_sec_elem->content = int_temp;
	};
}

void rev_rotate(t_list *list)
{
	int temp;
	t_element *point_elem;
	t_element *point_sec_elem;
	
	if (list && list->first && list->first->next)
	{
		point_elem = list->first;
		point_sec_elem = list->first->next;
		while (point_sec_elem->next)
		{
			temp = point_sec_elem->content;
			point_sec_elem->content = list->first->content;
			list->first->content = temp;
			point_elem = point_elem->next;
			point_sec_elem = point_sec_elem->next;
		}
		temp = point_sec_elem->content;
		point_sec_elem->content = list->first->content;
		list->first->content = temp;
	}
}

void rotate_ty(char type, t_list **list_a, t_list **list_b)
{
	if (type == 'a')
	{
		rotate(*list_a);
		printf("ra\n");
	}
	else if (type == 'b')
	{
		rotate(*list_b);
		printf("rb\n");
	}
	else if (type == 'r')
	{
		rotate(*list_a);
		rotate(*list_b);
		printf("rr\n");
	}
	else
		printf("ERREUR DE TYPE ROTATE");
}
void rev_rotate_ty(char type, t_list **list_a, t_list **list_b)
{
	if (type == 'a')
	{
		rev_rotate(*list_a);
		printf("rra\n");
	}
	else if (type == 'b')
	{
		rev_rotate(*list_b);
		printf("rrb\n");
	}
	else if (type == 'r')
	{
		rev_rotate(*list_a);
		rev_rotate(*list_b);
		printf("rrr\n");
	}
	else
		printf("ERREUR DE TYPE REV_ROTATE");
}
