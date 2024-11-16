/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swpsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:41 by fernando          #+#    #+#             */
/*   Updated: 2024/11/13 18:44:03 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Sirve para: sa(t_stack **a), sb(t_stack **b)
void	swap(t_stack **a)
{
	t_stack	*aux1;
	t_stack	*aux2;
	
	if (stack_len(*a) < 2)
	{
		write(2, "Error: no se puede hacer swap a un stack con menos de 2 nodos\n", 62);
		return ;	
	}
	aux1 = *a;
	aux2 = (*a)->next;
	aux1->next = aux2->next;
	aux2->next = aux1;
	aux1->prev = aux2;
	aux2->prev = NULL;
	aux1->index = aux2->index;
	aux2->index = 0;
	*a = aux2;
}

//ss(t_stack **a, t_stack **b)
void	sswap(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

/* Devuelve el primer nodo del stack desvinculado */
t_stack *extract(t_stack **a)
{
	t_stack	*res;
	
	res = *a;
	res = res->next;
	while (res)
	{
		res->index--;
		res = res->next;
	}
	res = *a;
	(*a) = (*a)->next;
	(*a)->prev = NULL;
	res->next = NULL;
	return(res);
}

//Sirve para: pa, y pb
void	push(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	aux_a = *a;
	aux_b = extract(b);
	if (aux_a == NULL)
	{
		*a = aux_b;
		return ;
	}
	aux_a->prev = aux_b;
	aux_b->next = aux_a;
	while (aux_a)
	{
		aux_a->index++;
		aux_a = aux_a->next;
	}
	*a = aux_b;
}
