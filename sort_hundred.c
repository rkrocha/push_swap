/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/08 17:13:49 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_next_larger_num(int smallest, t_data *frame)
{
	t_dlist	*tracker;
	long	compare;
	long	diff;
	int		num;

	tracker = A_STACK.top;
	diff = 9223372036854775807; ///   long max?
	while (tracker)
	{
		compare = value(tracker) - smallest;
		if (compare > 0 && compare < diff)
		{
			num = value(tracker);
			diff = compare;
		}
		if (diff == 1)
			break ;
		tracker = tracker->next;
	}
	return (num);
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
		smallest = get_next_larger_num(smallest, frame);
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

static void	peek_destinations(t_data *frame)
{
	if (B_STACK.len == 0)
		ft_bzero(frame->destin, sizeof(frame->destin));
	////////////////////////////////////////////////////////// PICK UP FROM HERE
}

void	sort_hundred(t_data *frame)
{
	int	i;

	def_frame_params(frame);
	frame->chunk_current = 0; ////     make this a local var?
	while (frame->chunk_current < frame->chunk_max)
	{
		i = 0;
		ft_bzero(frame->chunk_nums, sizeof(frame->chunk_nums));
		frame->chunk_size = def_chunk_nums(frame);
		while (i < frame->chunk_size)
		{
			peek_sources(frame);
			peek_destinations(frame);
			i++;
		}
		frame->chunk_current++;
	}
}
