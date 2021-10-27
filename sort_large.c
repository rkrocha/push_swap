/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/10 21:23:32 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	optimize_setup(int *setup, t_data *frame)
{
	int	rr_count;
	int	rb_cutoff;

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
	rb_cutoff = 999;
	if (frame->chunk_size == 20)
		rb_cutoff = 7;
	else
		rb_cutoff = 11;
	if (setup[2] > rb_cutoff)
		setup[2] = 0;
}

static void	choose_setup(int *s_one, int *s_two, t_data *frame)
{
	int	setup_one_moves;
	int	setup_two_moves;

	setup_one_moves = ft_abs(s_one[0]) + ft_abs(s_one[1]) + ft_abs(s_one[2]);
	setup_two_moves = ft_abs(s_two[0]) + ft_abs(s_two[1]) + ft_abs(s_two[2]);
	frame->setup_actions[0] = s_one[0];
	frame->setup_actions[1] = s_one[1];
	frame->setup_actions[2] = s_one[2];
	if (setup_one_moves > setup_two_moves)
	{
		frame->setup_actions[0] = s_two[0];
		frame->setup_actions[1] = s_two[1];
		frame->setup_actions[2] = s_two[2];
	}
}

static void	calc_shortest_setup(t_data *frame)
{
	int	setup_one[3];
	int	setup_two[3];

	setup_one[1] = frame->source_top[1];
	if (ft_abs(frame->source_top[1] - frame->a_stack.len)
		< frame->source_top[1])
		setup_one[1] = frame->source_top[1] - frame->a_stack.len;
	setup_one[2] = frame->destin_top[0];
	if (ft_abs(frame->destin_top[1]) < frame->destin_top[0])
		setup_one[2] = frame->destin_top[1];
	optimize_setup(setup_one, frame);
	setup_two[1] = frame->source_bot[1];
	if (ft_abs(frame->source_bot[1] - frame->a_stack.len)
		< frame->source_bot[1])
		setup_two[1] = frame->source_bot[1] - frame->a_stack.len;
	setup_two[2] = frame->destin_bot[0];
	if (ft_abs(frame->destin_bot[1]) < frame->destin_bot[0])
		setup_two[2] = frame->destin_bot[1];
	optimize_setup(setup_two, frame);
	choose_setup(setup_one, setup_two, frame);
}

static void	pre_sort(t_data *frame)
{
	peek_sources(frame);
	peek_destination(frame->source_top[0], frame->destin_top, frame);
	peek_destination(frame->source_bot[0], frame->destin_bot, frame);
	calc_shortest_setup(frame);
	op_nrr(frame->setup_actions[0], frame);
	op_nra(frame->setup_actions[1], frame);
	op_nrb(frame->setup_actions[2], frame);
	op_pb(frame);
}

void	sort_large(t_data *frame)
{
	int	i;

	def_chunks_params(frame);
	frame->iter_chunks = 0;
	while (frame->iter_chunks < frame->max_chunks)
	{
		i = 0;
		ft_bzero(frame->chunk_array, sizeof(frame->chunk_array));
		frame->chunk_len = def_chunk_array(frame);
		while (i < frame->chunk_len)
		{
			pre_sort(frame);
			i++;
		}
		op_nrb(peek_largest_num(&frame->b_stack, FALSE), frame);
		frame->iter_chunks++;
	}
	while (frame->b_stack.len > 0)
	{
		op_nrb(peek_largest_num(&frame->b_stack, FALSE), frame);
		op_pa(frame);
	}
}
