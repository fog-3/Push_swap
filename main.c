/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by fernando          #+#    #+#             */
/*   Updated: 2024/11/19 08:28:50 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

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
/* 		else
			push_swap(a, b); */
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
	print_stack(stack_a, stack_b);
	ft_sort(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
