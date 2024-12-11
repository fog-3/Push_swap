/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swpsh_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:41 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 18:28:13 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Usage: sa: swap(a, 0), sb: swap(b, 1)
void	swap(t_stack **a)
{
	t_stack	*aux1;
	t_stack	*aux2;

	if (!a || stack_len(*a) < 2)
		return ;
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
	swap(a);
	swap(b);
}

/* Return the first node of the stack whithout prev and next */
t_stack	*extract(t_stack **a)
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
	return (res);
}

/* Usage: pa = push(a, b, 0), y pb = push(b, a, 1) 
 * pa = moves the first node of the stack 'b' to the stack 'a'
 * pb = moves the first node of the stack 'a' to the stack 'b'
 */
void	push(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (!b)
		return ;
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
