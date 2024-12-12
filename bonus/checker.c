/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:18 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 09:57:42 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0, a, b);
	while (str)
	{
		cmp_str(str, a, b);
		free(str);
		str = NULL;
		str = get_next_line(0, a, b);
	}
	if (stack_sorted(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/* Parse the argument when it is a single number
* in other case it exits with an error message
*/
void	parse_num(char *num, t_stack **a_stack)
{
	chk_args(a_stack, num);
	add_to_stack(a_stack, ft_atoi(a_stack, num));
	if (!a_stack)
		clean_exit(a_stack, 0, 1, "Error: error allocating memory\n");
}

/* Parse the given string imput in case of be given between 
* quotation marks ("").
*/
void	parse_num_str(char *str, t_stack **a_stack)
{
	int	i;
	int	bol;

	i = 0;
	bol = 1;
	while (str[i])
	{
		if (bol && str[i] != ' ')
		{
			chk_args(a_stack, &str[i]);
			add_to_stack(a_stack, ft_atoi(a_stack, &str[i]));
			if (!a_stack)
				clean_exit(a_stack, 0, 1, "Error: error allocating memory\n");
			bol = 0;
		}
		if (str[i] == ' ')
			bol = 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		i;

	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc > 2)
	{
		while (i < argc)
			parse_num(argv[i++], &a_stack);
	}
	else
		parse_num_str(argv[i], &a_stack);
	ft_checker(&a_stack, &b_stack);
	ft_free(&a_stack);
	ft_free(&b_stack);
	return (0);
}
