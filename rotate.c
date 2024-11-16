#include "pushswap.h"

//rotate(t_stack **a): para ra y rb
void	rotate(t_stack **a)
{
	t_stack	*ini;
	t_stack	*res;

	res = *a;
	ini = (*a)->next;
	ini->prev = NULL;
	while (res->next)
	{
		res->index--;
		res = res->next;
	}
	res->next = *a;
	(*a)->index = res->index;
	res->index--;
	(*a)->prev = res;
	(*a)->next = NULL;
	*a = ini;
}

//rrotate(t_stack **a, t_stack **b): para rr
void	rrotate(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}

//inv_rot(t_stack **a): para rra y rrb
void	inv_rot(t_stack **a)
{
	t_stack	*res;
	t_stack	*ini;

	ini = *a;
	res = *a;
	while (res->next)
	{
		res->index++;
		res = res->next;
	}
	res->prev->next = NULL;
	ini->prev = res;
	res->next = ini;
	res->index = 0;
	res->prev = NULL;
	*a = res;
}

//inv_rrot(t_stack **a, t_stack **b): para rrr
void	inv_rrot(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	inv_rot(a);
	inv_rot(b);
}
