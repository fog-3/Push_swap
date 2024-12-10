/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:08:20 by fernando          #+#    #+#             */
/*   Updated: 2024/12/08 14:40:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//rotate(t_stack **a): ra = rotate(a, 0)
// and rb = rotate(b, 1)
void	rotate(t_stack **a, int n)
{
	t_stack	*ini;
	t_stack	*res;

	if (!n)
		write(1, "ra\n", 3);
	else if (n > 0)
		write(1, "rb\n", 3);
	res = *a;
	ini = (*a)->next;
	ini->prev = NULL;
	while (res->next)
	{
		res->index--;
		res = res->next;
	}
	res->next = *a;
	(*a)->index = res->index;
	res->index--;
	(*a)->prev = res;
	(*a)->next = NULL;
	*a = ini;
}

//rrotate(t_stack **a, t_stack **b): for rr
void	rrotate(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a, -1);
	rotate(b, -1);
}

//inv_rot(t_stack **a): rra = inv_rot(a, 0)
// and rrb = inv_rot(b, 1)
void	inv_rot(t_stack **a, int n)
{
	t_stack	*res;
	t_stack	*ini;

	if (!n)
		write(1, "rra\n", 4);
	else if (n > 0)
		write(1, "rrb\n", 4);
	ini = *a;
	res = *a;
	while (res->next)
	{
		res->index++;
		res = res->next;
	}
	res->prev->next = NULL;
	ini->prev = res;
	res->next = ini;
	res->index = 0;
	res->prev = NULL;
	*a = res;
}

//inv_rrot(t_stack **a, t_stack **b): for rrr
void	inv_rrot(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	inv_rot(a, -1);
	inv_rot(b, -1);
}
