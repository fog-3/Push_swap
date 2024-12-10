/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:46:56 by fernando          #+#    #+#             */
/*   Updated: 2024/12/08 14:40:15 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Compares the node a with the node b and the val catched in the other function
int	aux_target_node(t_stack *a, t_stack *b, int best_val)
{
	if (a->value > b->value && best_val == b->value)
	{
		b->target = a->index;
		best_val = a->value;
	}
	else if (a->value > b->value && best_val > a->value)
	{
		best_val = a->value;
		b->target = a->index;
	}
	return (best_val);
}

// Gives a target node to each node of b
void	target_node(t_stack *a, t_stack **b)
{
	t_stack	*aux_b;
	t_stack	*aux_a;
	int		best_val;

	aux_b = *b;
	aux_a = a;
	while (aux_b)
	{
		best_val = aux_b->value;
		while (aux_a)
		{
			best_val = aux_target_node(aux_a, aux_b, best_val);
			aux_a = aux_a->next;
		}
		if (aux_b->value == best_val)
			aux_b->target = find_lowest(a)->index;
		aux_a = a;
		aux_b = aux_b->next;
	}
}

/* Auxiliar function to change the values of the target node */
int	lc_target(int target, int init_len)
{
	if (target == init_len - 1)
		target = 0;
	else
		target += 1;
	return (target);
}

/* Auxiliar function of mv_lowcost */
void	ft_conditions(t_stack *lc_node, t_stack **a, t_stack **b, int a_len)
{
	if (lc_node->index > (stack_len(*b) / 2) && lc_node->target > (a_len / 2))
	{
		inv_rrot(a, b);
		lc_node->target = lc_target(lc_node->target, a_len);
	}
	else if (lc_node->index > (stack_len(*b) / 2))
		inv_rot(b, 1);
	else if (lc_node->target > (a_len / 2))
	{
		inv_rot(a, 0);
		lc_node->target = lc_target(lc_node->target, a_len);
	}
	else if (lc_node->target > 0 && lc_node->index > 0)
	{
		rrotate(a, b);
		lc_node->target -= 1;
	}
	else if (lc_node->index > 0)
		rotate(b, 1);
	else if (lc_node->target > 0)
	{
		rotate(a, 0);
		lc_node->target -= 1;
	}
}

/* Function that moves the node that has the lower cost from b to a
*/
void	mv_lowcost(t_stack **a, t_stack **b)
{
	t_stack	*lc_node;
	int		init_len;

	lc_node = find_low_cost(*b);
	init_len = stack_len(*a);
	while (stack_len(*a) <= init_len)
	{
		ft_conditions(lc_node, a, b, init_len);
		if (lc_node->index == 0 && lc_node->target == 0)
			push(a, b, 0);
	}
}
