/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:50:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 09:45:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf)
{
	t_line	*bres;
	int 	*img;

	bres = fdf->bres;
	img = fdf->mlx->returned_img;
	bres->dx = (uint32_t)ABS(bres->x2 - bres->x1);
	bres->dy = (uint32_t)ABS(bres->y2 - bres->y1);
	bres->i1 = ABS(bres->x1);
	bres->i2 = ABS(bres->x2);
	bres->e = ABS((bres->dy * (1 - (bres->x1 - bres->i1))) - (bres->dx *(1 - (bres->y1 - bres->j))));
	while (bres->i1++ < bres->i2)
	{
		img[bres->x1 * 15 + (bres->y1 * SL * 15)] = 0x00ff00;
		if (bres->e >= 0)
		{
			bres->y1++;
			bres->e -= bres->dx;
		}
		bres->x1++;
		bres->e += bres->dy;
	}
}

void	set_x_and_y(t_line *bres, t_point a, t_point b, t_map *map)
{
	bres->x1 = a.x;
	bres->y1 = a.y;
	bres->x2 = b.x;
	bres->y2 = b.y;
	bres->c1 = a.z / map->depth;
	bres->c2 = b.z / map->depth;
}

void	draw_lines(t_fdf *fdf)
{
	size_t	i;

	i = -1;
	while (++i < fdf->map->points)
	{
		printf("i: %zu, x: %zu, y: %zu\n", i, fdf->map->grid[i].x, fdf->map->grid[i].y);
		if (fdf->map->grid[i].x < fdf->map->width - 1)
		{
			set_x_and_y(fdf->bres, fdf->map->grid[i], fdf->map->grid[i + 1], fdf->map);
			draw_line(fdf);
		}
		if (fdf->map->grid[i].y < fdf->map->height - 1)
		{
			set_x_and_y(fdf->bres, fdf->map->grid[i], fdf->map->grid[i + fdf->map->width], fdf->map);
			draw_line(fdf);
		}
	}
}

void	generate_image(t_fdf *fdf)
{
	fdf->mlx->ptr = mlx_init();
	fdf->mlx->win = mlx_new_window(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fdf->mlx->img = mlx_new_image(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->mlx->returned_img = (int *)mlx_get_data_addr(fdf->mlx->img, &BPP, &SL, &ENDIAN);
	draw_lines(fdf);
	// int x = -1;
	// int y = -1;
	// while (++x < 1000)
	// {
	// 	while (++y < 500)
	// 		fdf->mlx->returned_img[x + (y * SL / 4)] = 0x123456;
	// 	y = -1;
	// }
}
