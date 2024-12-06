/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swpsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:41 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 11:05:31 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Usage: sa: swap(a, 0), sb: swap(b, 1)
void	swap(t_stack **a, int n)
{
	t_stack	*aux1;
	t_stack	*aux2;
	
	if (stack_len(*a) < 2)
	{
		write(2, "Error: no se puede hacer swap a un stack con menos de 2 nodos\n", 62);
		return ;	
	}
	if (!n)
		write(1, "sa\n", 3);
	else if (n > 0)
		write(1, "sb\n", 3);
	aux1 = *a;
	aux2 = (*a)->next;
	aux1->next = aux2->next;
	if (aux2->next)
		aux2->next->prev = aux1;
	aux2->next = aux1;
	aux1->prev = aux2;
	aux2->prev = NULL;
	aux1->index = aux2->index;
	aux2->index = 0;
	*a = aux2;
}

//sswap(t_stack **a, t_stack **b): ss
void	sswap(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a, -1);
	swap(b, -1);
}

/* Return the first node of the stack whithout prev and next */
t_stack *extract(t_stack **a)
{
	t_stack	*res;
	
	res = *a;
	if (res->next == NULL)
	{
		*a = NULL;
		return (res);
	}
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

/* Usage: pa = push(a, b, 0), y pb = push(b, a, 1) 
 * pa = moves the first node of the stack 'b' to the stack 'a'
 * pb = moves the first node of the stack 'a' to the stack 'b'
 */
void	push(t_stack **a, t_stack **b, int n)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (!n)
		write(1, "pa\n", 3);
	else if (n > 0)
		write(1, "pb\n", 3);
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
