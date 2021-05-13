/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:35:48 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/14 00:05:12 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_error(char *s, int *argv_numbers)
{
	perror(s);
    free(argv_numbers);
	exit(-1);
}

int     check_digit_argv(char argv[])
{
    int l;

    l = 0;
    while(argv[l])
    {
        if (argv[l] >= 48 && argv[l] <= 57)
            l++;
        else if (argv[l] == '-' && argv[l+1] >= 48 && argv[l + 1] <= 57)
            l++;
        else
            return(-1);
    }    
}

int     main(int argc, char *argv[])
{
    int l;
    int n;
    int error;
    int *argv_numbers = malloc(sizeof(int) * argc - 1);
    
    l = 1;
    n = 0;
    if (argc < 2)
        print_error("ERROR", argv_numbers);
    while (l != argc)
    {
        error = check_digit_argv(argv[l]);
        if (error == -1)
            print_error("ERROR", argv_numbers);
        argv_numbers[n] = ft_atoi(argv[l]);
        l++;
        n++; 
    }
    n = 0;
    printf("Stack A:\n");
    while (n != argc - 1)
    {
        printf("%d\n", argv_numbers[n]);
        n++; 
    }
    free(argv_numbers);
    return (0);
}