/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:50:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/11 05:30:32 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate_image(t_fdf *fdf)
{
	
	fdf->mlx->returned_img = (int *)mlx_get_data_addr(fdf->mlx->img, &BPP, &SL, &ENDIAN);
	int x = 20;
	int y = 20;
	while (++x < 100)
	{
		while (++y < 100)
			fdf->mlx->returned_img[x + (y * SL / 4)] = 0x123456;
		y = 20;
	}
}
