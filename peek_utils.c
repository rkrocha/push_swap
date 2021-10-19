/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 07:42:16 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/15 13:20:45 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Returns the position where a number 'num' should be placed in a stack which
** is already sorted in ascending order.
*/
int	peek_num_position(t_stack *stack, int num)
{
	int		pos;
	t_dlist	*tracker;

	if (num < peek_smallest_num(stack, true))
		return (peek_smallest_num(stack, false));
	if (num > peek_largest_num(stack, true))
		return (peek_largest_num(stack, false) + 1);
	if (stack_issorted(stack) && num < value(stack->top))
		return (0);
	if (stack_issorted(stack) && num > value(stack->bottom))
		return (-1);
	tracker = stack->top->next;
	pos = 1;
	while (tracker)
	{
		if (num > value(tracker->prev) && num < value(tracker))
			break ;
		tracker = tracker->next;
		pos++;
	}
	return (pos);
}

/*
** Returns the position of the smallest number in a stack.
*/
int	peek_smallest_num(t_stack *stack, bool return_num)
{
	t_dlist	*tracker;
	int		smallest_num;
	int		smallest_pos;
	int		i;

	tracker = stack->top->next;
	smallest_num = value(stack->top);
	smallest_pos = 0;
	i = 0;
	while (tracker)
	{
		i++;
		if (smallest_num > value(tracker))
		{
			smallest_num = value(tracker);
			smallest_pos = i;
		}
		tracker = tracker->next;
	}
	if (return_num)
		return (smallest_num);
	return (smallest_pos);
}

int	peek_largest_num(t_stack *stack, bool return_num)
{
	t_dlist	*tracker;
	int		largest_num;
	int		largest_pos;
	int		i;

	tracker = stack->top->next;
	largest_num = value(stack->top);
	largest_pos = 0;
	i = 0;
	while (tracker)
	{
		i++;
		if (largest_num < value(tracker))
		{
			largest_num = value(tracker);
			largest_pos = i;
		}
		tracker = tracker->next;
	}
	if (return_num)
		return (largest_num);
	return (largest_pos);
}

static int	peek_single_lis(t_stack *stack, t_dlist *tracker)
{
	int		lis;
	int		num;
	int		i;

	lis = 0;
	num = value(tracker);
	i = 0;
	while (i < stack->len)
	{
		if (value(tracker) > num)
		{
			num = value(tracker);
			lis++;
		}
		if (tracker->next)
			tracker = tracker->next;
		else
			tracker = stack->top;
		i++;
	}
	return (lis);
}

void	peek_lis(t_stack *stack, t_data *frame)
{
	t_dlist	*tracker;
	int		temp_lis;

	tracker = stack->top;
	while (tracker)
	{
		temp_lis = peek_single_lis(&A_STACK, tracker);
		if (temp_lis > frame->lis)
			frame->lis = temp_lis;
		tracker = tracker->next;
	}
}

static int	peek_single_lds(t_stack *stack, t_dlist *tracker)
{
	int		lds;
	int		num;
	int		i;

	lds = 0;
	num = value(tracker);
	i = 0;
	while (i < stack->len)
	{
		if (value(tracker) < num)
		{
			num = value(tracker);
			lds++;
		}
		if (tracker->next)
			tracker = tracker->next;
		else
			tracker = stack->top;
		i++;
	}
	return (lds);
}

void	peek_lds(t_stack *stack, t_data *frame)
{
	t_dlist	*tracker;
	int		temp_lds;

	tracker = stack->top;
	while (tracker)
	{
		temp_lds = peek_single_lds(&A_STACK, tracker);
		if (temp_lds > frame->lds)
			frame->lds = temp_lds;
		tracker = tracker->next;
	}
}
