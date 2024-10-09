/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:45 by fernando          #+#    #+#             */
/*   Updated: 2024/10/07 08:16:45 by fernando         ###   ########.fr       */
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

int 	ft_atoi(const char *nptr);
void	print_stack(t_stack *a, t_stack *b);
int		parse_num(char *str, t_stack **a);
void	clean_exit(t_stack **a,  t_stack **b);
t_stack	*new_stack(int val);
void	add_to_stack(t_stack **stc, int val);
void	ft_free(t_stack **stc);

#endif
