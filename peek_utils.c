/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 07:42:16 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/05 12:41:11 by rkochhan         ###   ########.fr       */
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

	if (num < value(stack->top))
		return (0);
	else if (num > value(stack->bottom))
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
	if (pos > stack->len / 2)
		pos -= stack->len;
	return (pos);
}

/*
** Returns the position of the lowest number in a stack.
*/
int	peek_lowest_num_position(t_stack *stack)
{
	t_dlist	*tracker;
	int		lowest_num;
	int		lowest_pos;
	int		i;

	tracker = stack->top->next;
	lowest_num = value(stack->top);
	lowest_pos = 0;
	i = 0;
	while (tracker)
	{
		i++;
		if (lowest_num > value(tracker))
		{
			lowest_num = value(tracker);
			lowest_pos = i;
		}
		tracker = tracker->next;
	}
	if (lowest_pos > stack->len / 2)
		lowest_pos -= stack->len;
	return (lowest_pos);
}

// int	peek_lis(t_dlist *stack)
// {
// 	int		lis[3];
// 	int		*lis_array;
// 	t_dlist	*tracker;


// 	free(lis_array);
// 	return (lis)
// }
