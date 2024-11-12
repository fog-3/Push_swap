/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:38 by fernando          #+#    #+#             */
/*   Updated: 2024/11/12 09:53:49 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

/*Se usa para liberar la memoria del stack*/
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

/*Crea un nuevo stack vacío*/
t_stack	*new_stack(int val)
{
	t_stack *nuevo;

	nuevo = (t_stack *)malloc(sizeof(t_stack));
	if (!nuevo)
		return (0);
	nuevo->value = val;
	nuevo->index = 0;
	nuevo->next = NULL;
	nuevo->prev = NULL;
	return(nuevo);
}

/*Añade un nodo con el valor que se le pasa por parámetro*/
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

//delete_from_stack
/*Función utilizada sobre todo para el debug, imprime los stack
 *que se le pasen por parámetro*/
void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*aux_a;
	t_stack *aux_b;

	aux_b = b;
	aux_a = a;
	while (aux_a != NULL)
	{
		ft_putnb(aux_a->value);
		write(1, "=", 1);
		ft_putnb(aux_a->index);
		if (aux_b != NULL)
		{
			write(1, " ", 1);
			ft_putnb(aux_b->value);
			aux_b = aux_b->next;
		}
		aux_a = aux_a->next;
		write(1, "\n", 1);
	}
	write (1, "- -\na b\n", 8);
}

/*Calcula la longitud del stack*/
int	stack_len(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->index + 1);
}
