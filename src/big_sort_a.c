/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:22:04 by fosuna-g          #+#    #+#             */
/*   Updated: 2024/12/06 17:10:58 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Gives a target node to each node of a
void    target_node_a(t_stack *b, t_stack **a)
{
    t_stack *aux_a;
    t_stack *aux_b;
    int     cmp;
    
    aux_a = *a;
    while (aux_a)
    {
        cmp = aux_a->value;
        aux_b = b;
        while (aux_b)
        {
            if (aux_a->value > aux_b->value && cmp < aux_b->value)
            {
                aux_a->target = aux_b->index;
                cmp = aux_b->value;
            }
            else if (aux_a->value > aux_b->value && aux_a->value == cmp)
            {
                aux_a->target = aux_b->index;
                cmp = aux_b->value;
            }
            aux_b = aux_b->next;
        }
        if (aux_a->value == cmp)
            aux_a->target = find_highest(b)->index;
/*         write(1, "El target de (", 14);
        ft_putnb(aux_a->value);
        write(1, ") es :", 6);
        ft_putnb(aux_a->target);
        write(1, "\n", 1); */
        aux_a = aux_a->next;
    }
}

/* Auxiliar function of mv_lowcost */
void	ft_conditions_a(t_stack *lc_node, t_stack **a, t_stack **b, int b_len)
{
	if(lc_node->index > (stack_len(*a)/2) && lc_node->target > (b_len/2))
	{
		inv_rrot(a, b);
		lc_node->target = lc_target(lc_node->target, b_len);
	}
	else if (lc_node->index > (stack_len(*a)/2))
		inv_rot(a, 0);
	else if (lc_node->target > (b_len/2))
	{
		inv_rot(b, 1);
		lc_node->target = lc_target(lc_node->target, b_len);
	}
	else if (lc_node->target > 0 && lc_node->index > 0)
	{
		rrotate(a, b);
		lc_node->target -= 1;
	}
	else if (lc_node->index > 0)
		rotate(a, 0);
	else if (lc_node->target > 0)
	{
		rotate(b, 1);
		lc_node->target -= 1;
	}
}

/* Function that moves the node that has the lower cost from a to b
*/
void	mv_lowcost_a(t_stack **a, t_stack **b)
{
	t_stack	*lc_node;
	int		init_len;

	lc_node = find_low_cost(*a);
/*     write(1, "El nodo con menos coste es : ", 29);
    ft_putnb(lc_node->value); */
	init_len = stack_len(*b);
	while (stack_len(*b) <= init_len)
	{
		ft_conditions_a(lc_node, a, b, init_len);
		if (lc_node->index == 0 && lc_node->target == 0)
			push(b, a, 1);
	}
}

