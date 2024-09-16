#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int 		value;
	int			index;
	//int		pos;
	//int		target;
	//int		cost_a;
	//int		cost_b;
	struct s_stack	*next;
	struct s_stack *prev;
} t_stack;

int ft_atoi(const char *nptr);
int	parse_num(char *str, t_stack *a);

#endif
