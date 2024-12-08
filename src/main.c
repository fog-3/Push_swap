/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by fernando          #+#    #+#             */
/*   Updated: 2024/12/08 14:15:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// This is the general function to order stacks with more than 5 nodes
void	push_swap(t_stack **a, t_stack **b)
{
	int		init_len;
	t_stack	*lowest_node;
	int		mean;

	init_len = stack_len(*a);
	mean = find_highest(*a)->value;
	mean = (mean + find_lowest(*a)->value) / 2;
	while (stack_len(*a) > 3)
	{
		push(b, a, 1);
		if (stack_len(*b) > 1 && (*b)->value > mean)
			rotate(b, 1);
	}
	tiny_sort(a);
	while (stack_len(*a) < init_len)
		ft_sort_general(a, b);
	lowest_node = find_lowest(*a);
	while (lowest_node->index > 0)
	{
		if (lowest_node->index > (init_len / 2))
			inv_rot(a, 0);
		else
			rotate(a, 0);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (!stack_sorted(*a))
	{
		if (len == 2)
			swap(a, 0);
		else if (len == 3)
			tiny_sort(a);
		else if (len <= 5)
			sort_five(a, b);
		else
			push_swap(a, b);
	}
}

void	parse_num(char *str, t_stack **a)
{
	int	i;
	int	bol;

	i = 0;
	bol = 1;
	while (str[i])
	{
		if (bol && str[i] != ' ')
		{
			chk_args(a, &str[i]);
			add_to_stack(a, ft_atoi(a, &str[i]));
			if (!a)
				clean_exit(a, 0, 1);
			bol = 0;
		}
		if (str[i] == ' ')
			bol = 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	while (i < argc)
	{
		parse_num(argv[i], &stack_a);
		i++;
	}
	ft_sort(&stack_a, &stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
