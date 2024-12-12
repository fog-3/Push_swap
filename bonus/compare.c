/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:44:50 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 09:57:07 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* It compares all the posible instructions and if the instruction given
 * is not in this set the program will end and print Error message on stderr
*/
void	cmp_str(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcompare(str, "sa\n"))
		swap(a);
	else if (!ft_strcompare(str, "sb\n"))
		swap(b);
	else if (!ft_strcompare(str, "ss\n"))
		sswap(a, b);
	else if (!ft_strcompare(str, "pa\n"))
		push(a, b);
	else if (!ft_strcompare(str, "pb\n"))
		push(b, a);
	else if (!ft_strcompare(str, "ra\n"))
		rotate(a);
	else if (!ft_strcompare(str, "rb\n"))
		rotate(b);
	else if (!ft_strcompare(str, "rr\n"))
		rrotate(a, b);
	else if (!ft_strcompare(str, "rra\n"))
		inv_rot(a);
	else if (!ft_strcompare(str, "rrb\n"))
		inv_rot(b);
	else if (!ft_strcompare(str, "rrr\n"))
		inv_rrot(a, b);
	else
		clean_exit(a, b, -1, "Error\n");
}

void	ft_putnb(int val)
{
	char	c;

	if (val == -2147483648)
	{
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
		ft_putnb(val / 10);
	}
	c = val % 10 + '0';
	write(1, &c, 1);
}

/* Function that is used overall to debug, it prints the stack
 * that is passed as parameter.
 */
void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

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
