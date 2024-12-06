/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:38 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 14:33:52 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pushswap.h"

/* Funtion that free the memory use of the stack
 * that is pased as parameter 
 */
void	ft_free(t_stack **stc)
{
	t_stack *tmp;
	t_stack *aux;

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
	t_stack *nuevo;

	nuevo = (t_stack *)malloc(sizeof(t_stack));
	if (!nuevo)
		return (0);
	nuevo->value = val;
	nuevo->index = 0;
	nuevo->cost = 0;
	nuevo->target = 0;
	nuevo->next = NULL;
	nuevo->prev = NULL;
	return(nuevo);
}

/* Add a node with the value passed as parameter */
void	add_to_stack(t_stack **stc, int val)
{
	t_stack *new;
	t_stack *last_node;

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

/* Function that is used overall to debug, it prints the stack
 * that is passed as parameter.
 */
void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*aux_a;
	t_stack *aux_b;

	aux_b = b;
	aux_a = a;
	while (aux_a != NULL)
	{
		ft_putnb(aux_a->value);
		if (aux_b != NULL)
		{
			write(1, "\t", 1);
			ft_putnb(aux_b->value);
			aux_b = aux_b->next;
		}
		aux_a = aux_a->next;
		write(1, "\n", 1);
	}
	while (aux_b != NULL)
	{
		write(1, "\t\t", 1);
		ft_putnb(aux_b->value);
		aux_b = aux_b->next;
		write(1, "\n", 1);
	}
	write (1, " -\t -\n a\t b\n", 12);
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
