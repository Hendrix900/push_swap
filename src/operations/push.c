/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:37:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 02:38:02 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(int *stack_org, int *stack_dest, int n_elem_org, int n_elem_des)
{
	int tmp;
    int l;
    int first_org;
	int first_dest;

    tmp = 0;
    first_org = 0;
	first_dest = 0;
    l = 0;
    first_org = stack_org[0];
    while (l != n_elem_org)
    {
	    stack_org[l] = stack_org[l + 1];
        l++;       
    }
	first_dest = stack_dest[0];
	l = n_elem_des;
	while (l != 0)
    {
	    stack_dest[l - 1] = stack_dest[l];
        l--;       
    }
	stack_dest[0] = first_org;
}

void push_a(t_control *crtl)
{
	int n_elem_org;
	int n_elem_des;

	n_elem_org = crtl->n_elem_stack_b - 1;
	n_elem_des = crtl->n_elem_stack_a - 1;
	push(crtl->stack_b, crtl->stack_a, n_elem_org, n_elem_des);
	crtl->n_elem_stack_b -= 1;
	ft_putstr_fd("pa\n", 1);
}

void push_b(t_control *crtl)
{
	int n_elem_org;
	int n_elem_des;

	n_elem_org = crtl->n_elem_stack_a - 1;
	n_elem_des = crtl->n_elem_stack_b - 1;
	push(crtl->stack_a, crtl->stack_b, n_elem_org, n_elem_des);
	crtl->n_elem_stack_a -= 1;
	ft_putstr_fd("pb\n", 1);
}

