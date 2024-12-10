/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:28:49 by fosuna-g          #+#    #+#             */
/*   Updated: 2024/12/08 14:39:57 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Calculates the cost of every node of b to goes over the node a
 * cost = cost_to_be_indx_0_b + cost_to_be_indx_0_a
*/
void	calc_cost(t_stack *a, t_stack **b)
{
	t_stack	*aux;
	int		a_len;
	int		b_len;
	int		cost_a;

	aux = *b;
	cost_a = 0;
	a_len = stack_len(a);
	b_len = stack_len(*b);
	while (aux)
	{
		if (aux->target > (a_len / 2))
			cost_a = a_len - aux->target;
		else
			cost_a = aux->target;
		if (aux->index > (b_len / 2))
			aux->cost = b_len - aux->index + cost_a;
		else
			aux->cost = aux->index + cost_a;
		aux = aux->next;
	}
}

// Function that gives the node with the lower cost
t_stack	*find_low_cost(t_stack *a)
{
	t_stack	*res;

	res = a;
	while (a != NULL)
	{
		if (a->cost < res->cost)
			res = a;
		a = a->next;
	}
	return (res);
}

/* It do all the important things to short the algorithm
*/
void	ft_sort_general(t_stack **a, t_stack **b)
{
	target_node(*a, b);
	calc_cost(*a, b);
	mv_lowcost(a, b);
}
