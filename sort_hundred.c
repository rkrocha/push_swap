/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/10 08:42:26 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_next_larger_num(int smaller_num, t_stack *stack)
{
	t_dlist	*tracker;
	long	compare;
	long	diff;
	int		larger_num;

	tracker = stack->top;
	diff = 9223372036854775807; ///   long max?
	larger_num = smaller_num;   ///// test this
	while (tracker)
	{
		compare = value(tracker) - smaller_num;
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

static int	def_chunk_nums(t_data *frame)
{
	static int	smallest;
	int			count;

	count = 0;
	if (frame->chunk_current == 0)
	{
		smallest = peek_smallest_num(&A_STACK, true);
		frame->chunk_nums[count] = smallest;
		count++;
	}
	while (count < 20) ///    check chunk size?
	{
		smallest = get_next_larger_num(smallest, &A_STACK);
		frame->chunk_nums[count] = smallest;
		count++;
		if (smallest == frame->largest_num)
			break ;
	}
	return (count);
}

static void	def_frame_params(t_data *frame)
{
	frame->chunk_max = A_STACK.len / 20 + 1;
	if (A_STACK.len % 20 == 0)
		frame->chunk_max--;
	frame->largest_num = peek_largest_num(&A_STACK, true);
}





static bool	in_chunk(int num, t_data *frame)
{
	int	i;

	i = 0;
	while (i < frame->chunk_size)
	{
		if (num == frame->chunk_nums[i])
			return (true);
		i++;
	}
	return (false);
}

static void	peek_sources(t_data *frame)
{
	t_dlist	*tracker;
	int		i;

	i = 0;
	tracker = A_STACK.top;
	while (tracker)
	{
		if (in_chunk(value(tracker), frame))
			break ;
		tracker = tracker->next;
		i++;
	}
	frame->source_one[0] = value(tracker);
	frame->source_one[1] = i;
	i = -1;
	tracker = A_STACK.bottom;
	while (tracker)
	{
		if (in_chunk(value(tracker), frame))
			break ;
		tracker = tracker->prev;
		i--;
	}
	frame->source_two[0] = value(tracker);
	frame->source_two[1] = i;
}

static void	peek_destination(int source_num, int *destin, t_data *frame)
{
	t_dlist	*tracker;
	long	compare;
	long	diff;
	int		closest_num;

	ft_bzero(destin, sizeof(destin));
	tracker = B_STACK.top;
	diff = 9223372036854775807; ///   long max?
	closest_num = source_num;
	while (tracker)
	{
		compare = ft_abs(value(tracker) - source_num);
		if (compare < diff)
		{
			closest_num = value(tracker);
			diff = compare;
			destin[0] = destin[1];
		}
		if (diff == 1)
			break ;
		destin[1]++;
		tracker = tracker->next;
	}
	destin[0] += (source_num < closest_num);
	destin[1] = B_STACK.len - destin[0];
}

void	sort_hundred(t_data *frame)
{
	int	i;

	def_frame_params(frame);
	frame->chunk_current = 0;
	while (frame->chunk_current < frame->chunk_max)
	{
		i = 0;
		ft_bzero(frame->chunk_nums, sizeof(frame->chunk_nums));
		frame->chunk_size = def_chunk_nums(frame);
		while (i < frame->chunk_size)
		{
			peek_sources(frame);
			peek_destination(frame->source_one[0], frame->destin_one, frame);
			peek_destination(frame->source_two[0], frame->destin_two, frame);
			i++;
		}
		frame->chunk_current++;
	}
}
