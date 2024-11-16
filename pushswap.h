/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:45 by fernando          #+#    #+#             */
/*   Updated: 2024/11/14 14:31:36 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/***	Utils	***/
int 	ft_atoi(t_stack **a, const char *nptr);
int		parse_num(char *str, t_stack **a);
void	ft_putnb(int val);
t_stack *extract(t_stack **a);

/***	Stack creation	***/
void	print_stack(t_stack *a, t_stack *b);
t_stack	*new_stack(int val);
void	add_to_stack(t_stack **stc, int val);
void	ft_free(t_stack **stc);
int		stack_len(t_stack *a);

/***	Handle errors	***/
void	chk_enteros(int n, char num, int neg, t_stack **a);
void	chk_args(t_stack **a, char *str);
void	clean_exit(t_stack **a,  t_stack **b, int e);

/***	Operations	***/
void	swap(t_stack **a);
void	sswap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	rrotate(t_stack **a, t_stack **b);
void	inv_rot(t_stack **a);
void	inv_rrot(t_stack **a, t_stack **b);

#endif
