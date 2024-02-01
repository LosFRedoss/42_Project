/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:38:18 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/01 22:11:45 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*add_list(t_list *list, int elem_int);

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		*int_list;
	int		i;

	i = 1;
	int_list = tester(&argc, argv);
	if (!int_list)
		return (0);
	list_a = init_list(int_list[0]);
	list_b = NULL;
	while (i < argc)
		add_list(list_a,int_list[i++]);
	free(int_list);
	apply_rules(&list_a, &list_b);
	}

t_list	*init_list(int elem_int)
{
	t_list *list_a = malloc(sizeof(*list_a));
	t_element *element = malloc(sizeof(*element));
	
	if (!list_a || !element)
		return(NULL);
	element->content = elem_int;
	element->rang = 0;
	element->next = NULL;
	list_a->first = element;
	return (list_a);
}

t_list	*add_list(t_list *list, int elem_int)
{
	t_element *element = malloc (sizeof(*element));
	t_element *lst_temp;

	if(!element)
		return(NULL);
	if(!list)
		list = init_list(elem_int);
	else
	{
		element->content = elem_int;
		element->rang = 0;
		element->next = NULL;
		lst_temp = list->first;
		while (lst_temp -> next)
			lst_temp = lst_temp -> next;
		lst_temp->next = element;
	}
	return (list);
}

void	free_list(t_list *list)
{
	t_element *del_elem;

	if (list)
	{
		while (list->first != NULL)
		{
			del_elem = list->first;
			list->first = list->first->next;
			free(del_elem);
		}
		free(list);
	}
}

void	print_list(t_list *list)
{
	t_element *print_elem;

	if(list)
	{
		print_elem = list->first;
		while (print_elem)
		{
			printf("%i, ", print_elem->content);
			print_elem = print_elem->next;
		}
		printf("\n");
	}
}




/*Commencer par faire un testeur de variable, voir si tout est bien en ordre,
mettre chacune des variable dans la pile a */