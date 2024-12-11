/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:18:47 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 18:14:12 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Funtion that free the memory use of the stack
 * that is pased as parameter 
 */
void	ft_free(t_stack **stc)
{
	t_stack	*tmp;
	t_stack	*aux;

	if (!*stc)
		return ;
	aux = *stc;
	while (aux)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*stc = NULL;
}

/* Create a new empty node */
t_stack	*new_stack(int val)
{
	t_stack	*nuevo;

	nuevo = (t_stack *)malloc(sizeof(t_stack));
	if (!nuevo)
		return (0);
	nuevo->value = val;
	nuevo->index = 0;
	nuevo->next = NULL;
	nuevo->prev = NULL;
	return (nuevo);
}

/* Add a node with the value passed as parameter */
void	add_to_stack(t_stack **stc, int val)
{
	t_stack	*new;
	t_stack	*last_node;

	new = new_stack(val);
	if (!new)
		return ;
	if (*stc == NULL)
	{
		*stc = new;
		return ;
	}
	last_node = *stc;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new->prev = last_node;
	new->index = last_node->index + 1;
	last_node->next = new;
}

// Return 1 if the stack is sorted and 0 if it isn't
int	stack_sorted(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	if (b != NULL)
		return (0);
	return (1);
}

/* It gives the length of the stack */
int	stack_len(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
		a = a->next;
	return (a->index + 1);
}
