/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:29:30 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 20:44:56 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}t_data;

int		check_argument(int argc, char **argv);
void	assign_value(int argc, char **argv, t_data *data);
int		check_sort(t_data *data);
void	radix(t_data *data);
int		sa_rra(t_data *data);
void	small_sort(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rr(t_data *data);
void	rb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif
