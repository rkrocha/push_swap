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

static void	def_frame_params(t_data *frame)
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

static void	optimize_setup(int *setup, t_data *frame)
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
	// else
	// {
			///// case for setup1 * setup2 < 0
	// }
	setup[0] = rr_count;
	setup[1] -= rr_count;
	setup[2] -= rr_count;
	if (setup[2] > frame->max_chunks * 1.5) ///// 7 = magic number for 100 sort
		setup[2] = 0;
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
	optimize_setup(setup_one, frame);



	setup_two[1] = frame->source_bot[1];
	if (ft_abs(frame->source_bot[1] - A_STACK.len) < frame->source_bot[1])
		setup_two[1] = frame->source_bot[1] - A_STACK.len;
	setup_two[2] = frame->destin_bot[0];
	if (ft_abs(frame->destin_bot[1]) < frame->destin_bot[0])
		setup_two[2] = frame->destin_bot[1];
	optimize_setup(setup_two, frame);



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



		// ft_putendl("");
		// ft_putnbr(frame->setup_actions[0]);
		// ft_putchar(' ');
		// ft_putnbr(frame->setup_actions[1]);   //////////////////
		// ft_putchar(' ');
		// ft_putnbr(frame->setup_actions[2]);
		// ft_putendl("");
}

void	sort_large(t_data *frame)
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
		op_nrb(peek_largest_num(&B_STACK, false), frame);
		frame->iter_chunks++;
	}


	while (B_STACK.len > 0)
	{
		op_nrb(peek_largest_num(&B_STACK, false), frame);
		op_pa(frame);
	}
}
