/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:59:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 18:36:00 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*initialize_fdf(t_queue	*input)
{
	t_fdf	*new_fdf;
	int		i;
	
	i = -1;
	if (!(new_fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		exit_error();
	if (!(new_fdf->map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit_error();
	return(new_fdf);
}

void	exit_error(void)
{
	write(1,ERROR_MESSAGE, 18);
	exit(EXIT_FAILURE);
}
