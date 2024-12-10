/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:06:47 by fernando          #+#    #+#             */
/*   Updated: 2024/12/08 14:40:41 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* It returns the node with the highest value */
t_stack	*find_highest(t_stack *a)
{
	t_stack	*res;

	res = a;
	while (a)
	{
		if (res->value < a->value)
			res = a;
		a = a->next;
	}
	return (res);
}

/* It returns the node with the lowest value */
t_stack	*find_lowest(t_stack *a)
{
	t_stack	*res;

	res = a;
	while (a)
	{
		if (res->value > a->value)
			res = a;
		a = a->next;
	}
	return (res);
}

// To sort a stack of 3 nodes.
void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		rotate(a, 0);
	else if ((*a)->next == highest_node)
		inv_rot(a, 0);
	if ((*a)->value > (*a)->next->value)
		swap(a, 0);
}

// Return 1 if the stack is sorted and 0 if it isn't
int	stack_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

/* Sort a stack with less than 5 nodes */
void	sort_five(t_stack **a, t_stack **b)
{
	int		len;
	int		cnt;
	t_stack	*lowest_node;

	len = stack_len(*a);
	cnt = len;
	while (len > 3)
	{
		lowest_node = find_lowest(*a);
		if (lowest_node->index != 0)
		{
			if (lowest_node->index > (len / 2))
				inv_rot(a, 0);
			else
				rotate(a, 0);
		}
		else
			push(b, a, 1);
		len = stack_len(*a);
	}
	tiny_sort(a);
	if (cnt == 5)
		push(a, b, 0);
	if (cnt > 3)
		push(a, b, 0);
}
