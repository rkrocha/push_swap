/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 07:42:16 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/27 08:15:32 by rkochhan         ###   ########.fr       */
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

	if (num < peek_smallest_num(stack, TRUE))
		return (peek_smallest_num(stack, FALSE));
	if (num > peek_largest_num(stack, TRUE))
		return (peek_largest_num(stack, FALSE) + 1);
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
int	peek_smallest_num(t_stack *stack, t_bool return_num)
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

int	peek_largest_num(t_stack *stack, t_bool return_num)
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
