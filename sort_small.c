/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:22:45 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/27 08:15:32 by rkochhan         ###   ########.fr       */
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
	if (value(frame->a_stack.top) > value(frame->a_stack.top->next)
		&& value(frame->a_stack.top->next) < value(frame->a_stack.bottom)
		&& value(frame->a_stack.bottom) > value(frame->a_stack.top))
		op_sa(frame);
	else if (value(frame->a_stack.top) > value(frame->a_stack.top->next)
		&& value(frame->a_stack.top->next) > value(frame->a_stack.bottom)
		&& value(frame->a_stack.bottom) < value(frame->a_stack.top))
	{
		op_sa(frame);
		op_rra(frame);
	}
	else if (value(frame->a_stack.top) > value(frame->a_stack.top->next)
		&& value(frame->a_stack.top->next) < value(frame->a_stack.bottom)
		&& value(frame->a_stack.bottom) < value(frame->a_stack.top))
		op_ra(frame);
	else if (value(frame->a_stack.top) < value(frame->a_stack.top->next)
		&& value(frame->a_stack.top->next) > value(frame->a_stack.bottom)
		&& value(frame->a_stack.bottom) > value(frame->a_stack.top))
	{
		op_sa(frame);
		op_ra(frame);
	}
	else
		op_rra(frame);
}

void	sort_four_five(t_data *frame)
{
	int	num_pos;

	op_pb(frame);
	op_pb(frame);
	if (stack_issorted(&frame->a_stack) == FALSE)
		sort_small(frame);
	num_pos = peek_num_position(&frame->a_stack, value(frame->b_stack.top));
	op_pa_in_num_pos(num_pos, frame);
	num_pos = peek_num_position(&frame->a_stack, value(frame->b_stack.top));
	op_pa_in_num_pos(num_pos, frame);
	op_nra(peek_smallest_num(&frame->a_stack, FALSE), frame);
}

void	sort_small(t_data *frame)
{
	if (frame->a_stack.len == 2)
		sort_two(frame);
	else if (frame->a_stack.len == 3)
		sort_three(frame);
	else
		sort_four_five(frame);
}
