/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:43:46 by fernando          #+#    #+#             */
/*   Updated: 2024/12/09 21:35:22 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*** Utils  ***/
int		ft_atoi(t_stack **a, const char *num);
void	clean_exit(t_stack **a, t_stack **b, int e);

/*** Handle errors ***/
void	chk_enteros(int n, char num, int neg, t_stack **a);
void	chk_args(t_stack **a, char *str);

/*** Stack functions ***/
void	ft_free(t_stack **stc);
void	add_to_stack(t_stack **stc, int val);
int		stack_sorted(t_stack *a);

#endif