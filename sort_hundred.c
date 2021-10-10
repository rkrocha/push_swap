/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/10 16:41:01 by rkochhan         ###   ########.fr       */
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

static int	def_chunk_array(t_data *frame)
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
		smallest = get_next_larger_num(smallest, &A_STACK);
		frame->chunk_array[count] = smallest;
		count++;
		if (smallest == frame->largest_num)
			break ;
	}
	return (count);
}

static void	def_frame_params(t_data *frame)
{
	if (A_STACK.len <= 100)
		frame->chunk_size = 22;
	else
		frame->chunk_size = 50;
	frame->max_chunks = A_STACK.len / frame->chunk_size + 1;
	if (A_STACK.len % frame->chunk_size == 0)
		frame->max_chunks--;
	frame->largest_num = peek_largest_num(&A_STACK, true);
}





static bool	in_chunk(int num, t_data *frame)
{
	int	i;

	i = 0;
	while (i < frame->chunk_len)
	{
		if (num == frame->chunk_array[i])
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
	frame->source_top[0] = value(tracker);
	frame->source_top[1] = i;
	i = -1;
	tracker = A_STACK.bottom;
	while (tracker)
	{
		if (in_chunk(value(tracker), frame))
			break ;
		tracker = tracker->prev;
		i--;
	}
	frame->source_bot[0] = value(tracker);
	frame->source_bot[1] = i;
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
	destin[1] = destin[0] - B_STACK.len;
}

static void	optimize_setup(int *setup)
{
	int	rr_count;

	rr_count = 0;
	if (setup[1] * setup[2] > 0 || setup[1] == setup[2])
	{
		if (ft_abs(setup[1]) <= ft_abs(setup[2]))
			rr_count = setup[1];
		else
			rr_count = setup[2];
	}
	setup[0] = rr_count;
	setup[1] -= rr_count;
	setup[2] -= rr_count;
}

static void	calc_shortest_setup(t_data *frame)
{
	int	setup_one[3];
	int	setup_two[3];

	setup_one[1] = frame->source_top[1];
	if (ft_abs(frame->source_top[1] - A_STACK.len) < frame->source_top[1])
		setup_one[1] = frame->source_top[1] - A_STACK.len;

	setup_one[2] = frame->destin_top[0];
	if (ft_abs(frame->destin_top[1]) < frame->destin_top[0])
		setup_one[2] = frame->destin_top[1];
	optimize_setup(setup_one);



	setup_two[1] = frame->source_bot[1];
	if (ft_abs(frame->source_bot[1] - A_STACK.len) < frame->source_bot[1])
		setup_two[1] = frame->source_bot[1] - A_STACK.len;
	setup_two[2] = frame->destin_bot[0];
	if (ft_abs(frame->source_bot[1]) < frame->source_bot[0])
		setup_two[2] = frame->destin_bot[1];
	optimize_setup(setup_two);



	frame->setup_actions[0] = setup_one[0];
	frame->setup_actions[1] = setup_one[1];
	frame->setup_actions[2] = setup_one[2];
	if (ft_abs(setup_one[0]) + ft_abs(setup_one[1]) + ft_abs(setup_one[2])
		> (ft_abs(setup_two[0]) + ft_abs(setup_two[1]) + ft_abs(setup_two[2])))
	{
		frame->setup_actions[0] = setup_two[0];
		frame->setup_actions[1] = setup_two[1];
		frame->setup_actions[2] = setup_two[2];
	}

}

void	sort_hundred(t_data *frame)
{
	int	i;

	def_frame_params(frame);
	frame->iter_chunks = 0;
	while (frame->iter_chunks < frame->max_chunks)
	{
		i = 0;
		ft_bzero(frame->chunk_array, sizeof(frame->chunk_array));
		frame->chunk_len = def_chunk_array(frame);
		while (i < frame->chunk_len)
		{
			peek_sources(frame);
			peek_destination(frame->source_top[0], frame->destin_top, frame);
			peek_destination(frame->source_bot[0], frame->destin_bot, frame);
			calc_shortest_setup(frame);
			op_nrr(frame->setup_actions[0], frame);
			op_nra(frame->setup_actions[1], frame);
			op_nrb(frame->setup_actions[2], frame);
			op_pb(frame);
			i++;
		}
		frame->iter_chunks++;
	}
	op_nrb(peek_largest_num(&B_STACK, false), frame);
	op_n(op_pa, B_STACK.len, frame);
}
