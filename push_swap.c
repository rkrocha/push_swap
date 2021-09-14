/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:10:25 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/14 10:19:50 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_data	frame;

	ft_bzero(&frame, sizeof(frame));
	if (argc == 1)
		error_exit(&frame);
	parse_args(&frame, argc, argv);
	// sort_stack(&frame);
	stack_print(&(frame.a_stack), "a");
	free_stacks(&frame);
	return (0);
}
