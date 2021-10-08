/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/08 13:39:21 by rkochhan         ###   ########.fr       */
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
	diff = 9223372036854775807;
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
	while (count < 20)
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

void	sort_hundred(t_data *frame)
{
	int	i;
	int	chunk_size;

	def_frame_params(frame);
	frame->chunk_current = 0;
	while (frame->chunk_current < frame->chunk_max)
	{
		i = 0;
		ft_bzero(frame->chunk_nums, 50 * sizeof(int));
		chunk_size = def_chunk_nums(frame);
		while (i < chunk_size)
		{
			ft_putnbr(frame->chunk_nums[i]);
			ft_putchar(' ');
			i++;
		}
		frame->chunk_current++;
		ft_putchar('\n');
	}
}
