/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:59:23 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/14 22:23:13 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_error_exit(char *s, t_control *ctrl)
{
	perror(s);
	free(ctrl->stack_organized);
	free(ctrl->stack_original);
	exit(-1);
}
