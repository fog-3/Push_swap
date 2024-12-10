/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:18 by fernando          #+#    #+#             */
/*   Updated: 2024/12/09 21:38:50 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker(t_stack **a, t_stack **b)
{
	//loop until get next line returns null
	//Get next line
	//compare and do all you have to do
	//check if the stack is sorted at the end of the loop
}

/* Parse the argument when it is a single number
* in other case it exits with an error message
*/
void	parse_num(char *num, t_stack **a_stack)
{
	chk_args(a_stack, num);
	add_to_stack(a_stack, ft_atoi(a_stack, num));
	if (!a_stack)
		clean_exit(a_stack, 0, 1);
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
				clean_exit(a_stack, 0, 1);
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
		return (1);
	if (argc > 2)
	{
		while (argc > i++)
			parse_num(argv[i], &a_stack);
	}
	else
		parse_num_str(argv[i], &a_stack);
	ft_checker(&a_stack, &b_stack);
	ft_free(&a_stack);
	ft_free(&b_stack);
	return (0);
}
