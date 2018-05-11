/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:58:16 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 18:38:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_queue	*input;

	if (ac != 2)
		exit_error();
	input = parser(av[1]);
	generate_map(input);
	return (EXIT_SUCCESS);
}