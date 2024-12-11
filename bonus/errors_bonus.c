/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:54:51 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 18:30:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* It returns 1 if any node of the stack a has the value of n */
int	in_stack(t_stack *a, int n)
{
	t_stack	*aux;

	aux = a;
	while (aux != NULL)
	{
		if (aux->value == n)
			return (1);
		aux = aux->next;
	}
	return (0);
}

/* It sees if the next digit of the string gives a int number bigger or smaller 
   than the maximun integer or the minimun integer that is posible */
void	chk_enteros(int n, char num, int neg, t_stack **a)
{
	long int	res;

	res = (long int)(n * 10) + (long int)(num - '0');
	res *= neg;
	if (res > 2147483647 || res < -2147483648)
		clean_exit(a, NULL, -1, "Error\n");
}

/* It checks if the argument given is correct */
void	chk_args(t_stack **a, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] < '0' || str[i] > '9')
			clean_exit(a, NULL, -1, "Error\n");
		i++;
	}
	if (in_stack(*a, ft_atoi(a, &str[0])))
		clean_exit(a, NULL, -1, "Error\n");
}
