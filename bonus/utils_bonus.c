/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:48:45 by fernando          #+#    #+#             */
/*   Updated: 2024/12/09 21:05:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(t_stack **a, const char *num)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (num[i] == '\n' || num[i] == ' ' || num[i] == '\t'
		|| num[i] == '\v' || num[i] == '\f' || num[i] == '\r')
		i++;
	if (num[i] == '-')
		neg *= -1;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i] >= '0' && num <= '9')
	{
		chk_enteros(res, num[i], neg, a);
		res = (res * 10) + (num[i] - '0');
		i++;
	}
	return (res * neg);	
}

/* This function frees all the memory wich is allocated in this program
* and finish the execution with the error value e
*/
void	clean_exit(t_stack **a, t_stack **b, int e)
{
	if (a != NULL)
		ft_free(a);
	if (b != NULL)
		ft_free(b);
	a = NULL;
	b = NULL;
	exit(e);
}
