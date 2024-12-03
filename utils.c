/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:31 by fernando          #+#    #+#             */
/*   Updated: 2024/10/22 18:46:23 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putnb(int val)
{
	char	c;

	if(val == -2147483648){
		write(1, "-2147483648", 11);
		return ;
	}
	if (val < 0)
	{
		val *= -1;
		write(1, "-", 1);
	}
	if (val > 9)
	{
		ft_putnb(val/10);
	}
	c = val % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(t_stack **a, const char *nptr)
{
	int	res;
	int	neg;
	int	i;

	neg = 1;
	res = 0;
	i = 0;
	while (nptr[i] == '\n' || nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		neg *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		chk_enteros(res, nptr[i], neg, a);
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

void	clean_exit(t_stack **a,  t_stack **b, int e)
{
	if (a != NULL)
		ft_free(a);
	if (b != NULL)
		ft_free(b);
	a = NULL;
	b = NULL;
	exit(e);
}
