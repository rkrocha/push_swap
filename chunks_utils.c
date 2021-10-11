/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:20 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/11 10:59:58 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

void	peek_sources(t_data *frame)
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

void	peek_destination(int source_num, int *destin, t_data *frame)
{
	t_dlist	*tracker;
	long	compare;
	long	diff;
	int		closest_num;

	ft_bzero(destin, sizeof(destin));
	tracker = B_STACK.top;
	diff = 9223372036854775807;
	closest_num = source_num;
	while (tracker)
	{
		compare = ft_abs((long)value(tracker) - source_num);
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
