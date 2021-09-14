/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:38:42 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/14 10:59:49 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "push_swap.h"

static bool	num_isrepeat(t_stack *stack, long long num)
{
	t_dlist	*tracker;

	tracker = stack->top;
	while (tracker)
	{
		if (num == tracker->content)
			return (true);
		tracker = tracker->next;
	}
	return (false);
}

static bool	num_isvalid(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

static bool	str_isvalid(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str && !ft_strignore(str, "0123456789"))
		return (true);
	return (false);
}

void	parse_args(t_data *frame, int argc, const char **argv)
{
	long long	num;

	argc--;
	while (argc > 0)
	{
		num = ft_atoll(argv[argc]);
		if (str_isvalid(argv[argc]) == false
			|| num_isvalid(num) == false
			|| num_isrepeat(&frame->a_stack, num) == true)
			error_exit(frame);
		stack_push(&frame->a_stack, dlst_new(num));
		argc--;
	}
}
