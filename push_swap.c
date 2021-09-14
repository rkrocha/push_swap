/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:10:25 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/14 11:06:30 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_stack(t_data *frame)
{
	if (frame->a_stack.len == 1 || stack_issorted(&frame->a_stack) == true)
		return ;
	ft_putendl("sorting... but not really");
}

int	main(int argc, const char **argv)
{
	t_data	frame;

	if (argc == 1)
		return (0);
	ft_bzero(&frame, sizeof(frame));
	parse_args(&frame, argc, argv);
	sort_stack(&frame);
	stack_print(&frame.a_stack, "a"); // REMOVE
	free_stacks(&frame);
	return (0);
}
