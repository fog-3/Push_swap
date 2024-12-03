/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by fernando          #+#    #+#             */
/*   Updated: 2024/11/26 09:54:31 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

/* It gives the length of the stack */
int	stack_len(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->index + 1);
}

// This is the general function to order stacks with more than 5 nodes
void	push_swap(t_stack **a, t_stack **b)
{
	int 	init_len;
	t_stack	*lowest_node;

	init_len = stack_len(*a);
	while (stack_len(*a) > 3)
		push(b, a, 1);
	tiny_sort(a);
	while (stack_len(*a) < init_len)
	{
		target_node(*a, b);
		calc_cost(*a, b);
		mv_lowcost(a, b);
	}
	lowest_node = find_lowest(*a);
	while (lowest_node->index > 0)
	{
		if (lowest_node->index > (init_len/2))
			inv_rot(a, 0);
		else
			rotate(a, 0);
		lowest_node = find_lowest(*a);
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
		return(1);
	while (i < argc)
	{
		parse_num(argv[i], &stack_a);
		i++;
	}
	ft_sort(&stack_a, &stack_b);
	//print_stack(stack_a, stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
