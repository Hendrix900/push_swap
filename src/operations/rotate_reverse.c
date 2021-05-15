/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 02:00:20 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 02:11:39 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    rotate_reverse(int n_elem, int *stack)
{
	int tmp;
    int l;
    int last;

    tmp = 0;
    last = 0;
    l = 0;
    last = stack[n_elem];
    l = n_elem;
    while (l != 0)
    {
	    stack[l] = stack[l - 1];
        l--;       
    }
	stack[0] = last;    
}

void rotate_rev_a(t_control *crtl)
{
    int n_elem;
    
    n_elem = crtl->n_elem_stack_a - 1;
    rotate_reverse(n_elem ,crtl->stack_a);
    ft_putstr_fd("rra\n", 1);
}

void rotate_rev_b(t_control *crtl)
{
    int n_elem;
    
    n_elem = crtl->n_elem_stack_b - 1;
    rotate_reverse(n_elem ,crtl->stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void rotate_rev_ab(t_control *crtl)
{
    int n_elem;
    
    n_elem = crtl->n_elem_stack_a - 1;
    rotate_reverse(n_elem, crtl->stack_a);
    n_elem = crtl->n_elem_stack_b - 1;
	rotate_reverse(n_elem,crtl->stack_b);
	ft_putstr_fd("rrr\n", 1);
}
