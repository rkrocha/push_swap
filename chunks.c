/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:44:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/19 15:43:12 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	peek_next_larger_num(int smaller_num, t_stack *stack)
{
	t_dlist	*tracker;
	long	compare;
	long	diff;
	int		larger_num;

	tracker = stack->top;
	diff = 9223372036854775807;
	larger_num = smaller_num;
	while (tracker)
	{
		compare = (long)value(tracker) - smaller_num;
		if (compare > 0 && compare < diff)
		{
			larger_num = value(tracker);
			diff = compare;
		}
		if (diff == 1)
			break ;
		tracker = tracker->next;
	}
	return (larger_num);
}

int	def_chunk_array(t_data *frame)
{
	static int	smallest;
	int			count;

	count = 0;
	if (frame->iter_chunks == 0)
	{
		smallest = peek_smallest_num(&A_STACK, true);
		frame->chunk_array[count] = smallest;
		count++;
	}
	while (count < frame->chunk_size)
	{
		smallest = peek_next_larger_num(smallest, &A_STACK);
		frame->chunk_array[count] = smallest;
		count++;
		if (smallest == frame->largest_num)
			break ;
	}
	return (count);
}

void	def_chunks_params(t_data *frame)
{
	if (A_STACK.len <= 100)
		frame->chunk_size = 20;
	else
		frame->chunk_size = 45;
	frame->max_chunks = A_STACK.len / frame->chunk_size + 1;
	if (A_STACK.len % frame->chunk_size == 0)
		frame->max_chunks--;
	frame->largest_num = peek_largest_num(&A_STACK, true);
}
