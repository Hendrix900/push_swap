/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:58:08 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/19 05:39:00 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./push_swap.h"

int         stack_is_sorted(t_control *ctrl)
{
  	int	l;

	l = 0;
	while (l != ctrl->n_elem_stack_a)
	{
		if (ctrl->stack_a[l] != ctrl->stack_sorted[l])
		    return (1);
        else
            return (0);
    l++;
	}
    return (1);
}

int		which_is_bigger(int *stack, int n_elem_stack, t_control *ctrl)
{
	int bigger;

//	printf("ctrl->n_elem_stack_a es: %d\n", ctrl->n_elem_stack_a);
//	printf("ctrl->stack_a posicion 0[%d]\n", ctrl->stack_a[0]);
//	printf("ctrl->stack_a posicion 1[%d]\n", ctrl->stack_a[1]);
//	printf("ctrl->stack_a posicion final es[%d]\n", ctrl->stack_a[ctrl->n_elem_stack_a]);
	bigger = 0;
	if (stack[0] < stack[1])
		bigger = 0;
	else
		bigger = 1;
	if (stack[bigger] < stack[n_elem_stack])
		bigger = bigger;
	else
		bigger = 2;
	return(bigger);
}

int		which_is_smaller(int *stack, int n_elem_stack, t_control *ctrl)
{
	int bigger;

	bigger = 0;
	if (stack[0] > stack[1])
		bigger = 0;
	else
		bigger = 1;
	if (stack[bigger] > stack[n_elem_stack])
		bigger = bigger;
	else
		bigger = 2;
	return(bigger);
}	


int			first_move(t_control *ctrl)
{
	int big;

	big = 0;
	while (ctrl->n_elem_stack_a > 1)
	{
		big = which_is_bigger(ctrl->stack_a, ctrl->n_elem_stack_a, ctrl);
		if (big == 0)
		{
			push_b(ctrl);
		printf("ctrl->n_elem_stack_b es: %d\n", ctrl->n_elem_stack_b);
		printf("ctrl->stack_b posicion 0[%d]\n", ctrl->stack_b[0]);
		printf("ctrl->stack_b posicion 1[%d]\n", ctrl->stack_b[1]);
		printf("ctrl->stack_b posicion final es[%d]\n", ctrl->stack_b[ctrl->n_elem_stack_b - 1]);
		}
		else if (big == 1)
			swap_a(ctrl); //sa
		else if (big == 2)
			rotate_rev_a(ctrl); //rra

		if (ctrl->stack_b[0] < ctrl->stack_b[1])
			swap_b(ctrl);
		else if (ctrl->stack_b[ctrl->n_elem_stack_b -1]
			> ctrl->stack_b[0])
		{
			printf("ENTRÓ\n");
			rotate_rev_b(ctrl);
		}
	}
	if (ctrl->stack_a[1] < ctrl->stack_a[0])
				swap_a(ctrl); //sa
	return (0);	
}

int			third_move(t_control *ctrl)
{

		if (ctrl->stack_a[0] > ctrl->stack_a[1])
				swap_a(ctrl);
	return (0);	
}

int			second_move(t_control *ctrl)
{

	while (ctrl->n_elem_stack_b >= 1 )
	{
		if (ctrl->stack_b[0] > ctrl->stack_b[1] && ctrl->stack_b[0]
			> ctrl->stack_b[ctrl->n_elem_stack_b])
		{
				push_a(ctrl);
				third_move(ctrl);
		}
		else if (ctrl->stack_b[1] > ctrl->stack_b[0])
				swap_b(ctrl);
		else if (ctrl->stack_b[ctrl->n_elem_stack_b] 
			> ctrl->stack_b[0])
				rotate_rev_b(ctrl);
	}
//	push_a(ctrl);
	return (0);	
}

void        push_swap(t_control *ctrl)
{
//	while (stack_is_sorted)
//	{
	ctrl->n_elem_stack_a -= 1; // le resto 1 para que albergue las posiciones del array correctamente
//	ctrl->n_elem_stack_b -= 1;
		first_move(ctrl);
//	ctrl->n_elem_stack_b -= 1;
		second_move(ctrl); 
//	}
}