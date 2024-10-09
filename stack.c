/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:38 by fernando          #+#    #+#             */
/*   Updated: 2024/10/07 08:20:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

void	ft_free(t_stack **stc)
{
	
}

t_stack	*new_stack(int val)
{
	t_stack *nuevo;

	nuevo = (t_stack *)malloc(sizeof(t_stack));
	if (!nuevo)
		return (0);
	nuevo->value = val;
	nuevo->next = NULL;
	return(nuevo);
}

void	add_to_stack(t_stack **stc, int val)
{
	t_stack *new;
	t_stack *bottom;

	new = new_stack(val);
	if (!new)
		return ;
	if (!*stc)
	{
		*stc = new;
		return ;
	}
	bottom = *stc;
	
	bottom->next = new;	
}
//delete_from_stack
void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*aux_a;
	t_stack *aux_b;

	aux_b = b;
	aux_a = a;
	while (a != NULL)
	{
		ft_putnb(a->value);
		if (b != NULL)
		{
			write(1, " ", 1);
			ft_putnb(b->value);
			b = b->next;
		}
		a = a->next;
		write(1, "\n", 1);
	}
	write (1, "- -\na b\n", 8);
	b = aux_b;
	a = aux_a;
}
