#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int 		value;
	int		index;
	int		pos;
	int		target;
	int		cost_a;
	int		cost_b;
	struct s_stack	*next;
} t_stack;

#endif
