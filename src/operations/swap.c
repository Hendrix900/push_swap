/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:16:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 14:08:49 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *stack)
{
	int	tmp;

	tmp = 0;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	swap_a(t_control *crtl)
{
	swap(crtl->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_control *crtl)
{
	swap(crtl->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_control *crtl)
{
	swap(crtl->stack_a);
	swap(crtl->stack_b);
	ft_putstr_fd("ss\n", 1);
}
