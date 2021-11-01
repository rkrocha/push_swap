/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:38:42 by rkochhan          #+#    #+#             */
/*   Updated: 2021/11/01 08:50:19 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_bool	num_isunique(t_stack *stack, long long num)
{
	t_dlist	*tracker;

	tracker = stack->top;
	while (tracker)
	{
		if (num == tracker->content)
			return (FALSE);
		tracker = tracker->next;
	}
	return (TRUE);
}

static t_bool	num_isvalid(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (FALSE);
	return (TRUE);
}

static t_bool	str_isvalid(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str && !ft_strignore(str, "0123456789"))
		return (TRUE);
	return (FALSE);
}

void	parse_args(t_data *frame, int argc, const char **argv)
{
	long long	num;

	argc--;
	while (argc > 0)
	{
		num = ft_atoll(argv[argc]);
		if (str_isvalid(argv[argc]) == FALSE
			|| num_isvalid(num) == FALSE
			|| num_isunique(&frame->a_stack, num) == FALSE)
			error_exit(frame);
		stack_push(&frame->a_stack, dlst_new(num));
		argc--;
	}
}
