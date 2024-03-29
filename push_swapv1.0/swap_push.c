/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:43:52 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/05 19:22:02 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	swap(t_list *list)
{
	int temp;

	if (list && list->first && list->first->next)
	{
		temp = list->first->content;
		list->first->content = list->first->next->content;
		list->first->next->content = temp;
	}
}

void	push(t_list *list_send, t_list **list_receiv)
{
	t_element *new_elem;
	t_element *del_elem;
	
	new_elem = NULL;
	del_elem = NULL;
	if(list_send && list_send->first)
	{
		if(!(*list_receiv))
			*list_receiv = init_list(list_send->first->content);
		else
		{
			new_elem = malloc(sizeof(*new_elem));
			new_elem->content = list_send->first->content;
			new_elem->next = (*list_receiv)->first;
			(*list_receiv)->first = new_elem;
		}
		del_elem = list_send->first;
		list_send->first = list_send->first->next;
		free(del_elem);
	}
}

void	swap_ty(char type, t_list **list_a, t_list **list_b)
{
	if (type == 'a')
	{
		swap(*list_a);
		printf("sa\n");//ATTENTION VRAI PRINTF
	}
	if (type == 'b')
	{
		swap(*list_b);
		printf("sb\n");//ATTENTION VRAI PRINTF
	}
	if (type == 's')
	{
		swap(*list_a);
		swap(*list_b);
		printf("ss\n");//ATTENTION VRAI PRINTF
	}
}

void	push_ty(char type, t_list **list_a, t_list **list_b)
{
	if(type == 'a')
	{
		push(*list_b, list_a);
		printf("pa\n");//ATTENTION VRAI PRINTF
	}
	if(type == 'b')
	{
		push(*list_a, list_b);
		printf("pb\n");//ATTENTION VRAI PRINTF
	}
}

