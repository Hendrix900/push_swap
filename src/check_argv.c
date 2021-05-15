/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:08:02 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 01:14:09 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeated_number(int *argv_base, t_control *ctrl)
{
	int	l;

	l = 0;
	while (l < ctrl->n_elem_stack_a -1 && ctrl->n_elem_stack_a > 1)
	{
		if (argv_base[l] == argv_base[l + 1])
			return (-1);
		l++;
	}
	return (0);
}

int	*buble_stack_sorted(int *argv_base, t_control *ctrl)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 1;
	j = 0;
	while (i < ctrl->n_elem_stack_a)
	{
		j = 0;
		while (j < ctrl->n_elem_stack_a - i)
		{
			if (argv_base[j] > argv_base[j + 1])
			{
				ctrl->n_movments++;
				temp = argv_base[j];
				argv_base[j] = argv_base[j + 1];
				argv_base[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (argv_base);
}

int	check_ifdigit_argv(char argv[], t_control *ctrl)
{
	int	l;

	l = 0;
	while (argv[l])
	{
		if (argv[l] >= 48 && argv[l] <= 57)
			l++;
		else if (argv[l] == '-' && argv[l + 1] >= 48 && argv[l + 1] <= 57)
			l++;
		else
			return (-1);
	}
}

int	check_argv(char **argv, t_control *ctrl)
{
	int	l;
	int	n;

	l = 1;
	n = 0;
	while (l != ctrl->n_elem_stack_a + 1)
	{
		ctrl->error = check_ifdigit_argv(argv[l], ctrl);
		if (ctrl->error == -1)
			prnt_error_exit("ERROR some parameter is not a digit", ctrl);
		ctrl->stack_a[n] = ft_atoi_range(argv[l], ctrl);
		ctrl->stack_sorted[n] = ft_atoi_range(argv[l], ctrl);
		l++;
		n++;
	}
	ctrl->stack_sorted = buble_stack_sorted(ctrl->stack_sorted, ctrl);
	ctrl->error = repeated_number(ctrl->stack_sorted, ctrl);
	if (ctrl->error == -1)
		prnt_error_exit("ERROR Number repeated", ctrl);
}
