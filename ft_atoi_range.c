/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:19:41 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/14 23:41:47 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_line_atoi(const char *str, int l)
{
	while (str[l] != '\0')
	{
		if (str[l] == ' ' || str[l] == '\n' || str[l] == '\t' || str[l] == '\v'
			|| str[l] == '\f' || str[l] == '\r')
			l++;
		else
			return (l);
	}
}

int	ft_atoi_range(const char *str, t_control *ctrl)
{
	long	conversion;
	int		negative;
	int		l;

	l = 0;
	conversion = 0;
	negative = 1;
	l = check_line_atoi(str, l);
	if (str[l] == '-')
		negative = -1;
	if (str[l] == '-' || str[l] == '+')
		l++;
	while (str[l] >= '0' && str[l] <= '9')
	{
		conversion = conversion * 10 + (str[l] - 48);
		l++;
	}
	if ((1 * conversion) > 2147483647 || (1 * conversion) < -2147483648)
		p_error_exit("Error INT out of range", ctrl);
	return (conversion * negative);
}
