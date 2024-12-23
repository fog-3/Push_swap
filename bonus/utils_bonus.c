/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:48:45 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 10:02:46 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(t_stack **a, const char *num)
{
	int			i;
	long int	res;
	int			neg;

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
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = (res * 10) + (num[i] - '0');
		chk_enteros(res, neg, a);
		i++;
	}
	return (res * neg);
}

/* This function frees all the memory wich is allocated in this program
* and finish the execution with the error value e
*/
void	clean_exit(t_stack **a, t_stack **b, int e, char *msg)
{
	write(2, msg, ft_strlen(msg));
	if (a != NULL)
		ft_free(a);
	if (b != NULL)
		ft_free(b);
	a = NULL;
	b = NULL;
	exit(e);
}

// It returns the length of the string
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* It compares two strings and returns the diference between each other */
int	ft_strcompare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
