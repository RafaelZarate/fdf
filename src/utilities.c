/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:59:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 22:21:50 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*initialize_fdf(t_queue	*input)
{
	t_fdf	*new_fdf;
	
	if (!(new_fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		exit_error();
	return(new_fdf);
}

void	validate_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && s[i] != ' ')
			error_exit();
}

void	exit_error(void)
{
	write(1,ERROR_MESSAGE, 18);
	exit(EXIT_FAILURE);
}
