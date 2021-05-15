/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:14:40 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 01:14:47 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	prnt_error_exit(char *s, t_control *ctrl)
{
	perror(s);
	free(ctrl->stack_sorted);
	free(ctrl->stack_a);
	free(ctrl->stack_b);
	exit(-1);
}
