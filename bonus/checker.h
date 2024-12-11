/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:43:46 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 18:21:48 by fernando         ###   ########.fr       */
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
void	clean_exit(t_stack **a, t_stack **b, int e, char *msg);
int		ft_strlen(const char *str);
int		ft_strcompare(char *s1, char *s2);
void	print_stack(t_stack *a, t_stack *b);

/*** Handle errors ***/
void	chk_enteros(int n, char num, int neg, t_stack **a);
void	chk_args(t_stack **a, char *str);

/*** Stack functions ***/
void	ft_free(t_stack **stc);
void	add_to_stack(t_stack **stc, int val);
int		stack_sorted(t_stack *a, t_stack *b);
int		stack_len(t_stack *a);
void	swap(t_stack **a);
void	sswap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	rrotate(t_stack **a, t_stack **b);
void	inv_rot(t_stack **a);
void	inv_rrot(t_stack **a, t_stack **b);
void	cmp_str(char *str, t_stack **a, t_stack **b);

/*** Get next Line ***/
char	*get_next_line(int fd, t_stack **a, t_stack **b);
char	*join_free(char *str, char buffer);

#endif
