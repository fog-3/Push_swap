
#include "pushswap.h"

int	parse_num(char *str, t_stack *a)
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
		stack_size += parse_num(argv[i], stack_a);
		i++;
	}
	return (0);
}
