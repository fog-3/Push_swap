/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by fernando          #+#    #+#             */
/*   Updated: 2024/11/16 18:40:11 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

/* void	ft_sort(t_stack **a, t_stack **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 1)
			swap(a);
		else if (stack_len(*a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
} */

int	parse_num(char *str, t_stack **a)
{
	int	i;
	int	bol;
	int	n;

	i = 0;
	bol = 1;
	n = 0;
	while (str[i])
	{
		if (bol && str[i] != ' ')
		{
			chk_args(a, &str[i]);
			add_to_stack(a, ft_atoi(a, &str[i]));
			if (!a)
				clean_exit(a, 0, 1);
			bol = 0;
			n++;
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
	int		stack_size;
	int		i;
	
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(1);
	while (i < argc)
	{
		stack_size += parse_num(argv[i], &stack_a);
		i++;
	}
	//ft_sort(&stack_a, &stack_b);
	swap(&stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	sswap(&stack_a, &stack_b);
	rrotate(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	inv_rrot(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
