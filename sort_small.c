/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:22:45 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/06 09:46:34 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_two(t_data *frame)
{
	op_sa(frame);
}

void	sort_three(t_data *frame)
{
	if (value(A_STACK.top) > value(A_STACK.top->next)
		&& value(A_STACK.top->next) < value(A_STACK.bottom)
		&& value(A_STACK.bottom) > value(A_STACK.top))
		op_sa(frame);
	else if (value(A_STACK.top) > value(A_STACK.top->next)
		&& value(A_STACK.top->next) > value(A_STACK.bottom)
		&& value(A_STACK.bottom) < value(A_STACK.top))
	{
		op_sa(frame);
		op_rra(frame);
	}
	else if (value(A_STACK.top) > value(A_STACK.top->next)
		&& value(A_STACK.top->next) < value(A_STACK.bottom)
		&& value(A_STACK.bottom) < value(A_STACK.top))
		op_ra(frame);
	else if (value(A_STACK.top) < value(A_STACK.top->next)
		&& value(A_STACK.top->next) > value(A_STACK.bottom)
		&& value(A_STACK.bottom) > value(A_STACK.top))
	{
		op_sa(frame);
		op_ra(frame);
	}
	else
		op_rra(frame);
}

void	sort_four_five(t_data *frame)
{
	int	num_pos[2];

	op_pb(frame);
	op_pb(frame);
	if (stack_issorted(&A_STACK) == false)
		sort_small(frame);
	if (value(B_STACK.top) > value(B_STACK.bottom))
		op_sb(frame);
	num_pos[0] = peek_num_position(&A_STACK, value(B_STACK.top));
	op_pa_in_num_pos(num_pos[0], frame);
	num_pos[1] = peek_num_position(&A_STACK, value(B_STACK.bottom));
	op_pa_in_num_pos(num_pos[1], frame);
	op_nra(peek_lowest_num_position(&A_STACK), frame);
}

void	sort_small(t_data *frame)
{
	if (A_STACK.len == 2)
		sort_two(frame);
	else if (A_STACK.len == 3)
		sort_three(frame);
	else
		sort_four_five(frame);
}
