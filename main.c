/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by fernando          #+#    #+#             */
/*   Updated: 2024/10/07 08:15:48 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int	parse_num(char *str, t_stack **a)
{
	int i;
	int bol;
	int	n;

	i = 0;
	bol = 1;
	n = 0;
	while (str[i])
	{
		if (bol && str[i] != ' ')
		{
			add_to_stack(a, ft_atoi(&str[i]));
			if (!a)
				clean_exit(a, 0);
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
	while (i < argc)
	{
		stack_size += parse_num(argv[i], &stack_a);
		i++;
	}
	//ft_sort(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
