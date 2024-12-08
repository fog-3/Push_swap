/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:50:00 by fernando          #+#    #+#             */
/*   Updated: 2024/12/08 14:14:13 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*Devuelve 1 si existe el número dentro del stack*/
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

/*Mira si el entero más el siguiente dígito de la cadena de carácteres
  es menor o mayor que el máximo o mínimo entero posible*/
void	chk_enteros(int n, char num, int neg, t_stack **a)
{
	long int	res;

	res = (long int)(n * 10) + (long int)(num - '0');
	res *= neg;
	if (res > 2147483647 || res < -2147483648)
	{
		write(2, "Error\n", 6);
		clean_exit(a, NULL, 1);
	}
}

/*Chequea que el argumento que se está pasando sea correcto en el
  caso de que no imprime el mensaje de error y termina la ejecución*/
void	chk_args(t_stack **a, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			clean_exit(a, NULL, 1);
		}
		i++;
	}
	if (in_stack(*a, ft_atoi(a, &str[0])))
	{
		write(2, "Error\n", 6);
		clean_exit(a, NULL, 1);
	}
}
